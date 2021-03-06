/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include <stdio.h>
#include <string>
#include <functional>
#include <vector>
#include <chrono>
#include <time.h>
#include "_tls.hpp"
#include "task.hpp"

namespace wombat {
namespace core {

// used to track "event time"
time_t refTime;
bool _running = false;
static bool _debug = false;
std::string _language = "english";
TaskProcessor _taskProcessor;

void setLanguage(std::string lang) {
	_language = lang;
}

std::string getLanguage() {
	return _language;
}

bool running() {
	return _running;
}

void addTask(std::function<TaskState(Event)> task, TaskState state) {
	auto tp = activeTaskProcessor();
	if (tp == nullptr) {
		tp = &_taskProcessor;
	}
	tp->addTask(task, state);
}

void addTask(Task *task, TaskState state) {
	auto tp = activeTaskProcessor();
	if (tp == nullptr) {
		tp = &_taskProcessor;
	}
	tp->addTask(task, state);
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

void debugOn(bool debugOn) {
	_debug = debugOn;
}

bool debugOn() {
	return _debug;
}

void debug(std::string txt) {
	if (_debug) {
		printf("%s\n", txt.c_str());
	}
}

}
}
