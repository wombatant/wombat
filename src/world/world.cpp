/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "world.hpp"

namespace wombat {
namespace world {

bool _debugMode = true;

World::World(models::World world) {
	m_taskProc.start();
	m_taskProc.addTask(this);

	for (auto z : world.Zones) {
		auto zone = new Zone(z);
		m_zones[z.AccessorID] = zone;
		m_taskProc.addTask(zone);
	}
}

World::~World() {
	m_taskProc.stop();
	m_taskProc.done();
}

core::TaskState World::run(core::Event) {
	return core::TaskState::Continue;
}

Zone *World::getZone(std::string accessorId) {
	return m_zones[accessorId];
}

void World::zonesAt(std::vector<Zone*> &zones, common::Bounds bnds) {
	zones.erase(zones.begin(), zones.end());
	for (auto z : m_zones) {
		if (z.second && z.second->bounds().intersects(bnds)) {
			zones.push_back(z.second);
		}
	}
}

Zone *World::zoneAt(int x, int y) {
	for (auto z : m_zones) {
		if (z.second->bounds().contains(x, y)) {
			return z.second;
		}
	}
	return nullptr;
}

}
}
