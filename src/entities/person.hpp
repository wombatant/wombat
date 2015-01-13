/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_ENTITIES_PERSON_HPP
#define WOMBAT_ENTITIES_PERSON_HPP

#include <string>
#include <vector>
#include "creature.hpp"

namespace wombat {
namespace entities {

class Person {
	private:
		std::vector<Creature*> m_creatures;

	public:
		std::string name();
		void name(std::string name);

		std::vector<Creature*> creatures();
		void creatures(std::vector<Creature*> creatures);
};

}
}

#endif
