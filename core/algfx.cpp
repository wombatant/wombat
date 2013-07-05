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
#include "gfx.hpp"
#include "flyweight.hpp"

namespace wombat {
namespace core {

using std::string;

//Image

Image::Image(string path) {
	m_alImg = al_load_bitmap(path.c_str());
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

void Graphics::draw(Image* img, int x, int y, int w, int h) {
	if (w == -1)
		w = img->width();
	if (h == -1)
		h = img->height();
	al_draw_scaled_bitmap(img->m_alImg, 0, 0, img->width(), img->height(), x, y, w, h, 0);
}

}
}
