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
#include <vector>

#include <SDL.h>

#include "_sdlglobs.hpp"
#include "core.hpp"

namespace wombat {
namespace core {

std::vector<Drawer*> drawers;
std::vector<Graphics*> graphicsInstances;
SDL_Window *display = 0;
SDL_Renderer *renderer = 0;
extern std::vector<EventHandler> eventHandlers;
const auto Event_DrawEvent = SDL_RegisterEvents(1);
const auto Event_SemaporePost = SDL_RegisterEvents(1);
extern bool vrunning;


Key toWombatKey(SDL_Event);
void _updateEventTime();
void main();

class EventQueueSemaphore: public BaseSemaphore {
	private:
		std::queue<Event> m_posts;
		void *m_semaphore;
		Mutex m_mutex;

	public:
		/**
		 * Constructor
		 */
		EventQueueSemaphore();

		/**
		 * Destructor
		 */
		~EventQueueSemaphore();

		Event wait();

		Event wait(uint64 timeout);

		void post(Event wakeup = SemaphorePost);

		int popPost(Event &post);

		bool hasPosts();

	// disallow copying
	private:
		EventQueueSemaphore(const EventQueueSemaphore&);
		EventQueueSemaphore &operator=(const EventQueueSemaphore&);
} _mainSemaphore;

EventQueueSemaphore::EventQueueSemaphore() {
}

EventQueueSemaphore::~EventQueueSemaphore() {
}

Event EventQueueSemaphore::wait() {
	return UnknownEvent;
}

Event EventQueueSemaphore::wait(uint64 timeout) {
	return UnknownEvent;
}

void EventQueueSemaphore::post(Event post) {
	m_mutex.lock();
	m_posts.push(post);
	SDL_Event ev;
	SDL_zero(ev);
	ev.type = Event_SemaporePost;
	SDL_PushEvent(&ev);
	m_mutex.unlock();
}

int EventQueueSemaphore::popPost(Event &post) {
	m_mutex.lock();
	if (hasPosts()) {
		post = m_posts.front();
		m_posts.pop();
		m_mutex.unlock();
		return 0;
	}
	m_mutex.unlock();
	return 1;
}

bool EventQueueSemaphore::hasPosts() {
	return m_posts.size();
}

void draw() {
	SDL_Event ev;
	SDL_zero(ev);
	ev.type = Event_DrawEvent;
	SDL_PushEvent(&ev);
}

void _draw() {
	SDL_RenderClear(renderer);
	for (int i = 0; i < drawers.size(); i++) {
		drawers[i]->draw(graphicsInstances[i]);
	}
	SDL_RenderPresent(renderer);
}

void main() {
	TaskProcessor tp;
	// handle events
	SDL_Event sev;
	while (vrunning) {
		TaskState taskState;
		if (taskState.state == TaskState::Running) {
			printf("SDL_WaitEventTimeout\n");
			SDL_WaitEventTimeout(&sev, taskState.sleepDuration);
		} else {
			printf("SDL_WaitEvent\n");
			SDL_WaitEvent(&sev);
		}
		//printf("Got SDL_Event\n");
		const auto t = sev.type;
		_updateEventTime();
		if (t == Event_DrawEvent) {
			_draw();
		} else {
			Event ev;
			if (sev.type == Event_SemaporePost) {
				if (_mainSemaphore.popPost(ev) == 0) {
					taskState = tp.run(ev);
				}
			} else if (sev.type == SDL_QUIT) {
				ev.m_type = QuitEvent;
			} else if (sev.type == SDL_KEYUP) {
				ev.m_type = KeyUpEvent;
				ev.m_body.key = toWombatKey(sev);
			} else if (sev.type == SDL_KEYDOWN) {
				ev.m_type = KeyDownEvent;
				ev.m_body.key = toWombatKey(sev);
			}
			for (auto f : eventHandlers) {
				f(ev);
			}
		}
	}
}

int init(bool fullscreen, int w, int h) {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER) == -1) {
		return -1;
	}

	auto flags = SDL_WINDOW_OPENGL;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	display = SDL_CreateWindow("Wombat", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, flags);
	if (!display)
		return -3;
	renderer = SDL_CreateRenderer(display, -1, SDL_RENDERER_ACCELERATED);

	vrunning = true;
	_updateEventTime();
	return 0;
}

void addDrawer(Drawer *d) {
	graphicsInstances.push_back(new Graphics());
	drawers.push_back(d);
}

}
}

#endif
