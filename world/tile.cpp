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
#include "tile.hpp"

namespace wombat {
namespace world {

extern bool _debugMode;

Tile::Tile() {
	m_occupant = 0;
	m_tileClass = 0;
}

void Tile::load(models::Tile model) {
	m_tileClass = TileClass::checkout(model.TileClass);
	m_occupant = loadSprite(model.Occupant);
}

void Tile::draw(core::Graphics &gfx, common::Point pt) {
	if (m_tileClass) {
		m_tileClass->drawLower(gfx, pt);
		m_tileClass->drawUpper(gfx, pt);
	}
	if (m_occupant) {
		m_occupant->draw(gfx, pt);
	}
	if (_debugMode) {
		gfx.drawLine(pt.X, pt.Y, pt.X, pt.Y + TileClass::Height);
		gfx.drawLine(pt.X, pt.Y, pt.X + TileClass::Width, pt.Y);
	}
}

}
}
