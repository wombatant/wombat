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
#include "task.hpp"
#include "_submgr.hpp"

namespace wombat {
namespace core {

SubscriptionManager::SubscriptionManager(): m_subs(OptionalEventTypeRange) {
}

void SubscriptionManager::addSubscription(EventType et, Task *task) {
	m_subs[et].push_back(task);
}

void SubscriptionManager::removeFromAllSubs(Task *task) {
	// yes, this is inefficient, but I'll fix it later if it's really a problem
	for (auto l : m_subs) {
		auto begin = l.begin();
		for (uint i = 0; i < l.size(); i++) {
			if (task == l[i]) {
				l.erase(begin + i);
				break;
			}
		}
	}
}

void SubscriptionManager::post(Event e) {
	for (auto t : m_subs[e.type()]) {
		auto tp = dynamic_cast<TaskProcessor*>(t);
		if (tp) {
			tp->post(e);
		}
	}
}

void SubscriptionManager::run(Event e) {
	for (auto t : m_subs[e.type()]) {
		t->run(e);
	}
}

int SubscriptionManager::subs(EventType et) {
	return m_subs[et].size();
}

}
}
