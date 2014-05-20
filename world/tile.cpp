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
#include "tile.hpp"

namespace wombat {
namespace world {

// Static

const int Tile::Width = 32;
const int Tile::Height = 32;

core::Flyweight<models::Tile> Tile::c_tileClasses([](models::Tile &model) {
	if (model.Import != "") {
		core::read(model, model.Import);
	}

	AnimLayer al;
	auto tc = new Tile();
	tc->m_terrainFlags = model.TerrainType;

	al.animation = core::checkoutAnimation(model.UpperAnim.Animation);
	al.point = model.UpperAnim.Point;
	tc->m_upperAnim = al;

	al.animation = core::checkoutAnimation(model.LowerAnim.Animation);
	al.point = model.LowerAnim.Point;
	tc->m_lowerAnim = al;

	return tc;
});

Tile::Tile() {
}

Tile::~Tile() {
}

void Tile::drawUpper(core::Graphics &g, common::Point p) {
	draw(g, p.X, p.Y, m_upperAnim);
}

void Tile::drawLower(core::Graphics &g, common::Point p) {
	draw(g, p.X, p.Y, m_lowerAnim);
}

void Tile::draw(core::Graphics &g, int x, int y, AnimLayer &anim) {
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

Tile *Tile::checkout(models::Tile model) {
	return dynamic_cast<Tile*>(c_tileClasses.checkout(model));
}

Tile *Tile::checkout(std::string path) {
	return dynamic_cast<Tile*>(c_tileClasses.checkout(path));
}

void Tile::checkin(Tile *tc) {
	c_tileClasses.checkin(tc);
}

}
}
