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

		int m_terrainFlags = 0;
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

		void drawUpper(core::Graphics &g, common::Point p);
		void drawLower(core::Graphics &g, common::Point p);

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
		void draw(core::Graphics &g, int x, int y, AnimLayer &anims);

		// prevent copies
		TileClass(const TileClass&);
		TileClass &operator=(const TileClass&);
};

}
}

#endif
