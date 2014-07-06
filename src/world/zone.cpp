/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "_etc.hpp"
#include "zone.hpp"

namespace wombat {
namespace world {

using common::Point;
using common::Bounds;
using core::Event;
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
		m_tiles = nullptr;
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
	m_taskProcessor->addTask(this);
	m_taskProcessor->start();
}

Zone::~Zone() {
	m_taskProcessor->stop();
	m_taskProcessor->done();
	delete m_taskProcessor;
}

TaskState Zone::run(core::Event e) {
	switch (e.type()) {
	case Event::Timeout:
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

Bounds Zone::bounds() {
	Bounds bnds;
	bnds.X = TileWidth * m_address.X;
	bnds.Y = TileHeight * m_address.Y;
	bnds.Width = TileWidth * m_tiles.tilesWide();
	bnds.Height = TileHeight * m_tiles.tilesHigh();
	return bnds;
}

void Zone::draw(core::Graphics &g, Bounds bnds, Point translation) {
	auto loc = addrToPt(bounds().pt1()) + translation;

	for (auto l = 0; l < m_tiles.layers(); l++) {
		for (auto y = bnds.Y; y < bnds.y2(); y += TileHeight) {
			for (auto x = bnds.X; x < bnds.x2(); x += TileWidth) {
				auto &tile = m_tiles.at(x / TileWidth, y / TileHeight, l);
				tile.draw(g, addrToPt(ptToAddr(Point(x, y))) + loc);
			}
		}
	}
}

Point Zone::loc() {
	return Point(TileWidth * m_address.X, TileHeight * m_address.Y);
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
	sprite->setZone(this);
	if (sprite->id() != "") {
		m_sprites[sprite->id()] = sprite;
	}

	auto task = dynamic_cast<Task*>(sprite);
	if (task) {
		task->post(Event::FinishTask);
		m_taskProcessor->addTask(task);
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
				if (oc) {
					oc->setAddress(Point(x, y));
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
