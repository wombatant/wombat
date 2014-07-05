/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
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
