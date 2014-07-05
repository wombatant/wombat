/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include <gba.h>
#include "../_misc.hpp"
#include "../core.hpp"

namespace wombat {
namespace core {

void startThread(std::function<void()>) {
	// not supported
}

void sleep(uint64 ms) {
	auto sleepEnd = _schedTime() + ms;
	while (_schedTime() < sleepEnd) {
		IntrWait(0, 0);
	}
}

}
}
