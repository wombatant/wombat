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
#include <queue>

#ifdef WITH_SDL
#include <SDL.h>
#endif

#include "types.hpp"

namespace wombat {
namespace core {

class Semaphore;
class TaskProcessor;

class Task {
	public:
		virtual int64 run() = 0;
};

class Mutex {
	public:
#ifdef WITH_SDL
		SDL_mutex *m_mutex;
#endif

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

class SemaphorePost {
	friend Semaphore;
	friend TaskProcessor;

	public:
		enum Reason {
			GenericPost,
			Timeout,
			ReceivedMessage
		};

	protected:
		/**
		 * Used to specify the Task that received a message.
		 */
		Task *m_task;
		Reason m_reason;

	public:
		/**
		 * Constructor
		 * @param reason optional reason parameter, defaults to GenericPost
		 */
		SemaphorePost(Reason reason = GenericPost);

		/**
		 *	Gets the reason for the wake up.
		 * @return the reason for the post
		 */
		Reason reason();
};

class Semaphore {
	private:
#ifdef WITH_SDL
		SDL_sem *m_semaphore;
		SDL_mutex *m_mutex;
#endif
		std::queue<SemaphorePost> m_posts;

	public:
		/**
		 * Constructor
		 */
		Semaphore();

		/**
		 * Destructor
		 */
		~Semaphore();

		/**
		 * Waits until there is a post to process.
		 * @return a SemaphorePost with the reason for the wake up
		 */
		SemaphorePost wait();

		/**
		 * Waits until there is a post to process or the given timeout has expired.
		 * @param timeout the desired timeout period in milliseconds
		 * @return a SemaphorePost with the reason for the wake up
		 */
		SemaphorePost wait(uint64 timeout);

		/**
		 * Posts the the Semaphore to wake up.
		 * @param wakeup optional parameter used to specify the reason for the wake up
		 */
		void post(SemaphorePost wakeup = SemaphorePost());

		/**
		 * Gets the oldest post available.
		 * @return the oldest post available
		 */
		SemaphorePost popPost();

		/**
		 * Indicates whether or not there are any pending posts.
		 * @return indicator of whether or not there are any pending posts
		 */
		bool hasPosts();

	// disallow copying
	private:
		Semaphore(const Semaphore&);
		Semaphore &operator=(const Semaphore&);
};

class TaskProcessor {
	private:
		bool m_running;

	public:
		/**
		 * Starts the thread for this TaskProcessor.
		 */
		void start();
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

		/**
		 * Read will wait until a message is received, then write it to the given
		 * destination.
		 * @param msg reference to the message to write to
		 * @return reason for the wake up
		 */
		SemaphorePost::Reason read(T &msg) {
			auto reason = m_sem->wait().reason();
			if (reason == SemaphorePost::ReceivedMessage) {
				m_mutex.lock();
				msg = m_msgs.front();
				m_msgs.pop();
				m_mutex.unlock();
			}
			return reason;
		}

		/**
		 * Read will wait until a message is received, then write it to the given
		 * destination.
		 * @param msg reference to the message to write to
		 * @param timeout timeout duration to give up on
		 * @return reason for the wake up
		 */
		SemaphorePost::Reason read(T &msg, uint64 timeout) {
			auto reason = m_sem->wait(timeout).reason();
			if (reason == SemaphorePost::ReceivedMessage) {
				m_mutex.lock();
				msg = m_msgs.front();
				m_msgs.pop();
				m_mutex.unlock();
			}
			return reason;
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
			m_sem->post(SemaphorePost::ReceivedMessage);
		}

	// disallow copying
	private:
		Channel(const Channel&);
		Channel &operator=(const Channel&);
};

}
}

#endif
