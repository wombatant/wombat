/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "task.hpp"
#include "_submgr.hpp"

namespace wombat {
namespace core {

SubscriptionManager::SubscriptionManager(): m_subs((int) EventType::OptionalEventTypeRange) {
}

void SubscriptionManager::addSubscription(EventType et, Task *task) {
	m_subs[(int) et].push_back(task);
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
	for (auto t : m_subs[(int) e.type()]) {
		auto tp = dynamic_cast<TaskProcessor*>(t);
		if (tp) {
			tp->post(e);
		}
	}
}

void SubscriptionManager::run(Event e) {
	for (auto t : m_subs[(int) e.type()]) {
		t->run(e);
	}
}

int SubscriptionManager::subs(EventType et) {
	return m_subs[(int) et].size();
}

}
}
