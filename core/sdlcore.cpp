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

class EventQueueSemaphore: public BaseSemaphore {
	private:
		std::queue<Event> m_posts;
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

TaskProcessor _taskProcessor(&_mainSemaphore);

const auto Event_DrawEvent = SDL_RegisterEvents(1);
const auto Event_SemaporePost = SDL_RegisterEvents(1);
const auto Event_SemaporeTimeout = SDL_RegisterEvents(1);

std::vector<Drawer*> drawers;
std::vector<Graphics*> graphicsInstances;
SDL_Window *display = 0;
SDL_Renderer *renderer = 0;

extern std::vector<EventHandler> eventHandlers;
extern bool _running;


Key toWombatKey(SDL_Event);
void _updateEventTime();

// EventQueueSemaphore Implementation

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

// Main TaskProcessor modifiers

void addTask(std::function<TaskState(Event)> task, TaskState state) {
	_taskProcessor.addTask(task, state);
}

void addTask(Task *task, TaskState state) {
	_taskProcessor.addTask(task, state);
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
	// handle events
	SDL_Event sev;
	TaskState taskState = TaskState::Waiting;
	while (_running) {
		if (taskState.state == TaskState::Running) {
			if (SDL_WaitEventTimeout(&sev, taskState.sleepDuration) == 0) {
				// yes... SDL_WaitEventTimeout uses 0 indicate failure...
				sev.type = Event_SemaporeTimeout;
			}
		} else {
			SDL_WaitEvent(&sev);
		}

		const auto t = sev.type;
		Event ev;
		_updateEventTime();
		if (t == Event_DrawEvent) {
			_draw();
		} else if (sev.type == Event_SemaporeTimeout) {
			ev.m_type = Timeout;
			taskState = _taskProcessor.run(ev);
		} else if (sev.type == Event_SemaporePost) {
			if (_mainSemaphore.popPost(ev) == 0) {
				taskState = _taskProcessor.run(ev);
			}
		} else if (t == SDL_QUIT) {
			ev.m_type = QuitEvent;

			for (auto f : eventHandlers) {
				f(ev);
			}
		} else if (t == SDL_KEYUP) {
			ev.m_type = KeyUpEvent;
			ev.m_body.key = toWombatKey(sev);

			for (auto f : eventHandlers) {
				f(ev);
			}
		} else if (t == SDL_KEYDOWN) {
			ev.m_type = KeyDownEvent;
			ev.m_body.key = toWombatKey(sev);

			for (auto f : eventHandlers) {
				f(ev);
			}
		}
	}
}

int init(models::Settings settings) {
	auto fullscreen = settings.Fullscreen;
	auto w = settings.Width;
	auto h = settings.Height;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER) == -1) {
		return -1;
	}

	auto flags = SDL_WINDOW_OPENGL;
	if (fullscreen) {
		flags = (SDL_WindowFlags) (flags | SDL_WINDOW_FULLSCREEN_DESKTOP);
	} else {
		flags = (SDL_WindowFlags) (flags | SDL_WINDOW_RESIZABLE);
	}
	display = SDL_CreateWindow("Wombat", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, flags);
	if (!display)
		return -3;
	renderer = SDL_CreateRenderer(display, -1, SDL_RENDERER_ACCELERATED);

	_running = true; _updateEventTime();
	return 0;
}

void addDrawer(Drawer *d) {
	graphicsInstances.push_back(new Graphics());
	drawers.push_back(d);
}

}
}

#endif
