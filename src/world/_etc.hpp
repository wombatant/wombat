/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_WORLD__ETC_HPP
#define WOMBAT_WORLD__ETC_HPP

#include <common/point.hpp>
#include <core/task.hpp>

namespace wombat {
namespace world {

extern bool _debug;

extern const int TileWidth;
extern const int TileHeight;

extern std::map<core::TaskProcessor*, class Zone*> m_zoneMap;

typedef core::uint64 Error;

class ZoneProcessor: public core::TaskProcessor {
	private:
		class Zone *m_zone = nullptr;

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

inline common::Point addr(common::Point pt) {
	pt.X /= TileWidth;
	pt.Y /= TileHeight;
	return pt;
}

inline common::Point pt(common::Point addr) {
	addr.X *= TileWidth;
	addr.Y *= TileHeight;
	return addr;
}

}
}

#endif
