/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_TESTS_HPP
#define WOMBAT_TESTS_HPP

#include <string>

#include <core/core.hpp>
#include <world/tile.hpp>
#include <models/models.hpp>

namespace wombat {
namespace tests {

class AnimationTest: public core::Drawer {
	private:
		core::Animation *m_anim;
	public:
		AnimationTest(std::string path);
		void draw();
};

class TileClassTest: public core::Drawer {
	private:
		world::TileClass *m_tileClass;
	public:
		TileClassTest(std::string path);
		void draw();
};

core::Drawer *test(std::vector<std::string>&);

}
}

#endif
