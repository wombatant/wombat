/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_WORLD_SPRITE_HPP
#define WOMBAT_WORLD_SPRITE_HPP

#include "spriteclass.hpp"

namespace wombat {
namespace world {

class Sprite {
	public:
		/**
		 * Default setAddress does nothing, this is just here for classes based
		 * on Sprite can acquire their address.
		 */
		virtual void setAddress(common::Point pt);

		/**
		 * Default setZone does nothing, this is just here for classes based
		 * on Sprite can acquire a reference to their Zone.
		 */
		virtual void setZone(class Zone *zone);

		virtual std::string id();

		virtual void draw(core::Graphics &gfx, class Tile *tile, common::Point pt) = 0;
};

Sprite *loadSprite(models::Sprite model);

}
}

#endif
