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

const Event::Copier Event::DefaultCopy = [](Event *me, Body *dest, Event::Body src) {
	defaultCopy(dest, src);
};

const std::function<void(void*)> Event::DefaultFree = [](void*) {};

Event::Event(Event::Type type) {
	m_type = type;
	memset(&m_body, 0, sizeof(m_body));
}

Event::Event(int type, void *channel) {
	m_type = (Event::Type) type;
	m_body.channel = channel;
}

Event::Event(int type, Task *task) {
	m_type = (Event::Type) type;
	m_task = task;
}

Event::Event(const Event &src) {
	*this = src;
}

Event::~Event() {
	if (type() >= Event::AppEvent) {
		if (m_body.other.data != nullptr) {
			m_free(m_body.other.data);
		}
	}
}

Event &Event::operator=(const Event &src) {
	m_type = src.m_type;
	m_taskPost = src.m_taskPost;
	m_task = src.m_task;
	m_copy = src.m_copy;
	m_free = src.m_free;
	m_copy(this, &m_body, src.m_body);
	return *this;
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

void Event::defaultCopy(void *dest, Event::Body &src) {
	memcpy(dest, &src, sizeof(Event::Body));
}

}
}
