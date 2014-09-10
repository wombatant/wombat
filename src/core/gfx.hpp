/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_CORE_GFX_HPP
#define WOMBAT_CORE_GFX_HPP

#include <string>

#include "_cliprectstack.hpp"
#include "modelio.hpp"
#include "core.hpp"

namespace wombat {
namespace core {

int displayWidth();

int displayHeight();


struct Color {
	uint8 r, g, b, a;

	Color(uint8 r, uint8 g, uint8 b, uint8 a = 255);
};

class Font {
	protected:
		void *m_data = nullptr;

	public:
		Font(models::Font);

		~Font();

		class Text *buildText(std::string txt, Color color);

		/**
		 * @return true if the Font loaded correctly
		 */
		bool good();
	
	private:
		Font(Font&);
		Font &operator=(Font&);
};

class Text {
	friend class Font;
	friend void draw(Text *txt, int x, int y);
	friend void draw(Text *txt, common::Point pt);

	protected:
		void *m_data = nullptr;

	protected:
		Text(void *texture);

	public:
		~Text();
	
	private:
		Text(Text&);
		Text &operator=(Text&);
};

class Image: public Flyweight<models::Image>::Value {
	friend void draw(Image *img, int x, int y, int w, int h);
	friend void draw(Image *img, int x, int y);
	friend void draw(Image *img, common::Point pt);

	private:
		void *m_img = nullptr;
		std::string m_spriteSheetKey;
		models::Size m_defaultSize;
		std::string m_key;

	protected:
		/**
		 * The bounds to cut out of the source image.
		 */
		common::Bounds m_bounds;

	public:
		/**
		 * Constructor
		 * @param model Model to build the Image from
		 */
		explicit Image(models::Image);

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

		std::string key();

	private:
		// disallow copying
		Image(Image&);
		Image &operator=(Image&);
};

class Animation: public Flyweight<models::Animation>::Value {
	private:
		std::vector<Image*> m_imgs;
		uint64 m_lastUpdate;
		uint64 m_interval;
		int m_slide;
		std::string m_key;

	public:
		explicit Animation(models::Animation);

		~Animation();

		void add(Image*);

		Image *getImage();

		bool loaded();

		std::string key();

		/**
		 * Gets the number of Images in the Animation.
		 * @return the number of Images in the Animation
		 */
		int size();
};

void drawLine(int x1, int y1, int x2, int y2);

void draw(Image *img, int x, int y, int w, int h);

void draw(Image *img, int x, int y);

void draw(Image *img, common::Point pt);

void draw(Text *txt, int x, int y);

void draw(Text *txt, common::Point pt);

void drawRect(int x, int y, int w, int h);

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

/**
 * Pushs the given view port the viewports stack.
 * This will get cleared out at the end of this draw iteration regardless
 * of whether or not it is manually popped.
 * @param bnds the bounds of the desired viewport 
 */
void pushClipRect(common::Bounds bnds);

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

/**
 * Pop the current clip rect.
 */
void popClipRect();

void resetViewport();


class Drawer {
	public:
		virtual ~Drawer() {};
		virtual void draw() = 0;
};

void addDrawer(Drawer*);

Animation *checkoutAnimation(Path path);

Animation *checkoutAnimation(models::Animation &anim);

void checkinAnimation(Animation *i);

Image *checkoutImage(models::Image img);

void checkinImage(Image *img);

}
}

#endif
