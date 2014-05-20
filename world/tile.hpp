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

#include <string>
#include <common/common.hpp>
#include <core/core.hpp>
#include "animlayer.hpp"

namespace wombat {
namespace world {

class Tile: public core::Flyweight<models::Tile>::GenericValue {
	public:
		static const int Width;
		static const int Height;

	private:
		static core::Flyweight<models::Tile> c_tileClasses;

		int m_terrainFlags;
		AnimLayer m_upperAnim;
		AnimLayer m_lowerAnim;

	public:
		/**
		 * Constructor
		 */
		Tile();

		/**
		 * Destructor
		 */
		~Tile();

		void drawUpper(core::Graphics &g, common::Point p);
		void drawLower(core::Graphics &g, common::Point p);

		/**
		 * Checks out the Tile object matching the given model.
		 * @param model model representing the desired Tile
		 */
		static Tile *checkout(models::Tile model);

		/**
		 * Checks out the Tile object stored at the given path.
		 * @param path path of the Tile to checkout
		 */
		static Tile *checkout(std::string path);

		/**
		 * Checks in the given Tile object.
		 * @param tc Tile object to checkin
		 */
		static void checkin(Tile*);

	private:
		void draw(core::Graphics &g, int x, int y, AnimLayer &anims);

		// prevent copies
		Tile(const Tile&);
		Tile &operator=(const Tile&);
};

}
}

#endif
