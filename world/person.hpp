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
#ifndef WOMBAT_WORLD_PERSON_HPP
#define WOMBAT_WORLD_PERSON_HPP

#include <core/core.hpp>
#include "personclass.hpp"
#include "sprite.hpp"

namespace wombat {
namespace world {

class Person: public Sprite, public core::Task {
	private:
		models::SpriteDirection m_facing = models::SpriteDirection::North;
		models::SpriteMotion m_motion = models::SpriteMotion::Still;
		PersonClass *m_class = nullptr;
		std::vector<std::string> m_creatures;
		std::function<void()> m_onZoneChange = []() {};
		std::string m_id;

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

		void draw(core::Graphics &gfx, common::Point pt);

		/**
		 * Sets the function when the Person goes to a different Zone.
		 * @param zc the function when the Person goes to a different Zone
		 */
		void onZoneChange(std::function<void()> zc);

		std::string id();
};

}
}

#endif
