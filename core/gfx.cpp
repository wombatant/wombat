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
#include <iostream>
#include "core.hpp"
#include "flyweight.hpp"

namespace wombat {
namespace core {

using std::string;

//Image

FlyweightNode *loadImage(modelmaker::Model &key) {
	models::Image &mod = (models::Image&) key;
	Image *i = new Image(mod);
	if (i->loaded()) {
		return i;
	} else {
		delete i;
		return 0;
	}
}

Flyweight imageCache(loadImage);

Image *checkoutImage(string path) {
	models::Image img;
	img.path = path;
	img.defaultSize.width = -1;
	img.defaultSize.height = -1;
	return (Image*) imageCache.checkout(img);
}

Image *checkoutImage(models::Image &img) {
	return (Image*) imageCache.checkout(img);
}

void checkinImage(string path) {
	imageCache.checkin(path);
}

void checkinImage(Image &i) {
	checkinImage(i);
}

string Image::key() {
	return m_path;
}

int Image::defaultWidth() {
	return m_defaultSize.width;
}

int Image::defaultHeight() {
	return m_defaultSize.height;
}

}
}
