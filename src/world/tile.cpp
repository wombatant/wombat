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
using models::TerrainType;

Tile::~Tile() {
	unload();
}

void Tile::load(models::Tile model) {
	m_tileClass = TileClass::checkout(model.TileClass);
	m_occupant = loadSprite(model.Occupant);
}

void Tile::unload() {
	TileClass::checkin(m_tileClass);
}

void Tile::draw(Point pt) {
	if (m_tileClass) {
		m_tileClass->drawLower(pt);
		m_tileClass->drawUpper(pt);
	}
}

Sprite *Tile::getOccupant() {
	return m_occupant;
}

TerrainType Tile::terrainType() {
	return m_tileClass->terrainType();
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
