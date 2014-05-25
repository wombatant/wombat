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
#ifdef WITH_SDL

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

#endif
