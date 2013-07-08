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
#ifndef WOMBAT_CORE_GFX_HPP
#define WOMBAT_CORE_GFX_HPP

#include <string>

#ifdef WITH_ALLEGRO
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#endif

#include "../models/enginemodels.hpp"

#include "flyweight.hpp"

namespace wombat {
namespace core {

using std::string;

class Image: public FlyweightNode {
	public:
#ifdef WITH_ALLEGRO
		ALLEGRO_BITMAP *m_alImg;
#endif
	private:
		models::Size m_defaultSize;
		string m_path;
	public:
		Image(models::Image&);
		Image(string path);
		virtual ~Image();
		int width();
		int height();
		int defaultWidth();
		int defaultHeight();
		bool loaded();
		string key();
};

class Animation {
	private:
		vector<Image*> imgs;
	public:
		Animation(models::Animation&);
		void add(Image*);
};

class Graphics {
	public:
		void draw(Image *img, int x, int y, int w = -1, int h = -1);
};

class Drawer {
	public:
		virtual void draw(Graphics*) = 0;
};


Image *checkoutImage(string path);

Image *checkoutImage(models::Image &img);

void checkinImage(string path);

void checkinImage(string path);

void checkinImage(Image &img);

}
}

#endif
