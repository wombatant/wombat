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


Zone::TileGrid::TileGrid() {
	m_tiles = 0;
	m_tilesWide = m_tilesHigh = m_layers = 0;
}

Zone::TileGrid::~TileGrid() {
	free();
}

void Zone::TileGrid::setDimensions(int w, int h, int layers) {
	m_tilesWide = w;
	m_tilesHigh = h;
	m_layers = layers;
}

void Zone::TileGrid::allocate() {
	m_tiles = (TileInstance***) malloc(sizeof(TileInstance**) * m_layers);
	for (int l = 0; l < m_layers; l++) {
		m_tiles[l] = (TileInstance**) malloc(sizeof(TileInstance*) * m_tilesHigh);
		for (int y = 0; y < m_tilesHigh; y++) {
			m_tiles[l][y] = (TileInstance*) malloc(sizeof(TileInstance) * m_tilesWide);
			TileInstance t;
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
	m_loaded = false;
	m_dependents = 0;
}

Zone::~Zone() {
}

TaskState Zone::run(core::Event e) {
	switch (e.type()) {
	case core::Timeout:
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
			}
		}
	}

	m_loaded = true;
}

void Zone::unload() {
	m_tiles.free();
	m_loaded = false;
}

common::Bounds Zone::bounds() {
	common::Bounds bnds;
	bnds.X = Tile::Width * m_address.X;
	bnds.Y = Tile::Height * m_address.Y;
	bnds.Width = Tile::Width * m_tiles.tilesWide();
	bnds.Height = Tile::Height * m_tiles.tilesHigh();
	return bnds;
}

void Zone::draw(core::Graphics &g, common::Bounds bnds, common::Point translation) {
	auto loc = common::Point(bounds().X, bounds().Y);
	for (int l = 0; l < m_tiles.layers(); l++) {
		for (int y = bnds.Y; y < bnds.y2(); y += Tile::Height) {
			for (int x = bnds.X; x < bnds.x2(); x += Tile::Width) {
				auto &tile = m_tiles.at(x / Tile::Width, y / Tile::Height, l);
				tile.draw(g, common::Point(x, y) + loc + translation);
			}
		}
	}
}

common::Point Zone::loc() {
	return common::Point(Tile::Width * m_address.X, Tile::Height * m_address.Y);
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

}
}
