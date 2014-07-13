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

const Person::TimeoutProc Person::c_defaultTimeoutProc = [](Person *me) {
	return me->updateTimeoutProc();
};

const Person::TimeoutProc Person::c_timeoutMoveUp = [](Person *me) {
	return me->moveIn(me->m_ptOffset.Y, pt(me->m_addr).Y - TileHeight);
};

const Person::TimeoutProc Person::c_timeoutMoveDown = [](Person *me) {
	return me->moveOut(me->m_ptOffset.Y, pt(me->m_addr).Y + TileHeight);
};

const Person::TimeoutProc Person::c_timeoutMoveLeft = [](Person *me) {
	return me->moveIn(me->m_ptOffset.X, pt(me->m_addr).X - TileWidth);
};

const Person::TimeoutProc Person::c_timeoutMoveRight = [](Person *me) {
	return me->moveOut(me->m_ptOffset.X, pt(me->m_addr).X + TileWidth);
};

const core::uint64 Person::c_timeoutInterval = 100;

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

TaskState Person::run(Event e) {
	TaskState retval = TaskState::Continue;

	switch ((int) e.type()) {
	case StartMoving:
		{
			Motion flag;
			if (e.read(flag) == 0) {
				bool alreadyMoving = m_motion != Still;
				m_motion |= flag;
				if (m_motion != Person::Still && !alreadyMoving) {
					retval = 0;
				}
			}
		}
		break;
	case StopMoving:
		{
			Motion flag;
			if (e.read(flag) == 0) {
				m_motion &= ~flag;
			}
		}
		break;
	case Event::FinishTask:
		retval = TaskState::Done;
		break;
	case Event::Timeout:
		retval = m_timeoutProc(this);
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
	return pt(m_addr) + m_zone->bounds().pt1();
}

void Person::onZoneChange(Person::ZoneChangeProc zc) {
	m_onZoneChange = zc;
}

Error Person::startMoving(TimeoutProc proc, common::Point addr) {
	auto tile = m_zone->getTile(addr.X, addr.Y, m_layer);
	if (tile && tile->claim(this) == 0) {
		m_timeoutProc = proc;
		m_addr = addr;
		return 0;
	}
	return 1;
}

TaskState Person::updateTimeoutProc() {
	auto addr = m_addr;
	auto timeoutProc = m_timeoutProc;
	TaskState retval = TaskState::Continue;
	if (m_motion == Still) {
		m_timeoutProc = c_defaultTimeoutProc;
	} else {
		if (m_motion & MovingUp) {
			timeoutProc = c_timeoutMoveUp;
			addr.Y--;
		} else if (m_motion & MovingDown) {
			timeoutProc = c_timeoutMoveDown;
			addr.Y++;
		} else if (m_motion & MovingLeft) {
			timeoutProc = c_timeoutMoveLeft;
			addr.X--;
		} else if (m_motion & MovingRight) {
			timeoutProc = c_timeoutMoveRight;
			addr.X++;
		}

		if (startMoving(m_timeoutProc, addr) == 0) {
			retval = c_timeoutInterval;
		}
	}
	return retval;
}

TaskState Person::moveIn(int &operand, int goal) {
	operand -= 2;
	if (operand < goal) {
		operand = goal;
		updateTimeoutProc();
	}
	return c_timeoutInterval;
}

TaskState Person::moveOut(int &operand, int goal) {
	operand += 2;
	if (operand > goal) {
		operand = goal;
		updateTimeoutProc();
	}
	return c_timeoutInterval;
}

}
}
