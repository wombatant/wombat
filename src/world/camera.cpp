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
		keyDown(e);
		break;
	case Event::KeyUp:
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
			m_person->post((Event::Type) WorldEvent::MoveLeft);
			break;
		case Key::J:
			m_person->post((Event::Type) WorldEvent::MoveDown);
			break;
		case Key::K:
			m_person->post((Event::Type) WorldEvent::MoveUp);
			break;
		case Key::L:
			m_person->post((Event::Type) WorldEvent::MoveRight);
			break;
		default:
			break;
		}
	}
}

void Camera::keyUp(Event e) {
	if (m_person) {
		switch (e.key()) {
		case Key::H:
			m_person->post((Event::Type) WorldEvent::MoveLeft);
			break;
		case Key::J:
			m_person->post((Event::Type) WorldEvent::MoveDown);
			break;
		case Key::K:
			m_person->post((Event::Type) WorldEvent::MoveUp);
			break;
		case Key::L:
			m_person->post((Event::Type) WorldEvent::MoveRight);
			break;
		default:
			break;
		}
	}
}

}
}
