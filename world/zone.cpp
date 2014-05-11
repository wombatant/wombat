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
	m_width = m_height = m_layers = 0;
}

Zone::TileGrid::~TileGrid() {
	if (m_tiles) {
		for (int l = 0; l < m_layers; l++) {
			for (int y = 0; y < m_height; y++) {
				delete m_tiles[l][y];
			}
			delete m_tiles[l];
		}
		delete m_tiles;
	}
}

void Zone::TileGrid::allocate(int w, int h, int layers) {
	m_width = w;
	m_height = h;
	m_layers = layers;

	m_tiles = new TileInstance**[layers];
	for (int l = 0; l < layers; l++) {
		m_tiles[l] = new TileInstance*[h];
		for (int y = 0; y < h; y++) {
			m_tiles[l][y] = new TileInstance[w];
		}
	}
}

Zone::Zone() {
}

Zone::~Zone() {
}

core::TaskState Zone::run(core::Event) {
	return core::TaskState::Continue;
}

bool Zone::loaded() {
	return m_loaded;
}

}
}
