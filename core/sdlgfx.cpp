/*
 * Copyright 2013 gtalent2@gmail.com
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

//Image

Image::Image(string path) {
	SDL_Surface *s = IMG_Load(path.c_str());
	m_img = SDL_CreateTextureFromSurface(renderer, s);
	SDL_FreeSurface(s);
	m_defaultSize.width = -1;
	m_defaultSize.height = -1;
}

Image::Image(models::Image &img) {
	printf("Loading image: %s\n", img.toJson().c_str());
	SDL_Surface *s = IMG_Load(img.path.c_str());
	m_img = SDL_CreateTextureFromSurface(renderer, s);
	SDL_FreeSurface(s);
	m_defaultSize.width = img.defaultSize.width;
	m_defaultSize.height = img.defaultSize.height;
}

Image::~Image() {
	SDL_DestroyTexture(m_img);
}

int Image::width() {
	int out;
	SDL_QueryTexture(m_img, 0, 0, 0, &out);
	return out;
}

int Image::height() {
	int out;
	SDL_QueryTexture(m_img, 0, 0, &out, 0);
	return out;
}

bool Image::loaded() {
	return m_img;
}


//Animation

Animation::Animation(models::Animation &anim) {
}


//Graphics

void Graphics::draw(Image *img, int x, int y, int w, int h) {
	if (img->loaded()) {
		if (w == -1) {
			if (img->defaultWidth() == -1)
				w = img->width();
			else
				w = img->defaultWidth();
		}
		if (h == -1) {
			if (img->defaultHeight() == -1)
				h = img->height();
			else
				h = img->defaultHeight();
		}
		//printf("Draw1: %d, %d, %d, %d\n", x, y, w, h);
		//printf("Draw2: %d, %d, %d, %d\n", img->m_bounds.x, img->m_bounds.y, img->width(), img->height());
		SDL_SetTextureAlphaMod(img->m_img, 255);
		SDL_Rect dest;
		dest.x = x;
		dest.y = y;
		SDL_RenderCopy(renderer, img->m_img, 0, &dest);
	}
}

}
}
#endif
