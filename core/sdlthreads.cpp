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

int thread(void *func) {
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
	SDL_CreateThread(thread, thrdNm, (void*) fp);

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
	SDL_DestroyMutex(m_mutex);
}

int Mutex::lock() {
	return SDL_LockMutex(m_mutex);
}

int Mutex::unlock() {
	return SDL_UnlockMutex(m_mutex);
}

// Semaphore

Semaphore::Semaphore() {
	m_semaphore = SDL_CreateSemaphore(0);
	m_mutex = SDL_CreateMutex();
}

Semaphore::~Semaphore() {
	SDL_DestroySemaphore(m_semaphore);
	SDL_DestroyMutex(m_mutex);
}

Semaphore::Post Semaphore::wait() {
	if (m_posts.empty()) {
		SDL_SemWait(m_semaphore);
	}
	return popPost();
}

Semaphore::Post Semaphore::wait(uint64 timeout) {
	if (m_posts.empty()) {
		SDL_SemWaitTimeout(m_semaphore, timeout);
	}
	return popPost();
}

void Semaphore::post(Semaphore::Post wakeup) {
	m_posts.push(wakeup);
	SDL_LockMutex(m_mutex);
	SDL_SemPost(m_semaphore);
	SDL_UnlockMutex(m_mutex);
}

Semaphore::Post Semaphore::popPost() {
	SDL_LockMutex(m_mutex);
	auto post = m_posts.front();
	m_posts.pop();
	SDL_UnlockMutex(m_mutex);
	return post;
}

}
}

#endif
