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
#include "tests.hpp"

namespace wombat {
namespace tests {

ImageTest::ImageTest(std::string path) {
	models::Image img;
	img.loadFile(path + ".json");
	m_img = core::checkoutImage(img);
}

void ImageTest::draw(Graphics *g) {
	if (m_img && m_img->loaded()) {
		g->draw(m_img, 42, 42);
	}
}

AnimationTest::AnimationTest(std::string path) {
	anim.loadFile(path);
}

void AnimationTest::draw(Graphics *g) {
}

}
}
