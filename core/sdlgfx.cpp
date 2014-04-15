/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifdef WITH_SDL
#include "core.hpp"
#include "sdlglobs.hpp"
#include "flyweight.hpp"

namespace wombat {
namespace core {

using std::string;

int displayWidth() {
	int w;
	SDL_GetWindowSize(display, &w, 0);
	return w;
}

int displayHeight() {
	int h;
	SDL_GetWindowSize(display, 0, &h);
	return h;
}

//Image

Image::Image(models::Image img) {
	models::SpriteSheet ss;
	open(ss, img.SpriteSheet);
	SDL_Surface *s = IMG_Load(path(ss.SrcFile).c_str());
	m_img = SDL_CreateTextureFromSurface(renderer, s);
	SDL_FreeSurface(s);
	m_bounds = ss.Images[img.ImgId].SrcBounds;
	m_defaultSize.Width = img.DefaultSize.Width;
	m_defaultSize.Height = img.DefaultSize.Height;
	m_key = img.toJson();
}

Image::~Image() {
	SDL_DestroyTexture(m_img);
}

int Image::width() {
	int out;
	SDL_QueryTexture(m_img, 0, 0, &out, 0);
	return out;
}

int Image::height() {
	int out;
	SDL_QueryTexture(m_img, 0, 0, 0, &out);
	return out;
}

bool Image::loaded() {
	return m_img;
}


//Graphics

void Graphics::draw(Image *img, int x, int y, int w, int h) {
	if (img->loaded()) {
		SDL_SetTextureAlphaMod(img->m_img, 255);
		SDL_Rect dest;
		dest.x = x;
		dest.y = y;
		dest.w = w;
		dest.h = h;
		SDL_RenderCopy(renderer, img->m_img, 0, &dest);
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

		SDL_SetTextureAlphaMod(img->m_img, 255);
		SDL_Rect dest, src;
		dest.x = x;
		dest.y = y;
		dest.w = w;
		dest.h = h;

		src.x = img->m_bounds.X;
		src.y = img->m_bounds.Y;
		src.w = img->m_bounds.Width;
		src.h = img->m_bounds.Height;

		SDL_RenderCopy(renderer, img->m_img, &src, &dest);
	}
}

void Graphics::fillRect(int x, int y, int w, int h) {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	SDL_RenderFillRect(renderer, &rect);
}

void Graphics::setRGBA(int r, int g, int b, int a) {
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void Graphics::setRGB(int r, int g, int b) {
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
}

}
}
#endif
