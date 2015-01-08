/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_MODELS_ENUMS_HPP
#define WOMBAT_MODELS_ENUMS_HPP

namespace models {

enum class SpriteDirection {
	North = 0,
	South = 1,
	East  = 2,
	West  = 3
};

enum class SpriteMotion {
	Still   = 0,
	Walking = 1
};

enum class SpriteType {
	Inanimate = 1,
	Person    = 2,
	Creature  = 3,
	Item      = 4,
	Container = 5
};

enum class TerrainType {
	Land      = 0,
	Water     = 1,
	Whirlpool = 2,
	Waterfall = 3
};

enum class WorldAbilityFlags {
	None      = 0,
	Swim      = 1,
	Whirlpool = 2,
	Waterfall = 4,
	Cut       = 8
};

}

#endif
