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
#ifndef WOMBAT_WORLD_PERSONCLASS_HPP
#define WOMBAT_WORLD_PERSONCLASS_HPP

#include <core/core.hpp>
#include "animlayer.hpp"

namespace wombat {
namespace world {

class PersonClass: public core::Flyweight<models::PersonClass>::GenericValue {
	private:
		static core::Flyweight<models::PersonClass> c_personClasses;
		std::string m_name;
		std::vector<std::string> m_creatures;
		std::vector<std::vector<AnimLayer>> m_animations;

	public:
		/**
		 * Constructor
		 */
		PersonClass();

		/**
		 * Constructor
		 * @param model the model that the PersonClass will reflect
		 */
		PersonClass(models::PersonClass model);

		/**
		 * Checks out the PersonClass object from the given model.
		 * @param model model representing the desired PersonClass
		 */
		static PersonClass *checkout(models::PersonClass model);

		/**
		 * Checks out the PersonClass object stored at the given path.
		 * @param path path of the PersonClass to checkout
		 */
		static PersonClass *checkout(std::string path);

		/**
		 * Checks in the given PersonClass object.
		 * @param pc PersonClass object to checkin
		 */
		static void checkin(PersonClass *pc);
};

}
}

#endif
