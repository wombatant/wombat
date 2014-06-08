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
#include <vector>
#include <stdlib.h>
#include "event.hpp"

namespace wombat {
namespace core {

// Event

Event::Event(EventType type) {
	m_type = type;
	memset(&m_body, 0, sizeof(m_body));
}

Event::Event(EventType type, void *channel) {
	m_type = type;
	m_body.channel = channel;
}

Event::Event(EventType type, Task *task) {
	m_type = type;
	m_body.task = task;
}

Event::~Event() {
	if (type() >= AppEvent) {
		free(m_body.other.data);
	}
}

}
}
