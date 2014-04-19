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

#ifdef WITH_SDL
#include <SDL.h>
#endif

#include "types.hpp"

namespace wombat {
namespace core {

enum WakeupReason {
	SemaphorePost,
	Timeout,
	ReceivedMessage
};

class Semaphore;
class TaskProcessor;

class TaskState {
	public:
		enum {
			Running,
			Waiting,
			Done
		} state;

		/**
		 * Time (milliseconds) til the Task wants to run again.
		 */
		uint64 sleepDuration;
};

class Task {
	protected:
		TaskProcessor *m_taskProcessor;
	public:
		virtual TaskState run(WakeupReason) = 0;
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

class Semaphore {
	public:
		class Post {
			friend Semaphore;
			friend TaskProcessor;

			protected:
				/**
				 * Used to specify the Task that received a message.
				 */
				Task *m_task;
				WakeupReason m_reason;

			public:
				/**
				 * Constructor
				 * @param reason optional reason parameter, defaults to SemaphorePost
				 */
				Post(WakeupReason reason = SemaphorePost);

				/**
				 *	Gets the reason for the wake up.
				 * @return the reason for the post
				 */
				WakeupReason reason();

			protected:
				/**
				 * Gets the Task that the wake up is for.
				 * @return the Task that the wake up is for
				 */
				Task *task();
		};

	private:
#ifdef WITH_SDL
		SDL_sem *m_semaphore;
		SDL_mutex *m_mutex;
#endif
		std::queue<Post> m_posts;

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
		 * @return a Post with the reason for the wake up
		 */
		Post wait();

		/**
		 * Waits until there is a post to process or the given timeout has expired.
		 * @param timeout the desired timeout period in milliseconds
		 * @return a Post with the reason for the wake up
		 */
		Post wait(uint64 timeout);

		/**
		 * Posts the the Semaphore to wake up.
		 * @param wakeup optional parameter used to specify the reason for the wake up
		 */
		void post(Post wakeup = Post());

		/**
		 * Gets the oldest post available.
		 * @return the oldest post available
		 */
		Post popPost();

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
		WakeupReason read() {
			auto reason = m_sem->wait().reason();
			if (reason == ReceivedMessage) {
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
		WakeupReason read(T &msg) {
			while (1) {
				auto reason = m_sem->wait().reason();
				if (reason == ReceivedMessage) {
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
		WakeupReason read(T &msg, uint64 timeout) {
			while (1) {
				auto reason = m_sem->wait(timeout).reason();
				if (reason == ReceivedMessage) {
					if (getMessage(msg)) {
						return reason;
					}
				} else {
					return reason;
				}
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
			m_sem->post(ReceivedMessage);
		}

	// disallow copying
	private:
		Channel(const Channel&);
		Channel &operator=(const Channel&);
};

class TaskProcessor {
	private:
		bool m_running;
		Semaphore m_sem;
		Channel<bool> m_done;
		std::vector<std::pair<Task*, uint64>> m_schedule;
		//This map seems kind of silly, but it is used to make sure
		// the TaskProcessor owns the given Task.
		std::map<Task*, Task*> m_taskMap;

	public:
		/**
		 * Starts the thread for this TaskProcessor.
		 */
		void start();

		/**
		 * Stop the thread for this TaskProcessor.
		 */
		void stop();

		/**
		 * Blocks until this TaskProcessor has stopped.
		 */
		void done();

	private:
		/**
		 * Gets the next Task to execute.
		 * @return the next task scheduled to execute
		 */
		std::pair<Task*, uint64> nextTask();

		void schedule(Task *task, TaskState state);
};

}
}

#endif
