/*
 * Copyright 2013-2015 gtalent2@gmail.com
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

// Mutex

Mutex::~Mutex() {
}

int Mutex::lock() {
	return 0;
}

int Mutex::unlock() {
	return 0;
}

// EventQueue

EventQueue::EventQueue() {
	m_semaphore = 0;
}

EventQueue::~EventQueue() {
}

Event EventQueue::wait() {
	Event post;
	while (1) {
		IntrWait(0, 0);
		if (popPost(post) == 0) {
			break;
		}
	}
	return post;
}

Event EventQueue::wait(uint64 timeout) {
	Event post;
	auto sleepEnd = _schedTime() + timeout;
	while (_schedTime() < sleepEnd) {
		IntrWait(0, 0);
		if (popPost(post) == 0) {
			break;
		}
	}
	return post;
}

void EventQueue::post(Event wakeup) {
	m_mutex.lock();
	m_posts.push(wakeup);
	m_mutex.unlock();
}

}
}
