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
#ifndef WOMBAT_CORE__SUBMGR_HPP
#define WOMBAT_CORE__SUBMGR_HPP

#include <vector>
#include "event.hpp"

namespace wombat {
namespace core {

class Task;

class SubscriptionManager {
	private:
		std::vector<std::vector<Task*>> m_subs;

	public:
		/**
		 * Constructor
		 */
		SubscriptionManager();

		/**
		 * Adds the given Task to the subscription list of the given EventType.
		 * @param et the EventType that the Task is subscribing to
		 * @param task the Task to add to the subscription list
		 */
		void addSubscription(EventType et, Task *task);

		/**
		 * Removes the given Task from all subscription lists.
		 * @param task the Task that is unsubscribing from everything
		 */
		void removeFromAllSubs(Task *task);

		/**
		 * Calls post on the given Event for all TaskProcessors subscribed to
		 * the Event's EventType.
		 * @param event the Event to publish
		 */
		void post(Event event);

		/**
		 * Calls run on the given Event for all subscribers to the Event's EventType.
		 * @param event the Event to publish
		 */
		void run(Event event);

		/**
		 * Gets the number of subscribers to the given EventType.
		 * @param et the EventType to return the number of subscribers of
		 * @return the number of subscribers to the given EventType.
		 */
		int subs(EventType et);
};

}
}

#endif
