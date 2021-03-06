/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_WORLD_TILE_HPP
#define WOMBAT_WORLD_TILE_HPP

#include "_etc.hpp"
#include "sprite.hpp"
#include "tileclass.hpp"

namespace wombat {
namespace world {

class Tile {
	private:
		Sprite *m_occupant = nullptr;
		TileClass *m_tileClass = nullptr;

	public:
		~Tile();

		void load(models::Tile model);

		void unload();

		void draw(common::Point pt);

		Sprite *getOccupant();

		/**
		 * @return a models::TerrainType representing the terrain type (Land, Water, Whirlpool, Waterfall)
		 */
		models::TerrainType terrainType();

		/**
		 * Claims this Tile for the given Sprite.
		 * @param occupant the Sprite wanting to claim this Tile
		 * @return 0 for success
		 */
		Error claim(Sprite *occupant);

		/**
		 * Releases the current occupant's claim on this Tile.
		 */
		void release();
};

}
}

#endif
