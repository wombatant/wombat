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
#include "_etc.hpp"
#include "tileclass.hpp"
#include "zone.hpp"

namespace wombat {
namespace world {

bool _debug = true;

int TileWidth = 32;
int TileHeight = 32;

std::map<core::TaskProcessor*, Zone*> m_zoneMap;

ZoneProcessor::ZoneProcessor(Zone *zone) {
	m_zone = zone;
}

Zone *ZoneProcessor::zone() {
	return m_zone;
}

common::Point addrToPt(common::Point addr) {
	addr.X *= TileWidth;
	addr.Y *= TileHeight;
	return addr;
}

common::Point ptToAddr(common::Point pt) {
	pt.X /= TileWidth;
	pt.Y /= TileHeight;
	return pt;
}

}
}
