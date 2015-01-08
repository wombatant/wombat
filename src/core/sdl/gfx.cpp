/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <models/models.hpp>
#include "../_cliprectstack.hpp"
#include "../gfx.hpp"
#include "../modelio.hpp"

namespace wombat {
namespace core {

using std::string;

extern SDL_Window *_display;
extern SDL_Renderer *_renderer;
common::Point _drawOrigin;
ClipRectStack _clipRect;

common::Flyweight<std::string, SDL_Texture*> _spriteSheets(
	[](std::string key) {
		SDL_Surface *s = IMG_Load(path(key).c_str());
		auto out = SDL_CreateTextureFromSurface(_renderer, s);
		SDL_FreeSurface(s);
		return out;
	},
	[](SDL_Texture *value) {
		SDL_DestroyTexture((SDL_Texture*) value);
	}
);

int displayWidth() {
	int w;
	SDL_GetWindowSize(_display, &w, nullptr);
	return w;
}

int displayHeight() {
	int h;
	SDL_GetWindowSize(_display, nullptr, &h);
	return h;
}

// Font

Font::Font(models::Font font) {
	auto path = core::path(font.TtfPath);
	m_data = TTF_OpenFont(path.c_str(), font.Size);
}

Font::~Font() {
	if (good()) {
		TTF_CloseFont((TTF_Font*) m_data);
	}
}

bool Font::good() {
	return m_data;
}

Text *Font::buildText(std::string txt, Color color) {
	SDL_Color scolor;
	scolor.r = color.r;
	scolor.g = color.g;
	scolor.b = color.b;
	scolor.a = color.a;

	auto surface = TTF_RenderText_Blended((TTF_Font*) m_data, txt.c_str(), scolor);
	if (surface == nullptr){
		return nullptr;
	}
	auto texture = SDL_CreateTextureFromSurface(_renderer, surface);
	SDL_FreeSurface(surface);
	if (texture == nullptr){
		return nullptr;
	}

	return new Text(texture);
}


// Text

Text::Text(void *texture) {
	m_data = texture;
}

Text::~Text() {
	SDL_DestroyTexture((SDL_Texture*) m_data);
}


// Image

Image::Image(models::Image img) {
	models::SpriteSheet ss;
	read(ss, img.SpriteSheet);
	m_spriteSheetKey = ss.SrcFile;
	m_img = _spriteSheets.checkout(m_spriteSheetKey);
	m_bounds = ss.Images[img.ImgId].SrcBounds;
	m_defaultSize.Width = img.DefaultSize.Width;
	m_defaultSize.Height = img.DefaultSize.Height;
	m_key = toJson(img);
}

Image::~Image() {
	_spriteSheets.checkin(m_spriteSheetKey);
}

int Image::width() {
	int out;
	SDL_QueryTexture((SDL_Texture*) m_img, nullptr, nullptr, &out, nullptr);
	return out;
}

int Image::height() {
	int out;
	SDL_QueryTexture((SDL_Texture*) m_img, nullptr, nullptr, nullptr, &out);
	return out;
}

bool Image::loaded() {
	return m_img;
}


// Graphics

void drawLine(int x1, int y1, int x2, int y2) {
	SDL_RenderDrawLine(_renderer, x1, y1, x2, y2);
}

void draw(Image *img, int x, int y, int w, int h) {
	if (img->loaded()) {
		SDL_SetTextureAlphaMod((SDL_Texture*) img->m_img, 255);
		SDL_Rect dest, src;
		dest.x = _drawOrigin.X = x;
		dest.y = _drawOrigin.Y = y;
		dest.w = w;
		dest.h = h;

		src.x = img->m_bounds.X;
		src.y = img->m_bounds.Y;
		src.w = img->m_bounds.Width;
		src.h = img->m_bounds.Height;

		SDL_RenderCopy(_renderer, (SDL_Texture*) img->m_img, &src, &dest);
	}
}

void draw(Image *img, int x, int y) {
	if (img->loaded()) {
		int w, h;
		if (img->defaultWidth() == -1)
			w = img->width();
		else
			w = img->defaultWidth();

		if (img->defaultHeight() == -1)
			h = img->height();
		else
			h = img->defaultHeight();

		SDL_SetTextureAlphaMod((SDL_Texture*) img->m_img, 255);
		SDL_Rect dest, src;
		dest.x = _drawOrigin.X + x;
		dest.y = _drawOrigin.Y + y;
		dest.w = w;
		dest.h = h;

		src.x = img->m_bounds.X;
		src.y = img->m_bounds.Y;
		src.w = img->m_bounds.Width;
		src.h = img->m_bounds.Height;

		SDL_RenderCopy(_renderer, (SDL_Texture*) img->m_img, &src, &dest);
	}
}

void draw(Text *txt, int x, int y) {
	auto texture = (SDL_Texture*) txt->m_data;
	if (texture) {
		SDL_Rect dest, src;
		dest.x = _drawOrigin.X + x;
		dest.y = _drawOrigin.Y + y;
		SDL_QueryTexture(texture, nullptr, nullptr, &dest.w, &dest.h);

		src.x = 0;
		src.y = 0;
		src.w = dest.w;
		src.h = dest.h;
		SDL_RenderCopy(_renderer, texture, &src, &dest);
	}
}

void draw(Text *txt, common::Point pt) {
	draw(txt, pt.X, pt.Y);
}

void drawRect(int x, int y, int w, int h) {
	SDL_Rect r;
	r.x = x + _drawOrigin.X;
	r.y = y + _drawOrigin.Y;
	r.w = w;
	r.h = h;
	SDL_RenderDrawRect(_renderer, &r);
}

void fillRect(int x, int y, int w, int h) {
	SDL_Rect r;
	r.x = x + _drawOrigin.X;
	r.y = y + _drawOrigin.Y;
	r.w = w;
	r.h = h;
	SDL_RenderFillRect(_renderer, &r);
}

void setRGBA(int r, int g, int b, int a) {
	SDL_SetRenderDrawColor(_renderer, r, g, b, a);
}

void setRGB(int r, int g, int b) {
	SDL_SetRenderDrawColor(_renderer, r, g, b, 255);
}

void pushClipRect(int x, int y, int w, int h) {
	common::Bounds bnds;
	bnds.X = x;
	bnds.Y = y;
	bnds.Width = w;
	bnds.Height = h;

	_drawOrigin.X -= _clipRect.translate().X;
	_drawOrigin.Y -= _clipRect.translate().Y;
	_clipRect.push(bnds);
	auto r = _clipRect.bounds();

	SDL_Rect sdlRct;
	sdlRct.x = r.X;
	sdlRct.y = r.Y;
	sdlRct.w = r.Width;
	sdlRct.h = r.Height;

	SDL_RenderSetClipRect(_renderer, &sdlRct);

	_drawOrigin.X = _clipRect.bounds().X;
	_drawOrigin.Y = _clipRect.bounds().Y;
	_drawOrigin.X += _clipRect.translate().X;
	_drawOrigin.Y += _clipRect.translate().Y;
}

void popClipRect() {
	if (_clipRect.size()) {
		_drawOrigin.X -= _clipRect.translate().X;
		_drawOrigin.Y -= _clipRect.translate().Y;

		_clipRect.pop();
		auto r = _clipRect.bounds();
		if (r.Width == -1) {
			r.Width = displayWidth();
		}
		if (r.Height == -1) {
			r.Height = displayHeight();
		}

		SDL_Rect sdlRct;
		sdlRct.x = r.X;
		sdlRct.y = r.Y;
		sdlRct.w = r.Width;
		sdlRct.h = r.Height;
		SDL_RenderSetClipRect(_renderer, &sdlRct);

		_drawOrigin.X = _clipRect.bounds().X;
		_drawOrigin.Y = _clipRect.bounds().Y;
		_drawOrigin.X += _clipRect.translate().X;
		_drawOrigin.Y += _clipRect.translate().Y;
	}
}

void resetViewport() {
	_clipRect.clear();
	_drawOrigin.X = 0;
	_drawOrigin.Y = 0;
}

}
}
