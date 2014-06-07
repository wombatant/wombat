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
#include "worldobject.hpp"

namespace wombat {
namespace world {

class Person: public WorldObject {
	private:
		PersonClass *m_class;

	public:
		/**
		 * Constructor
		 */
		Person();

		/**
		 * Constructor
		 * @param path path to the Person model
		 */
		Person(std::string path);

		/**
		 * Destructor
		 */
		~Person();
};

}
}

#endif
