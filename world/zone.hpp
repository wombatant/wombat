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
#ifndef WOMBAT_WORLD_ZONE_HPP
#define WOMBAT_WORLD_ZONE_HPP

#include "core/core.hpp"
#include "tile.hpp"

namespace wombat {
namespace world {

class Zone: public core::Task {
	private:
		class TileGrid {
			private:
				Tile ***m_tiles;
				int m_width;
				int m_height;
				int m_layers;

			public:
				/**
				 * Constructor
				 */
				TileGrid();

				/**
				 * Destructor
				 */
				~TileGrid();

				/**
				 * Allocates Tile grid.
				 * @param w width of grid
				 * @param h height of grid
				 * @param layers layers of grid
				 */
				void allocate(int w, int h, int layers);

				/**
				 * Gets the Tile at the given address.
				 * @param x X address of desired Tile
				 * @param y Y address of desired Tile
				 * @param layer layer of desired Tile
				 * @return pointer to the Tile at the given address
				 */
				inline Tile &at(int x, int y, int layer) {
					return m_tiles[layer][y][x];
				}
		} m_tiles;
		bool m_loaded;

	public:
		/**
		 * Constructor
		 */
		Zone();

		/**
		 * Destructor
		 */
		~Zone();

		core::TaskState run(core::Event);

		/**
		 * Indicates whether or not the Zone has been loaded yet.
		 * @return whether or not the Zone has been loaded yet
		 */
		bool loaded();
};

}
}

#endif
