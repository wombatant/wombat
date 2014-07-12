/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "_etc.hpp"
#include "person.hpp"
#include "tile.hpp"

namespace wombat {
namespace world {

using common::Point;

void Tile::load(models::Tile model) {
	m_tileClass = TileClass::checkout(model.TileClass);
	m_occupant = loadSprite(model.Occupant);
}

void Tile::draw(core::Graphics &gfx, Point pt) {
	if (m_tileClass) {
		m_tileClass->drawLower(gfx, pt);
		m_tileClass->drawUpper(gfx, pt);
	}
	if (m_occupant) {
		m_occupant->draw(gfx, pt);
	}

	if (_debug) {
		gfx.drawLine(pt.X, pt.Y, pt.X, pt.Y + TileHeight);
		gfx.drawLine(pt.X, pt.Y, pt.X + TileWidth, pt.Y);
	}
}

Sprite *Tile::getOccupant() {
	return m_occupant;
}

Error Tile::claim(Sprite *occupant) {
	if (m_occupant == nullptr) {
		m_occupant = occupant;
		return 0;
	}
	return 1;
}

void Tile::release() {
	m_occupant = nullptr;
}

}
}
