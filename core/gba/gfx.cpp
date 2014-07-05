/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
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
	//auto r = m_cliprect.bounds();

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
