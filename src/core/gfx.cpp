/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include <iostream>
#include "misc.hpp"
#include "gfx.hpp"

namespace wombat {
namespace core {

std::vector<Drawer*> _drawers;


void addDrawer(Drawer *d) {
	_drawers.push_back(d);
}

// Graphics

Color::Color(uint8 r, uint8 g, uint8 b, uint8 a) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

// Graphics

void draw(Image *img, common::Point pt) {
	draw(img, pt.X, pt.Y);
}

// Image

Flyweight<models::Image> imageCache([](models::cyborgbear::Model &key) -> Image* {
	models::Image &mod = (models::Image&) key;
	Image *i = new Image(mod);
	if (i->loaded()) {
		return i;
	} else {
		delete i;
		return nullptr;
	}
});


Image *checkoutImage(Path path) {
	models::Image img;
	img.SpriteSheet = path;
	img.DefaultSize.Width = -1;
	img.DefaultSize.Height = -1;
	return (Image*) imageCache.checkout(img);
}

Image *checkoutImage(models::Image img) {
	return (Image*) imageCache.checkout(img);
}


void checkinImage(Image *i) {
	imageCache.checkin(i->key());
}

std::string Image::key() {
	return m_key;
}

int Image::defaultWidth() {
	return m_defaultSize.Width;
}

int Image::defaultHeight() {
	return m_defaultSize.Height;
}


// Animation

Flyweight<models::Animation> animCache([](models::Animation &key) -> Animation* {
	if (key.Import != "") {
		core::read(key, key.Import);
	}
	Animation *a = new Animation(key);
	if (a->loaded()) {
		return a;
	} else {
		delete a;
		return nullptr;
	}
});

Animation *checkoutAnimation(std::string path) {
	return (Animation*) animCache.checkout(path);
}

Animation *checkoutAnimation(models::Animation &anim) {
	return (Animation*) animCache.checkout(anim);
}

void checkinAnimation(Animation *i) {
	animCache.checkin(i->key());
}

Animation::Animation(models::Animation model) {
	m_slide = 0;
	m_lastUpdate = eventTime();

	//for now, just use a universal interval
	if (model.Images.size()) {
		m_interval = model.Images[0].Interval;
	}

	for (auto img : model.Images) {
		add(checkoutImage(img.Image));
	}
	m_key = model.toJson();
}

Animation::~Animation() {
}

std::string Animation::key() {
	return m_key;
}

void Animation::add(Image *img) {
	m_imgs.push_back(img);
}

Image *Animation::getImage() {
	if (m_imgs.size()) {
		auto time = core::time();
		if (m_lastUpdate <= time - m_interval) {
			m_slide = (m_slide + 1) % m_imgs.size();
			m_lastUpdate = time;
		}
		return m_imgs[m_slide];
	}
	return nullptr;
}

bool Animation::loaded() {
	bool retval = false;
	for (auto img : m_imgs) {
		if (img) {
			retval = true;
		} else {
			return false;
		}
	}
	return retval;
}

int Animation::size() {
	return m_imgs.size();
}

}
}
