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
		void draw(core::Graphics&);
};

class TileClassTest: public core::Drawer {
	private:
		world::Tile *m_tileClass;
	public:
		TileClassTest(std::string path);
		void draw(core::Graphics&);
};

core::Drawer *test(std::vector<std::string>&);

}
}

#endif
