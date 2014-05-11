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
	auto tc = new Tile();
	tc->m_terrainFlags = model.TerrainFlags;
	for (auto alm : model.UpperAnims) {
		AnimLayer al;
		al.animation = core::checkoutAnimation(alm.Animation);
		al.point = alm.Point;
		tc->m_upperAnims.push_back(al);
	}
	for (auto alm : model.LowerAnims) {
		AnimLayer al;
		al.animation = core::checkoutAnimation(alm.Animation);
		al.point = alm.Point;
		tc->m_lowerAnims.push_back(al);
	}
	return tc;
});

Tile::Tile() {
}

Tile::~Tile() {
}

void Tile::drawUpper(core::Graphics &g, int x, int y) {
	draw(g, x, y, m_upperAnims);
}

void Tile::drawLower(core::Graphics &g, int x, int y) {
	draw(g, x, y, m_lowerAnims);
}

void Tile::draw(core::Graphics &g, int x, int y, std::vector<AnimLayer> &anims) {
	g.pushClipRect(x, y, Width, Height);
	for (auto i : m_lowerAnims) {
		auto x = i.point.X;
		auto y = i.point.Y;
		g.draw(i.animation->getImage(), x, y);
	}
	g.popClipRect();
}

Tile *Tile::checkout(std::string path) {
	return dynamic_cast<Tile*>(c_tileClasses.checkout(path));
}

void Tile::checkin(Tile *tc) {
	c_tileClasses.checkin(tc);
}

}
}
