/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <SDL.h>
#include "../core.hpp"

namespace wombat {
namespace core {

void startThread(std::function<void()> f) {
	static int threadCount = 0;

	char thrdNm[10];
	snprintf(thrdNm, 10, "Thread %d", threadCount);


	auto fp = new std::function<void()>(f);
	auto thread = SDL_CreateThread([](void *func) -> int {
		if (func) {
			auto f = (std::function<void()>*) func;
			(*f)();
			delete f;
		}
		return 0;
	}, thrdNm, (void*) fp);
	SDL_DetachThread(thread);

	threadCount++;
}

void sleep(uint64 ms) {
	SDL_Delay(ms);
}

}
}
