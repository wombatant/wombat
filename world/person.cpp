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
#include "zone.hpp"
#include "person.hpp"

namespace wombat {
namespace world {

using core::TaskState;

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

TaskState Person::run(core::Event) {
	return TaskState::Continue;
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
