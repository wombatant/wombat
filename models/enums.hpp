/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_MODELS_ENUMS_HPP
#define WOMBAT_MODELS_ENUMS_HPP

namespace models {

enum class SpriteType: int {
	Inanimate = 1,
	Person,
	Creature
};

enum class SpriteDirection: int {
	North = 0,
	South,
	East,
	West
};

enum class SpriteMotion: int {
	Still = 1,
	Walking
};

}

#endif
