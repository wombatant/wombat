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
#include "camera.hpp"

namespace wombat {
namespace world {

using common::Bounds;
using common::Point;
using core::Event;
using core::EventType;
using core::Key;
using core::TaskState;

Camera::Camera(World *world) {
	m_world = world;
	setAutoDelete(true);
	core::addTask(this);
}

void Camera::init() {
	updateSize();
	core::subscribe(EventType::ScreenSizeChange);
	core::subscribe(EventType::KeyDown);
	core::subscribe(EventType::KeyUp);
}

TaskState Camera::run(Event e) {
	TaskState retval = TaskState::Continue;

	switch (e.type()) {
	case EventType::ScreenSizeChange:
		updateSize();
		break;
	case EventType::KeyDown:
		keyDown(e);
		break;
	case EventType::KeyUp:
		keyUp(e);
		break;
	default:
		break;
	}

	return retval;
}

void Camera::draw(core::Graphics &g) {
	Point translation;
	if (m_person) {
		auto dispSize = Point(core::displayWidth(), core::displayHeight());
		auto loc = (m_person->getWorldPoint() - (dispSize / 2));
		loc += Point(TileWidth, TileHeight) / 2;
		m_bounds.X = loc.X;
		m_bounds.Y = loc.Y;
		translation = loc * -1;
	}

	findZones();

	auto cbnds = bounds();
	cbnds.Width += TileWidth;
	cbnds.Height += TileHeight;
	for (auto z : m_zones) {
		auto bnds = cbnds;
		auto zbnds = z->bounds();
		if (bnds.X < zbnds.X) {
			bnds.X = zbnds.X;
		}
		if (bnds.Y < zbnds.Y) {
			bnds.Y = zbnds.Y;
		}
		if (bnds.x2() > zbnds.x2()) {
			bnds.Width = zbnds.x2() - bnds.X;
		}
		if (bnds.y2() > zbnds.y2()) {
			bnds.Height = zbnds.y2() - bnds.Y;
		}

		z->draw(g, bnds, translation);
	}
}

Bounds Camera::bounds() {
	return m_bounds;
}

void Camera::init(models::InitFile init) {
	auto z = m_world->getZone(init.ZoneId);
	if (z) {
		z->incDeps();
		auto person = dynamic_cast<Person*>(z->getSprite(init.SpriteId));
		if (person) {
			person->onZoneChange([z]() {
				z->decDeps();
			});
			m_person = person;
		}
	}
}

void Camera::findZones() {
	for (auto z : m_zones) {
		z->decDeps();
	}
	if (m_world) {
		m_world->zonesAt(m_zones, m_bounds);
		for (auto z : m_zones) {
			z->incDeps();
		}
	}
}

void Camera::updateSize() {
	m_bounds.Width = core::displayWidth();
	m_bounds.Height = core::displayHeight();
}

void Camera::keyDown(Event e) {
	if (m_person) {
		switch (e.key()) {
		case Key::H:
			m_person->post((EventType) WorldEvent::MoveLeft);
			break;
		case Key::J:
			m_person->post((EventType) WorldEvent::MoveDown);
			break;
		case Key::K:
			m_person->post((EventType) WorldEvent::MoveUp);
			break;
		case Key::L:
			m_person->post((EventType) WorldEvent::MoveRight);
			break;
		default:
			break;
		}
	}
}

void Camera::keyUp(Event e) {
}

}
}
