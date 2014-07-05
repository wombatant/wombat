/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "_etc.hpp"
#include "zone.hpp"
#include "person.hpp"

namespace wombat {
namespace world {

using core::EventType;
using core::TaskState;

const std::function<void()> Person::c_defaultTimeoutProc = []() {};

Person::Person(models::Sprite model) {
	m_facing = (models::SpriteDirection) model.Facing;
	m_motion = (models::SpriteMotion) model.Motion;
	m_id = model.Id;

	models::Person person;
	core::read(person, model.Data);
	m_class = PersonClass::checkout(person.PersonClass);
	m_creatures = person.Creatures;
}

Person::~Person() {
	PersonClass::checkin(m_class);
}

TaskState Person::run(core::Event e) {
	TaskState retval = TaskState::Continue;

	switch ((int) e.type()) {
	case WorldEvent::MoveLeft:
		break;
	case WorldEvent::MoveUp:
		break;
	case WorldEvent::MoveDown:
		break;
	case WorldEvent::MoveRight:
		break;
	case EventType::FinishTask:
		retval = TaskState::Done;
		break;
	case EventType::Timeout:
		m_timeoutProc();
		break;
	}

	return retval;
}

void Person::draw(core::Graphics &gfx, common::Point pt) {
	m_class->draw(gfx, pt, m_facing, m_motion);
}

std::string Person::id() {
	return m_id;
}

void Person::setZone(Zone *zone) {
	m_zone = zone;
}

void Person::setAddress(common::Point pt) {
	m_addr = pt;
}

Zone *Person::getZone() {
	return m_zone;
}

common::Point Person::getAddress() {
	return m_addr;
}

common::Point Person::getWorldPoint() {
	return addrToPt(m_addr) + m_zone->bounds().pt1();
}

void Person::onZoneChange(std::function<void()> zc) {
	m_onZoneChange = zc;
}

}
}
