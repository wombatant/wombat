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
using models::TerrainType;
using models::WorldAbilityFlags;

const Person::TimeoutProc Person::c_defaultTimeoutProc = [](Person *me) {
	return me->updateTimeoutProc();
};

const Person::TimeoutProc Person::c_timeoutMoveUp = [](Person *me) {
	return me->moveIn(me->m_ptOffset.Y, 0);
};

const Person::TimeoutProc Person::c_timeoutMoveDown = [](Person *me) {
	return me->moveOut(me->m_ptOffset.Y, 0);
};

const Person::TimeoutProc Person::c_timeoutMoveLeft = [](Person *me) {
	return me->moveIn(me->m_ptOffset.X, 0);
};

const Person::TimeoutProc Person::c_timeoutMoveRight = [](Person *me) {
	return me->moveOut(me->m_ptOffset.X, 0);
};

const uint64_t Person::c_timeoutInterval = 8;

Person::Person(models::Sprite model) {
	m_facing = (models::SpriteDirection) model.Facing;
	m_id = model.Id;

	models::Person person;
	core::read(person, model.Data);
	m_class = PersonClass::checkout(person.PersonClass);
	generateAbilities(person);
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
				m_motion ^= flag;
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

void Person::draw(Tile *tile, common::Point pt) {
	auto motion = m_motion == Still ? SpriteMotion::Still : SpriteMotion::Walking;
	m_class->draw(pt, tile->terrainType(), m_facing, motion);
}

std::string Person::id() {
	return m_id;
}

void Person::setZone(Zone *zone) {
	m_zone = zone;
}

void Person::setAddress(common::Point addr) {
	m_pt = pt(addr);
}

Zone *Person::getZone() {
	return m_zone;
}

common::Point Person::getAddress() {
	return addr(m_pt);
}

common::Point Person::getWorldPoint() {
	return m_pt + m_ptOffset + m_zone->bounds().pt1();
}

void Person::onZoneChange(Person::ZoneChangeProc zc) {
	m_onZoneChange = zc;
}

bool Person::hasAbility(WorldAbilityFlags ability) {
	return ((int) ability) & ((int) m_abilities);
}

void Person::generateAbilities(models::Person person) {
	m_abilities = WorldAbilityFlags::None;

	for (auto path : person.Creatures) {
		models::Creature c;
		core::read(c, path);

		for (auto mi : c.Moves) {
			models::CreatureMove cm;
			core::read(cm, mi.CreatureMove);
			m_abilities = (WorldAbilityFlags) (((int) m_abilities) | ((int) cm.WorldAbilityFlags));
		}
	}
}

bool Person::canTraverse(TerrainType type) {
	switch (type) {
	case TerrainType::Land:
		return true;
	case TerrainType::Water:
		return hasAbility(WorldAbilityFlags::Swim);
	case TerrainType::Waterfall:
		return hasAbility(WorldAbilityFlags::Waterfall);
	case TerrainType::Whirlpool:
		return hasAbility(WorldAbilityFlags::Whirlpool);
	}
	return false;
}

Error Person::startMoving(TimeoutProc proc, common::Point addr, common::Point newAddr) {
	auto tile = m_zone->getTile(newAddr.X, newAddr.Y, m_layer);
	if (tile && canTraverse(tile->terrainType()) && tile->claim(this) == 0) {
		auto oldTile = m_zone->getTile(addr.X, addr.Y, m_layer);
		if (oldTile) {
			oldTile->release();
		}

		m_timeoutProc = proc;
		m_pt = pt(newAddr);
		return 0;
	}
	return 1;
}

TaskState Person::updateTimeoutProc() {
	auto newAddr = getAddress();
	auto ptOffset = m_ptOffset;
	auto timeoutProc = m_timeoutProc;
	TaskState retval = TaskState::Continue;
	if (m_motion == Still) {
		m_timeoutProc = c_defaultTimeoutProc;
	} else {
		if (m_motion & MovingUp) {
			newAddr.Y--;
			ptOffset.Y += TileHeight;
			timeoutProc = c_timeoutMoveUp;
		} else if (m_motion & MovingDown) {
			newAddr.Y++;
			ptOffset.Y -= TileHeight;
			timeoutProc = c_timeoutMoveDown;
		} else if (m_motion & MovingLeft) {
			newAddr.X--;
			ptOffset.X += TileWidth;
			timeoutProc = c_timeoutMoveLeft;
		} else if (m_motion & MovingRight) {
			newAddr.X++;
			ptOffset.X -= TileWidth;
			timeoutProc = c_timeoutMoveRight;
		}

		if (startMoving(m_timeoutProc, getAddress(), newAddr) == 0) {
			m_timeoutProc = timeoutProc;
			m_ptOffset = ptOffset;
			retval = c_timeoutInterval;
		}
	}
	return retval;
}

TaskState Person::moveIn(int &operand, int goal) {
	operand -= 1;
	if (operand <= goal) {
		operand = goal;
		updateTimeoutProc();
	}
	return c_timeoutInterval;
}

TaskState Person::moveOut(int &operand, int goal) {
	operand += 1;
	if (operand >= goal) {
		operand = goal;
		updateTimeoutProc();
	}
	return c_timeoutInterval;
}

}
}
