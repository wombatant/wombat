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
	[](models::SpriteClass model) {
		return new SpriteClass(model);
	}
);

SpriteClass::SpriteClass(models::SpriteClass model) {
	load(model);
}

SpriteClass::~SpriteClass() {
	if (m_attr) {
		delete m_attr;
	}
}

void SpriteClass::load(models::SpriteClass model) {
	m_spriteType = model.SpriteType;
	switch (m_spriteType) {
	case models::SpriteType_Inanimate:
		break;
	case models::SpriteType_Person:
		m_attr = new Person(model.Attributes);
		break;
	case models::SpriteType_Creature:
		break;
	}
}

SpriteClass *SpriteClass::checkout(models::SpriteClass model) {
	return dynamic_cast<SpriteClass*>(c_spriteClasses.checkout(model));
}

SpriteClass *SpriteClass::checkout(std::string path) {
	return dynamic_cast<SpriteClass*>(c_spriteClasses.checkout(path));
}

void SpriteClass::checkin(SpriteClass *pc) {
	c_spriteClasses.checkin(pc);
}


}
}
