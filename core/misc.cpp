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
#include <stdio.h>
#include <string>
#include <functional>
#include <vector>
#include <chrono>
#include <time.h>
#include "event.hpp"
#include "misc.hpp"

namespace wombat {
namespace core {

// used to track "event time"
time_t refTime;
bool _running = false;

bool running() {
	return _running;
}

void quit() {
	_running = false;
}

void _updateEventTime() {
	refTime = time();
}

uint64 eventTime() {
	return refTime;
}

uint64 time() {
	auto t = std::chrono::system_clock::now().time_since_epoch();
	return std::chrono::duration_cast<std::chrono::milliseconds>(t).count();
}

void debug(std::string txt) {
	printf("%s\n", txt.c_str());
}

}
}
