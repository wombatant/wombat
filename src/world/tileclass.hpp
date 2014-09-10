/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_WORLD_TILECLASS_HPP
#define WOMBAT_WORLD_TILECLASS_HPP

#include <core/core.hpp>
#include "animlayer.hpp"

namespace wombat {
namespace world {

class TileClass: public core::Flyweight<models::TileClass>::GenericValue {
	private:
		static core::Flyweight<models::TileClass> c_tileClasses;

		models::TerrainType m_terrainType = models::TerrainType::Land;
		AnimLayer m_upperAnim;
		AnimLayer m_lowerAnim;

	public:
		/**
		 * Constructor
		 */
		TileClass();

		/**
		 * Destructor
		 */
		~TileClass();

		void drawUpper(common::Point p);
		void drawLower(common::Point p);

		/**
		 * @return a models::TerrainType representing the terrain type (Land, Water, Whirlpool, Waterfall)
		 */
		models::TerrainType terrainType();

		/**
		 * Checks out the TileClass object matching the given model.
		 * @param model model representing the desired TileClass
		 */
		static TileClass *checkout(models::TileClass model);

		/**
		 * Checks out the TileClass object stored at the given path.
		 * @param path path of the TileClass to checkout
		 */
		static TileClass *checkout(std::string path);

		/**
		 * Checks in the given TileClass object.
		 * @param tc TileClass object to checkin
		 */
		static void checkin(TileClass *&tc);

	private:
		void draw(int x, int y, AnimLayer &anims);

		// prevent copies
		TileClass(const TileClass&);
		TileClass &operator=(const TileClass&);
};

}
}

#endif
