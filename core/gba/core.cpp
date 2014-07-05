/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include <vector>

#include <gba.h>

#include "../core.hpp"

namespace wombat {
namespace core {

extern SubscriptionManager _submgr;
extern std::vector<std::pair<Drawer*, Graphics*>> _drawers;
extern bool _running;
const uint64 _timer3Interval = 61040;
uint64 _time = 0;   // time in milliseconds
uint64 _timeMs = 0; // time in microseconds

EventQueue _mainEventQueue;

TaskProcessor _taskProcessor(&_mainEventQueue);

void addTask(std::function<TaskState(Event)> task, TaskState state) {
	_taskProcessor.addTask(task, state);
}

void addTask(Task *task, TaskState state) {
	_taskProcessor.addTask(task, state);
}

void draw() {
}

void _draw() {
	for (auto d : _drawers) {
		d.first->draw(*d.second);
		d.second->resetViewport();
	}
}

void _timer3Int() {
	_timeMs += _timer3Interval;
	_time = _timeMs / 1000;
	REG_IF = IRQ_TIMER3;
}

void main() {
	while (_running) {
		IntrWait(0, 0);
	}
}

int init(models::Settings settings) {
	irqInit();
	irqSet(IRQ_TIMER3, _timer3Int);
	irqEnable(IRQ_TIMER3);
	return 0;
}

}
}
