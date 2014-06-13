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
#ifndef WOMBAT_CORE_SYNC_HPP
#define WOMBAT_CORE_SYNC_HPP

#include <queue>
#include "event.hpp"

namespace wombat {
namespace core {

class Mutex {
	private:
		void *m_mutex;

	public:
		/**
		 * Constructor
		 */
		Mutex();

		/**
		 * Destructor
		 */
		~Mutex();

		/**
		 * Locks this Mutex.
		 * @return 0 on success
		 */
		int lock();

		/**
		 * Unlocks this Mutex.
		 * @return 0 on success
		 */
		int unlock();

	private:
		Mutex(const Mutex&);
		Mutex &operator=(const Mutex&);
}; 

class BaseEventQueue {
	public:
		/**
		 * Destructor
		 */
		virtual ~BaseEventQueue() = default;

		/**
		 * Waits until there is a post to process.
		 * @return a Event with the reason for the wake up
		 */
		virtual Event wait() = 0;

		/**
		 * Waits until there is a post to process or the given timeout has expired.
		 * @param timeout the desired timeout period in milliseconds
		 * @return a Event with the reason for the wake up
		 */
		virtual Event wait(uint64 timeout) = 0;

		/**
		 * Posts the the EventQueue to wake up.
		 * @param wakeup optional parameter used to specify the reason for the wake up
		 */
		virtual void post(Event wakeup = Event()) = 0;

		/**
		 * Gets the oldest post available.
		 * @param post Event that the popped Event will be read into
		 * @return 0 if success, 1 if there are no posts
		 */
		virtual int popPost(Event &post) = 0;

		/**
		 * Indicates whether or not there are any pending posts.
		 * @return indicator of whether or not there are any pending posts
		 */
		virtual bool hasPosts() = 0;
};

class EventQueue: public BaseEventQueue {
	private:
		std::queue<Event> m_posts;
		void *m_semaphore;
		Mutex m_mutex;

	public:
		/**
		 * Constructor
		 */
		EventQueue();

		/**
		 * Destructor
		 */
		~EventQueue();

		Event wait();

		Event wait(uint64 timeout);

		void post(Event wakeup = EventType::GenericPost);

		int popPost(Event &post);

		bool hasPosts();

	// disallow copying
	private:
		EventQueue(const EventQueue&);
		EventQueue &operator=(const EventQueue&);
};

}
}

#endif
