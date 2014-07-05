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
#include <SDL.h>
#include "../core.hpp"

namespace wombat {
namespace core {

// Mutex

Mutex::Mutex() {
	m_mutex = SDL_CreateMutex();
}

Mutex::~Mutex() {
	if (m_mutex) {
		SDL_DestroyMutex((SDL_mutex*) m_mutex);
	}
}

int Mutex::lock() {
	return SDL_LockMutex((SDL_mutex*) m_mutex);
}

int Mutex::unlock() {
	return SDL_UnlockMutex((SDL_mutex*) m_mutex);
}

// EventQueue

EventQueue::EventQueue() {
	m_semaphore = SDL_CreateSemaphore(0);
}

EventQueue::~EventQueue() {
	SDL_DestroySemaphore((SDL_sem*) m_semaphore);
}

Event EventQueue::wait() {
	Event post;

	while (1) {
		SDL_SemWait((SDL_sem*) m_semaphore);

		if (popPost(post) == 0) {
			break;
		}
	}
	return post;
}

Event EventQueue::wait(uint64 timeout) {
	Event post;
	const auto origTimeout = timeout;
	const auto startTime = core::time();

	while (1) {
		auto wakeup = SDL_SemWaitTimeout((SDL_sem*) m_semaphore, timeout);

		if (wakeup == SDL_MUTEX_TIMEDOUT) {
			return EventType::Timeout;
		} else if (popPost(post) == 0) {
			break;
		} else {
			// no timeout, but another thread got the post
			auto time = core::time();
			// recheck timeout based on current time
			if (time > startTime + origTimeout) {
				post = EventType::Timeout;
				break;
			} else {
				// adjust timeout
				timeout = origTimeout - (time - startTime);
			}
		}
	}
	return post;
}

void EventQueue::post(Event event) {
	m_mutex.lock();
	m_posts.push(event);
	SDL_SemPost((SDL_sem*) m_semaphore);
	m_mutex.unlock();
}

}
}
