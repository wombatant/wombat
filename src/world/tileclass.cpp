/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "_etc.hpp"
#include "tileclass.hpp"

namespace wombat {
namespace world {

// Static

core::ModelFlyweight<models::TileClass> TileClass::c_tileClasses(
	[](models::TileClass model) {
		if (model.Import != "") {
			core::read(model, model.Import);
		}

		auto tc = new TileClass();
		tc->m_terrainFlags = model.TerrainType;
		tc->m_upperAnim.load(model.UpperAnim);
		tc->m_lowerAnim.load(model.LowerAnim);

		return tc;
	}
);

TileClass::TileClass() {
}

TileClass::~TileClass() {
}

void TileClass::drawUpper(core::Graphics &g, common::Point p) {
	draw(g, p.X, p.Y, m_upperAnim);
}

void TileClass::drawLower(core::Graphics &g, common::Point p) {
	draw(g, p.X, p.Y, m_lowerAnim);
}

void TileClass::draw(core::Graphics &g, int x, int y, AnimLayer &anim) {
	if (anim.animation) {
		x += anim.point.X;
		y += anim.point.Y;
		g.draw(anim.animation->getImage(), x, y);
	}
}

TileClass *TileClass::checkout(models::TileClass model) {
	return dynamic_cast<TileClass*>(c_tileClasses.checkout(model));
}

TileClass *TileClass::checkout(std::string path) {
	return dynamic_cast<TileClass*>(c_tileClasses.checkout(path));
}

void TileClass::checkin(TileClass *&tc) {
	c_tileClasses.checkin(tc);
	tc = 0;
}

}
}
