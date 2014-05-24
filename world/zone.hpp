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

#include <common/common.hpp>
#include <core/core.hpp>
#include "tileinstance.hpp"

namespace wombat {
namespace world {

class Zone: public core::Task {
	private:
		class TileGrid {
			private:
				TileInstance ***m_tiles;
				int m_tilesWide;
				int m_tilesHigh;
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
				 * Sets the dimensions of the TileInstance grid.
				 * @param w width of grid
				 * @param h height of grid
				 * @param layers layers of grid
				 */
				void setDimensions(int w, int h, int layers);

				/**
				 * Allocates TileInstance grid.
				 */
				void allocate();

				/**
				 * Frees TileInstance grid.
				 */
				void free();

				/**
				 * Gets the TileInstance at the given address.
				 * @param x X address of desired TileInstance
				 * @param y Y address of desired TileInstance
				 * @param layer layer of desired TileInstance
				 * @return pointer to the TileInstance at the given address
				 */
				inline TileInstance &at(int x, int y, int layer) {
					return m_tiles[layer][y][x];
				}

				/**
				 * Gets the number of tiles this grid spans horizontally.
				 * @return the number of tiles this grid spans horizontally
				 */
				int tilesWide();

				/**
				 * Gets the number of tiles this grid spans vertically.
				 * @return the number of tiles this grid spans vertically
				 */
				int tilesHigh();

				/**
				 * Gets the number of layers this grid has.
				 * @return the number of layers this grid has
				 */
				int layers();
		} m_tiles;
		core::Path m_path;
		common::Point m_address;
		// used to count the number Cameras watching the Zone to
		//  determine when to unload
		int m_dependents;
		bool m_loaded;
		core::Mutex m_mutex;

	public:
		/**
		 * Constructor
		 */
		Zone(models::ZoneInstance model);

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

		/**
		 * Gets the bounds of this Zone.
		 * @return the bounds of this Zone
		 */
		common::Bounds bounds();

		void draw(core::Graphics &g, common::Bounds crop, common::Point translation);

		/**
		 * Gets the coordinates of this Zone.
		 * @return the coordinates of this Zone
		 */
		common::Point loc();

		/**
		 * Increments the dependent counter.
		 */
		void incDeps();

		/**
		 * Decrements the dependent counter.
		 */
		void decDeps();

	private:
		void load();

		void unload();
};

}
}

#endif
