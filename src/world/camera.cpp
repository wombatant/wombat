/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "_etc.hpp"
#include "camera.hpp"

namespace wombat {
namespace world {

using common::Bounds;
using common::Point;
using core::Event;
using core::Key;
using core::TaskState;

Camera::Camera(World *world) {
	m_world = world;
	setAutoDelete(true);
}

void Camera::init() {
	updateSize();
	core::subscribe(Event::ScreenSizeChange);
	core::subscribe(Event::KeyDown);
	core::subscribe(Event::KeyUp);
}

TaskState Camera::run(Event e) {
	TaskState retval = TaskState::Continue;

	switch (e.type()) {
	case Event::ScreenSizeChange:
		updateSize();
		break;
	case Event::KeyDown:
	case Event::KeyUp:
		keyEvent(e);
		break;
	default:
		break;
	}

	return retval;
}

void Camera::draw(core::Graphics &g) {
	Point translation;
	std::pair<Sprite*, common::Point> focus;
	if (m_person) {
		auto dispSize = Point(core::displayWidth(), core::displayHeight());
		auto loc = (m_person->getWorldPoint() - (dispSize / 2));
		// always keep the focus sprite centered
		auto focusPt = dispSize / 2 - common::Point(TileWidth, TileHeight) / 2;
		loc += Point(TileWidth, TileHeight) / 2;
		m_bounds.X = loc.X;
		m_bounds.Y = loc.Y;
		translation = loc * -1;
		focus = std::pair<Sprite*, common::Point>(m_person, focusPt);
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

		z->draw(g, bnds, translation, focus);
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

void Camera::keyEvent(Event e) {
	if (m_person) {
		auto type = e.type();
		if (type == Event::KeyDown || type == Event::KeyUp) {
			Person::Motion motion;
			switch (e.key()) {
			case Key::H:
				motion = Person::MovingLeft;
				break;
			case Key::J:
				motion = Person::MovingDown;
				break;
			case Key::K:
				motion = Person::MovingUp;
				break;
			case Key::L:
				motion = Person::MovingRight;
				break;
			default:
				motion = Person::Still;
				break;
			}
			m_person->post(Event(type == Event::KeyDown ? StartMoving : StopMoving, motion));
		}
	}
}

}
}
