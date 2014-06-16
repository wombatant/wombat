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
#include "personclass.hpp"

namespace wombat {
namespace world {

using models::SpriteDirection;
using models::SpriteMotion;

core::Flyweight<models::PersonClass> PersonClass::c_personClasses(
	[](models::PersonClass model) {
		if (model.Import != "") {
			core::read(model, model.Import);
		}
		return new PersonClass(model);
	}
);

PersonClass::PersonClass(models::PersonClass model) {
	m_title = model.Title[core::getLanguage()];

	m_animations.resize(model.Overhead.size());
	for (int i = 0; i < model.Overhead.size(); i++) {
		m_animations[i].resize(model.Overhead[i].size());
		for (int ii = 0; ii < model.Overhead[i].size(); ii++) {
			m_animations[i][ii].load(model.Overhead[i][ii]);
		}
	}
}

void PersonClass::draw(core::Graphics &gfx, common::Point pt, SpriteDirection facing, SpriteMotion motion) {
	auto anim = this->anim(facing, motion);
	if (anim.animation) {
		gfx.draw(anim.animation->getImage(), pt + anim.point);
	}
}

AnimLayer PersonClass::anim(models::SpriteDirection facing, models::SpriteMotion motion) {
	if ((int) facing < m_animations.size() && (int) motion < m_animations[(int) facing].size()) {
		return m_animations[(int) facing][(int) motion];
	}
	return AnimLayer();
}

PersonClass *PersonClass::checkout(models::PersonClass model) {
	return dynamic_cast<PersonClass*>(c_personClasses.checkout(model));
}

PersonClass *PersonClass::checkout(std::string path) {
	return dynamic_cast<PersonClass*>(c_personClasses.checkout(path));
}

void PersonClass::checkin(PersonClass *pc) {
	c_personClasses.checkin(pc);
}

}
}
