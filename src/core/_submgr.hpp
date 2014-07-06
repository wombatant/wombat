/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
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
		 * Adds the given Task to the subscription list of the given Event::Type.
		 * @param et the Event::Type that the Task is subscribing to
		 * @param task the Task to add to the subscription list
		 */
		void addSubscription(Event::Type et, Task *task);

		/**
		 * Removes the given Task from all subscription lists.
		 * @param task the Task that is unsubscribing from everything
		 */
		void removeFromAllSubs(Task *task);

		/**
		 * Calls post on the given Event for all TaskProcessors subscribed to
		 * the Event's Event::Type.
		 * @param event the Event to publish
		 */
		void post(Event event);

		/**
		 * Calls run on the given Event for all subscribers to the Event's Event::Type.
		 * @param event the Event to publish
		 */
		void run(Event event);

		/**
		 * Gets the number of subscribers to the given Event::Type.
		 * @param et the Event::Type to return the number of subscribers of
		 * @return the number of subscribers to the given Event::Type.
		 */
		int subs(Event::Type et);
};

}
}

#endif
