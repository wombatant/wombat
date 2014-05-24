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

using core::TaskState;

Camera::Camera(World *world) {
	m_world = world;
	setAutoDelete(true);
	core::addTask(this);
}

void Camera::init() {
	updateSize();
	core::subscribe(core::ScreenSizeChange);
}

TaskState Camera::run(core::Event e) {
	TaskState retval = TaskState::Continue;

	switch (e.type()) {
	case core::ScreenSizeChange:
		updateSize();
		break;
	default:
		break;
	}

	return retval;
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
	for (auto z : m_zones) {
		z->decDeps();
	}
	m_world->zonesAt(m_zones, m_bounds);
	for (auto z : m_zones) {
		z->incDeps();
	}
}

void Camera::updateSize() {
	m_bounds.Width = core::displayWidth();
	m_bounds.Height = core::displayHeight();
}

}
}
