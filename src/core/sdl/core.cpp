/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include <vector>

#include <SDL.h>
#include <SDL_opengl.h>

#include "../core.hpp"

namespace wombat {
namespace core {

extern SubscriptionManager _submgr;
extern std::vector<std::pair<Drawer*, Graphics*>> _drawers;
extern bool _running;

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

		Event wait() override;

		Event wait(uint64 timeout) override;

		void post(Event wakeup = Event::GenericPost) override;

		int popPost(Event &post) override;

		bool hasPosts() override;

	// disallow copying
	private:
		SdlMainEventQueue(const SdlMainEventQueue&);
		SdlMainEventQueue &operator=(const SdlMainEventQueue&);
};

BaseEventQueue &_mainEventQueue = *new SdlMainEventQueue();

TaskProcessor _taskProcessor(&_mainEventQueue);

const auto Event_DrawEvent = SDL_RegisterEvents(1);
const auto Event_SemaphorePost = SDL_RegisterEvents(1);

SDL_Window *_display = nullptr;
SDL_GLContext _glContext = nullptr;

Key toWombatKey(SDL_Event);
void _updateEventTime();

// SdlMainEventQueue Implementation

SdlMainEventQueue::SdlMainEventQueue() {
}

SdlMainEventQueue::~SdlMainEventQueue() {
}

Event SdlMainEventQueue::wait() {
	return Event::UnknownEvent;
}

Event SdlMainEventQueue::wait(uint64 timeout) {
	return Event::UnknownEvent;
}

void SdlMainEventQueue::post(Event post) {
	m_mutex.lock();
	m_posts.push(post);

	SDL_Event ev;
	SDL_zero(ev);
	ev.type = Event_SemaphorePost;
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

void draw() {
	SDL_Event ev;
	SDL_zero(ev);
	ev.type = Event_DrawEvent;
	SDL_PushEvent(&ev);
}

void _draw() {
	//SDL_RenderClear(_renderer);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (auto d : _drawers) {
		//glTranslated((double) -(w / 2), (double) -(h / 2), 0);
		//glTranslated((double) translation->getX(), (double) translation->getY(), 0);

		d.first->draw(*d.second);
		d.second->resetViewport();
	}
	SDL_GL_SwapWindow(_display);
}

void main() {
	// handle events
	SDL_Event sev;
	TaskState taskState = TaskState::Waiting;
	while (_running) {
		if (taskState.state == TaskState::Running) {
			// yes... SDL_WaitEventTimeout uses 0 indicate failure...
			if (SDL_WaitEventTimeout(&sev, taskState.sleepDuration) == 0) {
				_mainEventQueue.post(Event::Timeout);
			}
		} else {
			SDL_WaitEvent(&sev);
		}

		const auto t = sev.type;
		Event ev;
		_updateEventTime();
		if (t == Event_DrawEvent) {
			_draw();
		} else if (sev.type == Event_SemaphorePost) {
			if (_mainEventQueue.popPost(ev) == 0) {
				taskState = _taskProcessor.run(ev);
			}
		} else if (t == SDL_WINDOWEVENT) {
			if (sev.window.event == SDL_WINDOWEVENT_RESIZED) {
				glLoadIdentity();
				glViewport(0, 0, displayWidth(), displayHeight());
				glOrtho(0.0f, displayWidth(), displayHeight(), 0.0f, -1.0f, 1.0f);
				_submgr.post(Event::ScreenSizeChange);
			}
		} else if (t == SDL_QUIT) {
			_submgr.post(Event::Quit);
		} else if (t == SDL_KEYUP) {
			ev.m_type = Event::KeyUp;
			ev.m_body.key = toWombatKey(sev);
			_submgr.post(ev);
		} else if (t == SDL_KEYDOWN) {
			ev.m_type = Event::KeyDown;
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
	if (!_display) {
		return -2;
	}


	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	SDL_GL_SetSwapInterval(1);
	_glContext = SDL_GL_CreateContext(_display);

	glLoadIdentity();
	glOrtho(0.0f, displayWidth(), displayHeight(), 0.0f, -1.0f, 1.0f);

	_running = true;
	_updateEventTime();

	return 0;
}

}
}
