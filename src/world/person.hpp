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
		static const std::function<void()> c_defaultTimeoutProc;
		models::SpriteDirection m_facing = models::SpriteDirection::North;
		PersonClass *m_class = nullptr;
		class Zone *m_zone = nullptr;
		std::vector<std::string> m_creatures;
		std::function<void()> m_onZoneChange = []() {};
		std::function<void()> m_timeoutProc = c_defaultTimeoutProc;
		std::string m_id;
		common::Point m_addr;
		int m_motion = Still;

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

		void setAddress(common::Point pt) override;

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
		void onZoneChange(std::function<void()> zc);
};

}
}

#endif
