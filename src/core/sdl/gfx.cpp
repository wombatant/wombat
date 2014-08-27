/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <common/flyweight.hpp>

#include "../core.hpp"

namespace wombat {
namespace core {

using std::string;

extern SDL_Window *_display;
extern SDL_GLContext _glContext;

common::Flyweight<string, GLuint> _glSrcImageCache(
	[](string key) {
		cout << key << endl;
		SDL_Surface *s = IMG_Load(key.c_str());

		GLuint glTxtr;

		glGenTextures(1, &glTxtr);
		glBindTexture(GL_TEXTURE_2D, glTxtr);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		if (s) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, s->w, s->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, s->pixels);
		}

		SDL_FreeSurface(s);

		return glTxtr;
	}
);

struct GlDisplayListKey {
	common::Bounds srcBnds;
	models::Size destSize;
	std::string spriteSheet;

	GlDisplayListKey(common::Bounds bnds, models::Size size, std::string ss) {
		srcBnds = bnds;
		destSize = size;
		spriteSheet = ss;
	}

	bool operator<(const GlDisplayListKey &r) const {
		return srcBnds.Width < r.srcBnds.Width && destSize.Width < r.destSize.Width &&
		       srcBnds.Height < r.srcBnds.Height && destSize.Height < r.destSize.Height &&
		       spriteSheet < r.spriteSheet;
	}
};

common::Flyweight<GlDisplayListKey, GLuint> _glDisplayLists(
	[](GlDisplayListKey key) {
		GLuint dl = glGenLists(1);
		auto imgId = _glSrcImageCache.checkout(key.spriteSheet);

		glNewList(dl, GL_COMPILE);
		{
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0);

			glEnable(GL_TEXTURE_2D);
			glTexEnvf(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_REPLACE);
			glColor3d(1, 1, 1);
			glBindTexture(GL_TEXTURE_2D, imgId);

			auto x1 = 0;
			auto y1 = 0;
			auto x2 = x1 + key.destSize.Width;
			auto y2 = y1 + key.destSize.Height;
			glBegin(GL_QUADS);
			{
				//Bottom Left
				glTexCoord2d(0, 0);
				glVertex3i(x1, y1, 0);
				//Bottom Right
				glTexCoord2d(1.0 / key.srcBnds.Width, 0);
				glVertex3i(x2, y1, 0);
				//Top Right
				glTexCoord2d(1.0 / key.srcBnds.Width, 1.0 / key.srcBnds.Height);
				glVertex3i(x2, y2, 0);
				//Top Left
				glTexCoord2d(0, 1.0 / key.srcBnds.Height);
				glVertex3i(x1, y2, 0);
			}
			glEnd();
		}
		glEndList();

		return dl;
	},
	[](GLuint val) {
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

	m_bounds = ss.Images[img.ImgId].SrcBounds;
	m_defaultSize.Width = img.DefaultSize.Width;
	m_defaultSize.Height = img.DefaultSize.Height;
	m_key = img.toJson();

	m_img = _glDisplayLists.checkout(GlDisplayListKey(m_bounds, m_defaultSize, path(ss.SrcFile)));
}

Image::~Image() {
	//SDL_DestroyTexture((SDL_Texture*) m_img);
}

int Image::width() {
	int out = 0;
	//SDL_QueryTexture((SDL_Texture*) m_img, nullptr, nullptr, &out, nullptr);
	return out;
}

int Image::height() {
	int out = 0;
	//SDL_QueryTexture((SDL_Texture*) m_img, nullptr, nullptr, nullptr, &out);
	return out;
}

bool Image::loaded() {
	return m_img;
}


//Graphics

void Graphics::drawLine(int x1, int y1, int x2, int y2) {
	//SDL_RenderDrawLine(_renderer, x1, y1, x2, y2);
}

void Graphics::draw(Image *img, int x, int y) {
	//if (img->loaded()) {
	//	int w, h;
	//	if (img->defaultWidth() == -1) {
	//		w = img->width();
	//	} else {
	//		w = img->defaultWidth();
	//	}

	//	if (img->defaultHeight() == -1) {
	//		h = img->height();
	//	} else {
	//		h = img->defaultHeight();
	//	}

	//	//SDL_SetTextureAlphaMod((SDL_Texture*) img->m_img, 255);
	//	SDL_Rect dest, src;
	//	dest.x = m_origin.X + x;
	//	dest.y = m_origin.Y + y;
	//	dest.w = w;
	//	dest.h = h;

	//	src.x = img->m_bounds.X;
	//	src.y = img->m_bounds.Y;
	//	src.w = img->m_bounds.Width;
	//	src.h = img->m_bounds.Height;

	//	//SDL_RenderCopy(_renderer, (SDL_Texture*) img->m_img, &src, &dest);
	//}

	//glColor3b(0, 0, 64);
	//cout << x << ", " << y << endl;
	//glRecti(x, y, x + 32, y + 32);

	//glPushMatrix();


	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//glEnable(GL_ALPHA_TEST);
	//glAlphaFunc(GL_GREATER, 0);

	//glEnable(GL_TEXTURE_2D);
	//glTexEnvf(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	//glColor3d(1, 1, 1);
	//if (currentImg != img->m_img) {
	//	glBindTexture(GL_TEXTURE_2D, img->m_img);
	//	currentImg = img->m_img;
	//}

	//auto &x1 = x;
	//auto &y1 = y;
	//auto x2 = x + 32;
	//auto y2 = y + 32;
	//glBegin(GL_QUADS);
	//{
	//	//Bottom Left
	//	glTexCoord2d(0, 0);
	//	glVertex3i(x1, y1, 0);
	//	//Bottom Right
	//	glTexCoord2d(1.0 / img->m_bounds.Width, 0);
	//	glVertex3i(x2, y1, 0);
	//	//Top Right
	//	glTexCoord2d(1.0 / img->m_bounds.Width, 1.0 / img->m_bounds.Height);
	//	glVertex3i(x2, y2, 0);
	//	//Top Left
	//	glTexCoord2d(0, 1.0 / img->m_bounds.Height);
	//	glVertex3i(x1, y2, 0);
	//}
	//glEnd();

	//glDisable(GL_TEXTURE_2D);
	//glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	//glDisable(GL_ALPHA);
	//glDisable(GL_BLEND);
	glTranslated(x, y, 0);
	glCallList(img->m_img);
	glTranslated(-x, -y, 0);
}

void Graphics::setRGBA(int r, int g, int b, int a) {
	//SDL_SetRenderDrawColor(_renderer, r, g, b, a);
}

void Graphics::setRGB(int r, int g, int b) {
	//SDL_SetRenderDrawColor(_renderer, r, g, b, 255);
}

void Graphics::pushClipRect(int x, int y, int w, int h) {
	//common::Bounds bnds;
	//bnds.X = x;
	//bnds.Y = y;
	//bnds.Width = w;
	//bnds.Height = h;

	//m_origin.X -= m_cliprect.translate().X;
	//m_origin.Y -= m_cliprect.translate().Y;
	//m_cliprect.push(bnds);
	//auto r = m_cliprect.bounds();

	//SDL_Rect sdlRct;
	//sdlRct.x = r.X;
	//sdlRct.y = r.Y;
	//sdlRct.w = r.Width;
	//sdlRct.h = r.Height;

	//SDL_RenderSetClipRect(_renderer, &sdlRct);

	//m_origin.X = m_cliprect.bounds().X;
	//m_origin.Y = m_cliprect.bounds().Y;
	//m_origin.X += m_cliprect.translate().X;
	//m_origin.Y += m_cliprect.translate().Y;
}

void Graphics::popClipRect() {
	//if (m_cliprect.size()) {
	//	m_origin.X -= m_cliprect.translate().X;
	//	m_origin.Y -= m_cliprect.translate().Y;

	//	m_cliprect.pop();
	//	auto r = m_cliprect.bounds();
	//	if (r.Width == -1) {
	//		r.Width = displayWidth();
	//	}
	//	if (r.Height == -1) {
	//		r.Height = displayHeight();
	//	}

	//	SDL_Rect sdlRct;
	//	sdlRct.x = r.X;
	//	sdlRct.y = r.Y;
	//	sdlRct.w = r.Width;
	//	sdlRct.h = r.Height;
	//	SDL_RenderSetClipRect(_renderer, &sdlRct);

	//	m_origin.X = m_cliprect.bounds().X;
	//	m_origin.Y = m_cliprect.bounds().Y;
	//	m_origin.X += m_cliprect.translate().X;
	//	m_origin.Y += m_cliprect.translate().Y;
	//}
}

void Graphics::resetViewport() {
	m_cliprect.clear();
	m_origin.X = 0;
	m_origin.Y = 0;
}

}
}
