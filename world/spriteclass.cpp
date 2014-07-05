/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "person.hpp"
#include "spriteclass.hpp"

namespace wombat {
namespace world {

core::Flyweight<models::SpriteClass> SpriteClass::c_spriteClasses(
	[](models::SpriteClass model) -> SpriteClass* {
		switch ((models::SpriteType) model.SpriteType) {
		case models::SpriteType::Inanimate:
			break;
		case models::SpriteType::Person:
			break;
		case models::SpriteType::Creature:
			break;
		}
		return nullptr;
	}
);

SpriteClass *SpriteClass::checkout(models::SpriteClass model) {
	return dynamic_cast<SpriteClass*>(c_spriteClasses.checkout(model));
}

SpriteClass *SpriteClass::checkout(std::string path) {
	return dynamic_cast<SpriteClass*>(c_spriteClasses.checkout(path));
}

void SpriteClass::checkin(SpriteClass *&pc) {
	c_spriteClasses.checkin(pc);
	pc = 0;
}


SpriteClass::SpriteClass() {
}

SpriteClass::~SpriteClass() {
}

}
}
