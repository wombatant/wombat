/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include <stdlib.h>
#include <string.h>
#include "event.hpp"

namespace wombat {
namespace core {

// Event

Event::Event(EventType type) {
	m_type = type;
	m_copy = [this](void *dest, Event::Body src) {
		this->defaultCopy(dest, src);
	};
	m_free = [](void *dest) {};
	memset(&m_body, 0, sizeof(m_body));
}

Event::Event(EventType type, void *channel) {
	m_type = type;
	m_body.channel = channel;
	m_copy = [this](void *dest, Event::Body src) {
		this->defaultCopy(dest, src);
	};
	m_free = [](void *dest) {};
}

Event::Event(EventType type, Task *task) {
	m_type = type;
	m_task = task;
	m_copy = [this](void *dest, Event::Body src) {
		this->defaultCopy(dest, src);
	};
	m_free = [](void *dest) {};
}

Event::Event(const Event &event) {
	*this = event;
	m_copy(&m_body, event.m_body);
}

Event::~Event() {
	if (type() >= EventType::AppEvent) {
		m_free(m_body.other.data);
	}
}

void Event::setTask(class Task *task) {
	m_task = task;
}

void Event::setTaskPost(bool taskPost) {
	m_taskPost = taskPost;
}

bool Event::getTaskPost() {
	return m_taskPost;
}

void Event::defaultCopy(void *dest, union Event::Body src) {
	memcpy(dest, &src, sizeof(Event::Body));
}

}
}
