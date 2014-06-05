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
#include "tileclass.hpp"

namespace wombat {
namespace world {

// Static

const int TileClass::Width = 32;
const int TileClass::Height = 32;

core::Flyweight<models::TileClass> TileClass::c_tileClasses(
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
		g.pushClipRect(x, y, Width, Height);
		{
			auto x = anim.point.X;
			auto y = anim.point.Y;
			g.draw(anim.animation->getImage(), x, y);
		}
		g.popClipRect();
	}
}

TileClass *TileClass::checkout(models::TileClass model) {
	return dynamic_cast<TileClass*>(c_tileClasses.checkout(model));
}

TileClass *TileClass::checkout(std::string path) {
	return dynamic_cast<TileClass*>(c_tileClasses.checkout(path));
}

void TileClass::checkin(TileClass *tc) {
	c_tileClasses.checkin(tc);
}

}
}
