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
#include "tests.hpp"

namespace wombat {
namespace tests {

Drawer *test(std::vector<std::string> &args) {
	ImageTest *test = 0;
	if (args[2] == "image") {
		test = new ImageTest(args[3]);
		core::addDrawer(test);
	}
	return test;
}

//Image Test
ImageTest::ImageTest(std::string path) {
	models::Image img;
	img.readJsonFile(path + ".json");
	m_img = core::checkoutImage(img);
}

void ImageTest::draw(Graphics *g) {
	if (m_img && m_img->loaded()) {
		//printf("drawing\n");
		g->draw(m_img, 42, 42);
	}
}

//Animation Test
AnimationTest::AnimationTest(std::string path) {
	models::Animation anim;
	anim.readJsonFile(path + ".json");
}

void AnimationTest::draw(Graphics *g) {
	auto img = m_anim->getImage();
	if (img && img->loaded()) {
		//printf("drawing\n");
		g->draw(img, 42, 42);
	}
}

}
}
