/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "person.hpp"

namespace wombat {
namespace entities {

std::string Person::name() {
	return "";
}

void Person::name(std::string name) {
}

std::vector<Creature*> Person::creatures() {
	return m_creatures;
}

void Person::creatures(std::vector<Creature*> creatures) {
	m_creatures = creatures;
}

}
}
