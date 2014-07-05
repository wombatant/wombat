/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include <core/core.hpp>

namespace wombat {
namespace world {

extern bool _debug;

extern int TileWidth;
extern int TileHeight;

extern std::map<core::TaskProcessor*, class Zone*> m_zoneMap;

class ZoneProcessor: public core::TaskProcessor {
	private:
		Zone *m_zone = nullptr;

	public:
		/**
		 * Constructor
		 * @param zone the Zone that owns this ZoneProcessor
		 */
		ZoneProcessor(class Zone *zone);

		/**
		 * Gets the Zone that owns this ZoneProcessor.
		 * @return the Zone that owns this ZoneProcessor
		 */
		class Zone *zone();
};

common::Point addrToPt(common::Point);

common::Point ptToAddr(common::Point);

}
}
