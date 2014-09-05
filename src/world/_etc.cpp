/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "_etc.hpp"
#include "tileclass.hpp"
#include "zone.hpp"

namespace wombat {
namespace world {

bool _debug = false;

int TileWidth = 32;
int TileHeight = 32;

std::map<core::TaskProcessor*, Zone*> m_zoneMap;

ZoneProcessor::ZoneProcessor(Zone *zone) {
	m_zone = zone;
}

Zone *ZoneProcessor::zone() {
	return m_zone;
}

}
}
