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
#include "core.hpp"
#include "flyweight.hpp"

namespace wombat {
namespace core {

using std::string;

//Image

Image::Image(string path) {
	m_alImg = al_load_bitmap(path.c_str());
	m_defaultSize.width = -1;
	m_defaultSize.height = -1;
}

Image::Image(models::Image &img) {
	m_alImg = al_load_bitmap(img.path.c_str());
	m_defaultSize.width = img.defaultSize.width;
	m_defaultSize.height = img.defaultSize.height;
}

Image::~Image() {
	al_destroy_bitmap(m_alImg);
}

int Image::width() {
	return al_get_bitmap_width(m_alImg);
}

int Image::height() {
	return al_get_bitmap_height(m_alImg);
}

bool Image::loaded() {
	return m_alImg;
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
		printf("Draw1: %d, %d, %d, %d\n", x, y, w, h);
		printf("Draw2: %d, %d, %d, %d\n", img->m_bounds.x, img->m_bounds.y, img->width(), img->height());
		al_draw_scaled_bitmap(img->m_alImg, img->m_bounds.x, img->m_bounds.y, img->width(), img->height(), x, y, w, h, 0);
	}
}

}
}
