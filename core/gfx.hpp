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

#include "models/enginemodels.hpp"

#include "_viewportmgr.hpp"
#include "modelio.hpp"
#include "core.hpp"

namespace wombat {
namespace core {

using std::string;

int displayWidth();

int displayHeight();


class Image: public Flyweight<models::Image>::Value {
	friend class Graphics;
	public:
		void *m_img;

	private:
		models::Size m_defaultSize;
		string m_key;

	protected:
		/**
		 * The bounds to cut out of the source image.
		 */
		models::Bounds m_bounds;

	public:
		/**
		 * Constructor
		 * @param model Model to build the Image from
		 */
		Image(models::Image);

		/**
		 * Destructor
		 */
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

class Animation: public Flyweight<models::Animation>::Value {
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
	friend void _draw();
	private:
		models::Point m_origin;
		//models::Point m_translation;

	protected:
		ViewportManager m_viewport;

	public:
		void draw(Image *img, int x, int y, int w, int h);

		void draw(Image *img, int x, int y);

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

		/**
		 * Pushs the given view port the viewports stack.
		 * This will get cleared out at the end of this draw iteration regardless
		 * of whether or not it is manually popped.
		 * @param bnds the bounds of the desired viewport 
		 */
		void pushClipRect(models::Bounds bnds);

		/**
		 * Pushs the given view port the viewports stack.
		 * This will get cleared out at the end of this draw iteration regardless
		 * of whether or not it is manually popped.
		 * @param x the left border of the clip rect
		 * @param y the right border of the clip rect
		 * @param w the width of the clip rect
		 * @param h the height of the clip rect
		 */
		void pushClipRect(int x, int y, int w, int h);

	protected:
		void resetViewport();
};

class Drawer {
	public:
		virtual ~Drawer() {};
		virtual void draw(Graphics*) = 0;
};

void addDrawer(Drawer*);

Animation *checkoutAnimation(models::Animation & anim);

Image *checkoutImage(models::Image &img);

void checkinImage(string path);

void checkinImage(string path);

void checkinImage(Image &img);

}
}

#endif
