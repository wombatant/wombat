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
	Drawer *test = 0;
	if (args[2] == "animation") {
		test = new AnimationTest(args[3]);
	} else if (args[2] == "tile") {
		test = new TileClassTest(args[3]);
	}
	return test;
}

// Animation Test
AnimationTest::AnimationTest(std::string path) {
	models::Animation anim;
	core::read(anim, path);
	m_anim = new Animation(anim);
}

void AnimationTest::draw(Graphics &g) {
	if (m_anim->loaded()) {
		auto img = m_anim->getImage();
		g.draw(img, 42, 42);
	}
}

// Tile Test
TileClassTest::TileClassTest(std::string path) {
	using namespace models::cyborgbear;
	models::Tile model;
	core::read(model, path);
	m_tileClass = world::Tile::checkout(path);
}

void TileClassTest::draw(Graphics &g) {
	m_tileClass->drawLower(g, common::Point(42, 42));
	m_tileClass->drawUpper(g, common::Point(42, 42));
}

}
}
