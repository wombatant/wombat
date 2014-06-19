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
	return 0;
}

}
}
