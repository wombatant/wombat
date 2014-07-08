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

using core::Event;
using core::TaskState;
using models::SpriteMotion;

const std::function<void()> Person::c_defaultTimeoutProc = []() {};

Person::Person(models::Sprite model) {
	m_facing = (models::SpriteDirection) model.Facing;
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
	case StartMoving:
		{
			Motion flag;
			if (e.read(flag) == 0) {
				m_motion |= flag;
			}
		}
		break;
	case StopMoving:
		{
			Motion flag;
			if (e.read(flag) == 0) {
				m_motion |= ~flag;
			}
		}
		break;
	case Event::FinishTask:
		retval = TaskState::Done;
		break;
	case Event::Timeout:
		m_timeoutProc();
		break;
	}

	return retval;
}

void Person::draw(core::Graphics &gfx, common::Point pt) {
	auto motion = m_motion == Still ? SpriteMotion::Still : SpriteMotion::Walking;
	m_class->draw(gfx, pt, m_facing, motion);
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
