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
#include "zone.hpp"

namespace wombat {
namespace world {

using core::TaskState;


Zone::TileGrid::~TileGrid() {
	free();
}

void Zone::TileGrid::setDimensions(int w, int h, int layers) {
	m_tilesWide = w;
	m_tilesHigh = h;
	m_layers = layers;
}

void Zone::TileGrid::allocate() {
	m_tiles = (Tile***) malloc(sizeof(Tile**) * m_layers);
	for (int l = 0; l < m_layers; l++) {
		m_tiles[l] = (Tile**) malloc(sizeof(Tile*) * m_tilesHigh);
		for (int y = 0; y < m_tilesHigh; y++) {
			m_tiles[l][y] = (Tile*) malloc(sizeof(Tile) * m_tilesWide);
			Tile t;
			for (int x = 0; x < m_tilesWide; x++) {
				m_tiles[l][y][x] = t;
			}
		}
	}
}

void Zone::TileGrid::free() {
	if (m_tiles) {
		for (int l = 0; l < m_layers; l++) {
			for (int y = 0; y < m_tilesHigh; y++) {
				::free(m_tiles[l][y]);
			}
			::free(m_tiles[l]);
		}
		::free(m_tiles);
		m_tiles = 0;
	}
}

int Zone::TileGrid::tilesWide() {
	return m_tilesWide;
}

int Zone::TileGrid::tilesHigh() {
	return m_tilesHigh;
}

int Zone::TileGrid::layers() {
	return m_layers;
}


Zone::Zone(models::ZoneInstance model) {
	models::ZoneHeader header;
	core::read(header, model.ZoneHeader);
	m_address = model.Address;
	m_tiles.setDimensions(header.TilesWide, header.TilesHigh, header.Layers);
	m_path = header.Zone;
}

Zone::~Zone() {
}

TaskState Zone::run(core::Event e) {
	switch (e.type()) {
	case core::EventType::Timeout:
		if (m_dependents == 0) {
			unload();
		}
		return 10000;
	default:
		return TaskState::Continue;
	}
}

bool Zone::loaded() {
	return m_loaded;
}

common::Bounds Zone::bounds() {
	common::Bounds bnds;
	bnds.X = TileClass::Width * m_address.X;
	bnds.Y = TileClass::Height * m_address.Y;
	bnds.Width = TileClass::Width * m_tiles.tilesWide();
	bnds.Height = TileClass::Height * m_tiles.tilesHigh();
	return bnds;
}

void Zone::draw(core::Graphics &g, common::Bounds bnds, common::Point translation) {
	auto loc = common::Point(bounds().X, bounds().Y);
	for (int l = 0; l < m_tiles.layers(); l++) {
		for (int y = bnds.Y; y < bnds.y2(); y += TileClass::Height) {
			for (int x = bnds.X; x < bnds.x2(); x += TileClass::Width) {
				auto &tile = m_tiles.at(x / TileClass::Width, y / TileClass::Height, l);
				tile.draw(g, common::Point(x, y) + loc + translation);
			}
		}
	}
}

common::Point Zone::loc() {
	return common::Point(TileClass::Width * m_address.X, TileClass::Height * m_address.Y);
}

void Zone::incDeps() {
	m_mutex.lock();
	m_dependents++;
	if (m_dependents == 1 && !m_loaded) {
		load();
	}
	m_mutex.unlock();
}

void Zone::decDeps() {
	m_mutex.lock();
	if (m_dependents > 0) {
		m_dependents--;
	}
	m_mutex.unlock();
}

void Zone::add(Sprite *sprite) {
	m_sprites[sprite->id()] = sprite;
	auto p = dynamic_cast<Person*>(sprite);
	if (p) {
	}
}

void Zone::remove(Sprite *sprite) {
	for (auto v : m_sprites) {
		if (v.second == sprite) {
			m_sprites.erase(v.first);
		}
	}
}

Sprite *Zone::getSprite(std::string id) {
	return m_sprites[id];
}

void Zone::load() {
	models::Zone zone;
	core::read(zone, m_path);
	m_tiles.allocate();

	for (int l = 0; l < m_tiles.layers(); l++) {
		for (int y = 0; y < m_tiles.tilesHigh(); y++) {
			for (int x = 0; x < m_tiles.tilesWide(); x++) {
				auto &tile = m_tiles.at(x, y, l);
				auto model = zone.Tiles[l][y][x];
				tile.load(model);

				auto oc = tile.getOccupant();
				if (oc && oc->id() != "") {
					add(oc);
				}
			}
		}
	}

	m_loaded = true;
}

void Zone::unload() {
	for (auto s : m_sprites) {
		m_sprites.erase(s.first);
	}
	m_tiles.free();
	m_loaded = false;
}

}
}
