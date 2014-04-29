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
#ifndef WOMBAT_CORE_THREADS_HPP
#define WOMBAT_CORE_THREADS_HPP

#include <functional>
#include <map>
#include <queue>

#include "event.hpp"
#include "misc.hpp"
#include "types.hpp"

namespace wombat {
namespace core {

class Task;
class TaskProcessor;
class Semaphore;

class Mutex {
	public:
		void *m_mutex;

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

class BaseSemaphore {
	public:
		/**
		 * Destructor
		 */
		virtual ~BaseSemaphore();

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
		 * Posts the the Semaphore to wake up.
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

class Semaphore: public BaseSemaphore {
	private:
		std::queue<Event> m_posts;
		void *m_semaphore;
		Mutex m_mutex;

	public:
		/**
		 * Constructor
		 */
		Semaphore();

		/**
		 * Destructor
		 */
		~Semaphore();

		Event wait();

		Event wait(uint64 timeout);

		void post(Event wakeup = SemaphorePost);

		int popPost(Event &post);

		bool hasPosts();

	// disallow copying
	private:
		Semaphore(const Semaphore&);
		Semaphore &operator=(const Semaphore&);
};

void startThread(std::function<void()> f);

void sleep(uint64 ms);


template <typename T>
class Channel {
	private:
		Semaphore *m_sem;
		Mutex m_mutex;
		std::queue<T> m_msgs;

	public:
		/**
		 * Constructor
		 * @param sem the Semaphore for this Channel to listen on
		 */
		Channel(Semaphore *sem = new Semaphore()) {
			m_sem = sem;
		}

		/**
		 * Destructor
		 */
		~Channel() {
			if (m_sem) {
				delete m_sem;
			}
		}

	private:
		/**
		 *
		 * @return indicates whether or not a message was retrieved
		 */
		bool getMessage(T &msg) {
			bool retval = false;
			m_mutex.lock();
			if (!m_msgs.empty) {
				msg = m_msgs.front();
				m_msgs.pop();
				retval = true;
			}
			m_mutex.unlock();
			return retval;
		}

	public:
		/**
		 * Waits until a message is received, then discards the message.
		 * @return reason for the wake up
		 */
		EventType read() {
			auto reason = m_sem->wait().type();
			if (reason == ChannelMessage) {
				m_mutex.lock();
				m_msgs.pop();
				m_mutex.unlock();
			}
			return reason;
		}

		/**
		 * Read will wait until a message is received, then write it to the given
		 * destination.
		 * @param msg reference to the message to write to
		 * @return reason for the wake up
		 */
		EventType read(T &msg) {
			while (1) {
				auto reason = m_sem->wait().type();
				if (reason == ChannelMessage) {
					if (getMessage(msg)) {
						return reason;
					}
				} else {
					return reason;
				}
			}
		}

		/**
		 * Read will wait until a message is received, then write it to the given
		 * destination.
		 * @param msg reference to the message to write to
		 * @param timeout timeout duration to give up on
		 * @return reason for the wake up
		 */
		EventType read(T &msg, uint64 timeout) {
			auto startTime = core::time();
			auto currentTimeout = timeout;
			while (1) {
				auto reason = m_sem->wait(currentTimeout).type();
				if (reason == ChannelMessage) {
					if (getMessage(msg)) {
						return reason;
					}
				} else {
					return reason;
				}
				currentTimeout = timeout - (time() - startTime);
			}
		}

		/**
		 * Writes the given message to the message queue and wakes up any thread
		 * waiting for a message.
		 * @param msg the message to write
		 */
		void write(T msg) {
			m_mutex.lock();
			m_msgs.push(msg);
			m_mutex.unlock();
			m_sem->post(ChannelMessage);
		}

	// disallow copying
	private:
		Channel(const Channel&);
		Channel &operator=(const Channel&);
};

}
}

#endif
