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
#ifndef WOMBAT_WORLD_TILE_HPP
#define WOMBAT_WORLD_TILE_HPP

#include <common/common.hpp>
#include "sprite.hpp"
#include "tileclass.hpp"

namespace wombat {
namespace world {

class Tile {
	private:
		Sprite *m_occupant = nullptr;
		TileClass *m_tileClass = nullptr;

	public:
		void load(models::Tile model);

		void draw(core::Graphics &gfx, common::Point pt);

		Sprite *getOccupant();
};

}
}

#endif
