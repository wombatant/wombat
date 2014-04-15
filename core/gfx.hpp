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
#ifndef WOMBAT_CORE_GFX_HPP
#define WOMBAT_CORE_GFX_HPP

#include <string>

#ifdef WITH_ALLEGRO
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#elif WITH_SDL
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#endif

#include "models/enginemodels.hpp"

#include "types.hpp"
#include "common/flyweight.hpp"

namespace wombat {
namespace core {

using std::string;
using common::FlyweightNode;

int displayWidth();

int displayHeight();


class Image: public FlyweightNode {
	friend class Graphics;
	public:
#ifdef WITH_ALLEGRO
		ALLEGRO_BITMAP *m_alImg;
#elif WITH_SDL
		SDL_Texture *m_img;
#endif
	private:
		models::Size m_defaultSize;
		string m_key;
	protected:
		/**
		 * The bounds to cut out of the source image.
		 */
		models::Bounds m_bounds;
	public:
		Image(models::Image);

		virtual ~Image();

		/**
		 * Returns the width of the source image.
		 */
		int width();

		/**
		 * Returns the height of the source image.
		 */
		int height();

		/**
		 * Returns the default draw width.
		 */
		int defaultWidth();

		/**
		 * Returns the default draw width.
		 */
		int defaultHeight();

		bool loaded();

		string key();
};

class Animation: public FlyweightNode {
	private:
		std::vector<Image*> m_imgs;
		time_t m_lastUpdate;
		time_t m_interval;
		int m_slide;
		std::string m_key;

	public:
		Animation(models::Animation);

		~Animation();

		void add(Image*);

		Image *getImage();

		bool loaded();

		string key();
};

class Graphics {
	public:
		void draw(Image *img, int x, int y, int w, int h);

		void draw(Image *img, int x, int y);

		void fillRect(int x, int y, int w, int h);

		/**
		 * Sets the color for primitives to draw with.
		 * @param r red value (0-255)
		 * @param g green value (0-255)
		 * @param b blue value (0-255)
		 * @param a alpha value (0-255)
		 */
		void setRGBA(int r, int g, int b, int a);

		/**
		 * Sets the color for primitives to draw with.
		 * @param r red value (0-255)
		 * @param g green value (0-255)
		 * @param b blue value (0-255)
		 */
		void setRGB(int r, int g, int b);
};

class Drawer {
	public:
		virtual ~Drawer() {};
		virtual void draw(Graphics*) = 0;
};


Animation *checkoutAnimation(models::Animation & anim);

Image *checkoutImage(models::Image &img);

void checkinImage(string path);

void checkinImage(string path);

void checkinImage(Image &img);

}
}

#endif
