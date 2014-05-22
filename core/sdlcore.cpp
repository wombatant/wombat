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

#include "core.hpp"

namespace wombat {
namespace core {

extern SubscriptionManager _submgr;

class SdlMainEventQueue: public BaseEventQueue {
	private:
		std::queue<Event> m_posts;
		Mutex m_mutex;

	public:
		/**
		 * Constructor
		 */
		SdlMainEventQueue();

		/**
		 * Destructor
		 */
		~SdlMainEventQueue();

		Event wait();

		Event wait(uint64 timeout);

		void post(Event wakeup = GenericPost);

		int popPost(Event &post);

		bool hasPosts();

	// disallow copying
	private:
		SdlMainEventQueue(const SdlMainEventQueue&);
		SdlMainEventQueue &operator=(const SdlMainEventQueue&);
} _mainEventQueue;

TaskProcessor _taskProcessor(&_mainEventQueue);

const auto Event_DrawEvent = SDL_RegisterEvents(1);
const auto Event_SemaporePost = SDL_RegisterEvents(1);
const auto Event_SemaphoreTimeout = SDL_RegisterEvents(1);

std::vector<std::pair<Drawer*, Graphics*>> drawers;
SDL_Window *_display = 0;
SDL_Renderer *_renderer = 0;

extern bool _running;


Key toWombatKey(SDL_Event);
void _updateEventTime();

void addDrawer(Drawer *d) {
	drawers.push_back(std::pair<Drawer*, Graphics*>(d, new Graphics()));
}

// SdlMainEventQueue Implementation

SdlMainEventQueue::SdlMainEventQueue() {
}

SdlMainEventQueue::~SdlMainEventQueue() {
}

Event SdlMainEventQueue::wait() {
	return UnknownEvent;
}

Event SdlMainEventQueue::wait(uint64 timeout) {
	return UnknownEvent;
}

void SdlMainEventQueue::post(Event post) {
	m_mutex.lock();
	m_posts.push(post);

	SDL_Event ev;
	SDL_zero(ev);
	ev.type = Event_SemaporePost;
	SDL_PushEvent(&ev);

	m_mutex.unlock();
}

int SdlMainEventQueue::popPost(Event &post) {
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

bool SdlMainEventQueue::hasPosts() {
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
	SDL_RenderClear(_renderer);
	for (auto d : drawers) {
		d.first->draw(*d.second);
		d.second->resetViewport();
	}
	SDL_RenderPresent(_renderer);
}

void main() {
	// handle events
	SDL_Event sev;
	TaskState taskState = TaskState::Waiting;
	while (_running) {
		if (taskState.state == TaskState::Running) {
			// yes... SDL_WaitEventTimeout uses 0 indicate failure...
			if (SDL_WaitEventTimeout(&sev, taskState.sleepDuration) == 0) {
				sev.type = Event_SemaphoreTimeout;
			}
		} else {
			SDL_WaitEvent(&sev);
		}

		const auto t = sev.type;
		Event ev;
		_updateEventTime();
		if (t == Event_DrawEvent) {
			_draw();
		} else if (sev.type == Event_SemaphoreTimeout) {
			ev.m_type = Timeout;
			taskState = _taskProcessor.run(ev);
		} else if (sev.type == Event_SemaporePost) {
			if (_mainEventQueue.popPost(ev) == 0) {
				taskState = _taskProcessor.run(ev);
			}
		} else if (t == SDL_WINDOWEVENT) {
			if (sev.window.event == SDL_WINDOWEVENT_RESIZED) {
				ev.m_type = ScreenSizeChange;
				_submgr.post(ev);
			}
		} else if (t == SDL_QUIT) {
			ev.m_type = QuitEvent;
			_submgr.post(ev);
		} else if (t == SDL_KEYUP) {
			ev.m_type = KeyUpEvent;
			ev.m_body.key = toWombatKey(sev);
			_submgr.post(ev);
		} else if (t == SDL_KEYDOWN) {
			ev.m_type = KeyDownEvent;
			ev.m_body.key = toWombatKey(sev);
			_submgr.post(ev);
		}
	}
}

int init(models::Settings settings) {
	auto fullscreen = settings.Fullscreen;
	auto w = settings.Width;
	auto h = settings.Height;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == -1) {
		return -1;
	}

	auto flags = SDL_WINDOW_OPENGL;
	if (fullscreen) {
		flags = (SDL_WindowFlags) (flags | SDL_WINDOW_FULLSCREEN_DESKTOP);
	} else {
		flags = (SDL_WindowFlags) (flags | SDL_WINDOW_RESIZABLE);
	}
	_display = SDL_CreateWindow("Wombat", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, flags);
	if (!_display)
		return -3;
	_renderer = SDL_CreateRenderer(_display, -1, SDL_RENDERER_ACCELERATED);

	_running = true;
	_updateEventTime();

	return 0;
}

}
}

#endif
