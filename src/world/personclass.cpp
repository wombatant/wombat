/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include <core/misc.hpp>
#include "personclass.hpp"

namespace wombat {
namespace world {

using models::SpriteDirection;
using models::SpriteMotion;
using models::TerrainType;

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
	for (uint i = 0; i < model.Overhead.size(); i++) {
		m_animations[i].resize(model.Overhead[i].size());
		for (uint ii = 0; ii < model.Overhead[i].size(); ii++) {
			m_animations[i][ii].resize(model.Overhead[i][ii].size());
			for (uint iii = 0; iii < model.Overhead[i][ii].size(); iii++) {
				m_animations[i][ii][iii].load(model.Overhead[i][ii][iii]);
			}
		}
	}
}

void PersonClass::draw(common::Point pt,
                       TerrainType tt, SpriteDirection facing, SpriteMotion motion) {
	auto anim = this->anim(tt, facing, motion);
	if (anim && anim->animation) {
		core::draw(anim->animation->getImage(), pt + anim->point);
	}
}

AnimLayer *PersonClass::anim(TerrainType tt, SpriteDirection facing, SpriteMotion motion) {
	for (int i = 0; i < 2; i++) {
		if ((uint) facing < m_animations.size() && (uint) motion < m_animations[(uint) facing].size()) {
			return &m_animations[(uint) tt][(uint) facing][(uint) motion];
		}
		facing = (SpriteDirection) 0;
		motion = (SpriteMotion) 0;
	}
	return nullptr;
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
