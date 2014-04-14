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
#include "core.hpp"

namespace wombat {
namespace core {

std::vector<std::function<void(Event)>> eventListeners;
std::string home = "wombat_home/";

// used to track "event time"
time_t refTime;
bool vrunning = false;

bool running() {
	return vrunning;
}

void quit() {
	vrunning = false;
}

void _updateEventTime() {
	auto t = std::chrono::system_clock::now().time_since_epoch();
	refTime = std::chrono::duration_cast<std::chrono::milliseconds>(t).count();
}

time_t eventTime() {
	return refTime;
}

time_t time() {
	auto t = std::chrono::system_clock::now().time_since_epoch();
	return std::chrono::duration_cast<std::chrono::milliseconds>(t).count();
}

std::string getHome() {
	return home;
}

int open(models::cyborgbear::Model &m, std::string path) {
	if (path.substr(path.size() - 5) != ".json") {
		path += ".json";
	}
	m.readJsonFile(core::path(path));
}

std::string path(std::string path) {
	return home + path;
}

void setHome(std::string h) {
	home = h + "/";
}

void addEventListener(std::function<void(Event)> el) {
	eventListeners.push_back(el);
}

void debug(std::string txt) {
	printf("%s\n", txt.c_str());
}

}
}
