/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_WORLD_PERSON_HPP
#define WOMBAT_WORLD_PERSON_HPP

#include <core/core.hpp>
#include "_etc.hpp"
#include "event.hpp"
#include "personclass.hpp"
#include "sprite.hpp"

namespace wombat {
namespace world {

class Person: public Sprite, public core::Task {
	public:
		enum Motion {
			Still       = 0,
			MovingUp    = 1,
			MovingDown  = 2,
			MovingLeft  = 4,
			MovingRight = 8
		};

	private:
		typedef std::function<core::TaskState(Person *me)> TimeoutProc;
		typedef std::function<void()> ZoneChangeProc;

		static const TimeoutProc c_defaultTimeoutProc;
		static const TimeoutProc c_timeoutMoveUp;
		static const TimeoutProc c_timeoutMoveDown;
		static const TimeoutProc c_timeoutMoveLeft;
		static const TimeoutProc c_timeoutMoveRight;
		static const uint64_t c_timeoutInterval;

		models::SpriteDirection m_facing = models::SpriteDirection::North;
		models::Person m_model; // model representing this person
		PersonClass *m_class = nullptr;
		class Zone *m_zone = nullptr;
		ZoneChangeProc m_onZoneChange = []() {};
		TimeoutProc m_timeoutProc = c_defaultTimeoutProc;
		std::string m_id;
		common::Point m_pt;
		common::Point m_ptOffset;
		int m_layer = 0;
		int m_motion = Still;
		models::WorldAbilityFlags m_abilities = models::WorldAbilityFlags::None;

	public:
		/**
		 * Constructor
		 * @param path path to the Person model
		 */
		Person(models::Sprite model);

		/**
		 * Destructor
		 */
		~Person();

		core::TaskState run(core::Event) override;

		void draw(core::Graphics &gfx, common::Point pt) override;

		std::string id() override;

		void setZone(class Zone *zone) override;

		void setAddress(common::Point addr) override;

		/**
		 * Gets the Zone of this Person.
		 * @return the Zone of this Person
		 */
		Zone *getZone();

		/**
		 * Gets the address of this Person within its Zone.
		 * @return the address of this Person within its Zone
		 */
		common::Point getAddress();

		/**
		 * Gets the location of point of this Person in the world.
		 * @return the location of point of this Person in the world
		 */
		common::Point getWorldPoint();

		/**
		 * Sets the function when the Person goes to a different Zone.
		 * @param zc the function when the Person goes to a different Zone
		 */
		void onZoneChange(ZoneChangeProc zc);

		/**
		 * Returns whether or not this Person has the specified ability.
		 * @param ability the ability capability being queried
		 * @return whether or not this Person has the specified ability
		 */
		bool hasAbility(models::WorldAbilityFlags ability);

	private:
		/**
		 * Fills out this Person's abilities according the abilities of the creatures in its party.
		 */
		void generateAbilities(models::Person);

		bool canTraverse(models::TerrainType);

		Error startMoving(TimeoutProc proc, common::Point oldAddr, common::Point newAddr);

		core::TaskState updateTimeoutProc();

		core::TaskState moveIn(int &operand, int goal);

		core::TaskState moveOut(int &operand, int goal);
};

}
}

#endif
