/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "person.hpp"
#include "sprite.hpp"
#include "zone.hpp"

namespace wombat {
namespace world {

using core::TaskState;

void Sprite::setAddress(common::Point pt) {
}

void Sprite::setZone(Zone *zone) {
}

std::string Sprite::id() {
	return "";
}

Sprite *loadSprite(models::Sprite model) {
	switch ((models::SpriteType) model.SpriteType) {
	case models::SpriteType::Inanimate:
		break;
	case models::SpriteType::Person:
		return new Person(model);
	case models::SpriteType::Creature:
		break;
	default:
		break;
	}
	return nullptr;
}

}
}
