/*
 * Copyright 2013-2015 gtalent2@gmail.com
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

Event::Event(int type, int32_t integer) {
	m_type = (Event::Type) type;
	m_body.integer32 = integer;
}

Event::Event(const Event &src) {
	*this = src;
}

Event::~Event() {
}

int Event::read(int32_t *integer) {
	if (integer) {
		*integer = m_body.integer32;
		return 0;
	} else {
		return 1;
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

}
}
