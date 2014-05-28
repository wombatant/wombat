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
