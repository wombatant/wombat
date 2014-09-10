/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "tests.hpp"

namespace wombat {
namespace tests {

using namespace core;

Drawer *test(std::vector<std::string> &args) {
	Drawer *test = nullptr;
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

void AnimationTest::draw() {
	if (m_anim->loaded()) {
		auto img = m_anim->getImage();
		core::draw(img, 42, 42);
	}
}

// TileClass Test
TileClassTest::TileClassTest(std::string path) {
	models::TileClass model;
	core::read(model, path);
	m_tileClass = world::TileClass::checkout(path);
}

void TileClassTest::draw() {
	m_tileClass->drawLower(common::Point(42, 42));
	m_tileClass->drawUpper(common::Point(42, 42));
}

}
}
