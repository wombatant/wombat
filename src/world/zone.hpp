/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_WORLD_ZONE_HPP
#define WOMBAT_WORLD_ZONE_HPP

#include <core/task.hpp>
#include "event.hpp"
#include "person.hpp"
#include "tile.hpp"

namespace wombat {
namespace world {

class Zone: public core::Task {
	private:
		class TileGrid {
			private:
				Tile ***m_tiles = nullptr;
				int m_tilesWide = 0;
				int m_tilesHigh = 0;
				int m_layers = 0;

			public:
				/**
				 * Destructor
				 */
				~TileGrid();

				/**
				 * Sets the dimensions of the Tile grid.
				 * @param w width of grid
				 * @param h height of grid
				 * @param layers layers of grid
				 */
				void setDimensions(int w, int h, int layers);

				/**
				 * Allocates Tile grid.
				 */
				void allocate();

				/**
				 * Frees Tile grid.
				 */
				void free();

				/**
				 * Gets the Tile at the given address. Returns null if
				 * the given address is invalid
				 * @param x X address of desired Tile
				 * @param y Y address of desired Tile
				 * @param layer layer of desired Tile
				 * @return pointer to the Tile at the given address
				 */
				inline Tile *safeAt(int x, int y, int layer) {
					if (layer < m_layers && y < m_tilesHigh && x < m_tilesWide &&
						layer >= 0 && y >= 0 && x >= 0) {
						return &m_tiles[layer][y][x];
					}
					return nullptr;
				}

				/**
				 * Gets the Tile at the given address.
				 * @param x X address of desired Tile
				 * @param y Y address of desired Tile
				 * @param layer layer of desired Tile
				 * @return pointer to the Tile at the given address
				 */
				inline Tile *at(int x, int y, int layer) {
					return &m_tiles[layer][y][x];
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
		int m_dependents = 0;
		bool m_loaded = false;
		std::map<std::string, Sprite*> m_sprites;
		// general mutex used for any atomic operations on this Zone
		core::Mutex m_mutex;
		core::TaskProcessor *m_taskProcessor = new core::TaskProcessor();

	public:
		/**
		 * Constructor
		 */
		Zone(models::ZoneInstance model);

		/**
		 * Destructor
		 */
		~Zone();

		core::TaskState run(core::Event) override;

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

		void draw(common::Bounds crop, common::Point translation,
		          std::pair<Sprite*, common::Point> focus);

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

		/**
		 * Adds the given Sprite to the sprite map.
		 * @param sprite the sprite to add
		 */
		void add(Sprite *sprite);

		/**
		 * Removes the given Sprite from the sprite map.
		 * @param sprite the sprite to remove
		 */
		void remove(Sprite *sprite);

		/**
		 * Gaets the Sprite with the given id.
		 * @param id the id of the desired Sprite
		 * @return the Sprite with the given id
		 */
		Sprite *getSprite(std::string id);

		/**
		 * Gaets the Sprite with the given id.
		 * @param id the id of the desired Sprite
		 * @return the Sprite with the given id
		 */
		class Person *getPerson(std::string id);

		/**
		 * Gets the Tile at the given address
		 * @param x the x address the address
		 * @param y the y address the address
		 * @return Tile at the given address
		 */
		Tile *getTile(int x, int y, int layer);

	private:
		void load();

		void unload();
};

}
}

#endif
