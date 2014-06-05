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

SpriteClass::SpriteClass() {
	m_attr = 0;
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

}
}
