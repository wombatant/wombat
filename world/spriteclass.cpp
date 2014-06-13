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
		return 0;
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
