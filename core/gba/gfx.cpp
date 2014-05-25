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
#ifdef USE_GBA

#include "../core.hpp"

namespace wombat {
namespace core {

using std::string;


int displayWidth() {
	return 0;
}

int displayHeight() {
	return 0;
}

//Image

Image::Image(models::Image img) {
}

Image::~Image() {
}

int Image::width() {
	return 0;
}

int Image::height() {
	return 0;
}

bool Image::loaded() {
	return m_img;
}


//Graphics

void Graphics::draw(Image *img, int x, int y, int w, int h) {
	if (img->loaded()) {
	}
}

void Graphics::draw(Image *img, int x, int y) {
	if (img->loaded()) {
	}
}

void Graphics::setRGBA(int r, int g, int b, int a) {
}

void Graphics::setRGB(int r, int g, int b) {
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

	//SDL_Rect sdlRct;
	//sdlRct.x = r.X;
	//sdlRct.y = r.Y;
	//sdlRct.w = r.Width;
	//sdlRct.h = r.Height;

	//SDL_RenderSetClipRect(_renderer, &sdlRct);

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

		//SDL_Rect sdlRct;
		//sdlRct.x = r.X;
		//sdlRct.y = r.Y;
		//sdlRct.w = r.Width;
		//sdlRct.h = r.Height;
		//SDL_RenderSetClipRect(_renderer, &sdlRct);

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
#endif
