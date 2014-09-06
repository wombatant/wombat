/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include <SDL.h>
#include <SDL_image.h>

#include "../core.hpp"

namespace wombat {
namespace core {

using std::string;

extern SDL_Window *_display;
extern SDL_Renderer *_renderer;

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

//Image

Image::Image(models::Image img) {
	models::SpriteSheet ss;
	read(ss, img.SpriteSheet);
	m_spriteSheetKey = ss.SrcFile;
	m_img = _spriteSheets.checkout(m_spriteSheetKey);
	m_bounds = ss.Images[img.ImgId].SrcBounds;
	m_defaultSize.Width = img.DefaultSize.Width;
	m_defaultSize.Height = img.DefaultSize.Height;
	m_key = img.toJson();
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


//Graphics

void Graphics::drawLine(int x1, int y1, int x2, int y2) {
	SDL_RenderDrawLine(_renderer, x1, y1, x2, y2);
}

void Graphics::draw(Image *img, int x, int y, int w, int h) {
	if (img->loaded()) {
		SDL_SetTextureAlphaMod((SDL_Texture*) img->m_img, 255);
		SDL_Rect dest, src;
		dest.x = m_origin.X = x;
		dest.y = m_origin.Y = y;
		dest.w = w;
		dest.h = h;

		src.x = img->m_bounds.X;
		src.y = img->m_bounds.Y;
		src.w = img->m_bounds.Width;
		src.h = img->m_bounds.Height;

		SDL_RenderCopy(_renderer, (SDL_Texture*) img->m_img, &src, &dest);
	}
}

void Graphics::draw(Image *img, int x, int y) {
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
		dest.x = m_origin.X + x;
		dest.y = m_origin.Y + y;
		dest.w = w;
		dest.h = h;

		src.x = img->m_bounds.X;
		src.y = img->m_bounds.Y;
		src.w = img->m_bounds.Width;
		src.h = img->m_bounds.Height;

		SDL_RenderCopy(_renderer, (SDL_Texture*) img->m_img, &src, &dest);
	}
}

void Graphics::setRGBA(int r, int g, int b, int a) {
	SDL_SetRenderDrawColor(_renderer, r, g, b, a);
}

void Graphics::setRGB(int r, int g, int b) {
	SDL_SetRenderDrawColor(_renderer, r, g, b, 255);
}

void Graphics::pushClipRect(int x, int y, int w, int h) {
	common::Bounds bnds;
	bnds.X = x;
	bnds.Y = y;
	bnds.Width = w;
	bnds.Height = h;

	m_origin.X -= m_cliprect.translate().X;
	m_origin.Y -= m_cliprect.translate().Y;
	m_cliprect.push(bnds);
	auto r = m_cliprect.bounds();

	SDL_Rect sdlRct;
	sdlRct.x = r.X;
	sdlRct.y = r.Y;
	sdlRct.w = r.Width;
	sdlRct.h = r.Height;

	SDL_RenderSetClipRect(_renderer, &sdlRct);

	m_origin.X = m_cliprect.bounds().X;
	m_origin.Y = m_cliprect.bounds().Y;
	m_origin.X += m_cliprect.translate().X;
	m_origin.Y += m_cliprect.translate().Y;
}

void Graphics::popClipRect() {
	if (m_cliprect.size()) {
		m_origin.X -= m_cliprect.translate().X;
		m_origin.Y -= m_cliprect.translate().Y;

		m_cliprect.pop();
		auto r = m_cliprect.bounds();
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

		m_origin.X = m_cliprect.bounds().X;
		m_origin.Y = m_cliprect.bounds().Y;
		m_origin.X += m_cliprect.translate().X;
		m_origin.Y += m_cliprect.translate().Y;
	}
}

void Graphics::resetViewport() {
	m_cliprect.clear();
	m_origin.X = 0;
	m_origin.Y = 0;
}

}
}
