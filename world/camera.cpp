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
#include "camera.hpp"

namespace wombat {
namespace world {

Camera::Camera(World *world) {
	m_tlZone = m_trZone = m_blZone = m_brZone = 0;
	m_world = world;
}

void Camera::draw(core::Graphics &g) {
	findZones();

	const auto cbnds = bounds();
	const auto cloc = common::Point(cbnds.X, cbnds.Y) * -1;
	for (auto z : m_zones) {
		auto bnds = z->bounds();
		if (bnds.X > cbnds.X) {
			bnds.X = cbnds.X;
		}
		if (bnds.Y > cbnds.Y) {
			bnds.Y = cbnds.Y;
		}
		if (bnds.x2() > cbnds.x2()) {
			bnds.Width = cbnds.x2() - bnds.X;
		}
		if (bnds.y2() > cbnds.y2()) {
			bnds.Height = cbnds.y2() - bnds.Y;
		}

		z->draw(g, bnds, cloc);
	}
}

common::Bounds Camera::bounds() {
	return m_bounds;
}

void Camera::findZones() {
	bool updateZones = !(m_tlZone && m_trZone && m_blZone && m_brZone) ||
		!(m_tlZone->bounds().contains(m_bounds.X, m_bounds.Y) &&
		m_tlZone->bounds().contains(m_bounds.X, m_bounds.y2()) &&
		m_tlZone->bounds().contains(m_bounds.x2(), m_bounds.Y) &&
		m_tlZone->bounds().contains(m_bounds.x2(), m_bounds.y2()));

	if (updateZones) {
		auto newZones = m_world->zonesAt(m_bounds);
		for (auto z : newZones) {
			z->incDeps();
		}
		for (auto z : m_zones) {
			z->decDeps();
		}
		m_zones = newZones;

		m_tlZone = m_world->zoneAt(m_bounds.X, m_bounds.Y);
		m_trZone = m_world->zoneAt(m_bounds.x2(), m_bounds.Y);
		m_blZone = m_world->zoneAt(m_bounds.X, m_bounds.y2());
		m_brZone = m_world->zoneAt(m_bounds.x2(), m_bounds.y2());
	}
}

}
}
