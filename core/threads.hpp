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

class SemaphorePost {
	friend Semaphore;
	friend TaskProcessor;

	public:
		enum Reason {
			GenericPost,
			Timeout,
			ReceivedMessage
		} m_reason;

	protected:
		/**
		 * Used to specify the Task that received a message.
		 */
		Task *m_task;

	public:
		/**
		 * Constructor
		 */
		SemaphorePost();
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
};

template <typename T>
class Channel {
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

}
}

#endif
