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
#ifdef WITH_SDL

#include <SDL.h>
#include "threads.hpp"

namespace wombat {
namespace core {

int _sdlthread(void *func) {
	if (func) {
		auto f = (std::function<void()>*) func;
		(*f)();
		delete f;
	}
	return 0;
}

void startThread(std::function<void()> f) {
	static int threadCount = 0;

	char thrdNm[10];
	snprintf(thrdNm, 10, "Thread %d", threadCount);


	auto fp = new std::function<void()>(f);
	SDL_CreateThread(_sdlthread, thrdNm, (void*) fp);

	threadCount++;
}

void sleep(uint64 ms) {
	SDL_Delay(ms);
}

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

// Semaphore

Semaphore::Semaphore() {
	m_semaphore = SDL_CreateSemaphore(0);
}

Semaphore::~Semaphore() {
	SDL_DestroySemaphore((SDL_sem*) m_semaphore);
}

Event Semaphore::wait() {
	Event post;

	while (1) {
		SDL_SemWait((SDL_sem*) m_semaphore);

		if (popPost(post) == 0) {
			break;
		}
	}
	return post;
}

Event Semaphore::wait(uint64 timeout) {
	Event post;
	const auto origTimeout = timeout;
	const auto startTime = core::time();

	while (1) {
		auto wakeup = SDL_SemWaitTimeout((SDL_sem*) m_semaphore, timeout);

		if (wakeup == SDL_MUTEX_TIMEDOUT) {
			return Timeout;
		} else if (popPost(post) == 0) {
			break;
		} else {
			// no timeout, but another thread got the post
			auto time = core::time();
			// recheck timeout based on current time
			if (time > startTime + origTimeout) {
				post = Timeout;
				break;
			} else {
				// adjust timeout
				timeout = origTimeout - (time - startTime);
			}
		}
	}
	return post;
}

void Semaphore::post(Event wakeup) {
	m_mutex.lock();
	m_posts.push(wakeup);
	SDL_SemPost((SDL_sem*) m_semaphore);
	m_mutex.unlock();
}

}
}

#endif
