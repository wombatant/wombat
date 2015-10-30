/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include <vector>

#include <SDL.h>
#include <SDL_ttf.h>

#include "../_misc.hpp"
#include "../gfx.hpp"
#include "../task.hpp"
#include "../types.hpp"

namespace wombat {
namespace core {

extern SubscriptionManager _submgr;
extern Mutex _drawersLock;
extern std::vector<Drawer*> _drawers;
extern bool _running;

extern TaskProcessor _taskProcessor;

const auto Event_QuitEvent = SDL_RegisterEvents(1);
const auto Event_SemaphorePost = SDL_RegisterEvents(1);

SDL_Window *_display = nullptr;
SDL_Renderer *_renderer = nullptr;

Key toWombatKey(SDL_Event);
void _updateEventTime();

static int _eventFilter(void *userdata, SDL_Event *event) {
	return (!((event->type == SDL_KEYDOWN) && event->key.repeat)) && event->type != SDL_TEXTINPUT;
}

void quit() {
	_running = false;
	SDL_Event ev;
	SDL_zero(ev);
	ev.type = Event_QuitEvent;
	SDL_PushEvent(&ev);
}

void _draw() {
	setRGB(0, 0, 0);
	SDL_RenderClear(_renderer);
	_drawersLock.lock();
	for (auto d : _drawers) {
		d->draw();
		resetViewport();
	}
	_drawersLock.unlock();
	SDL_RenderPresent(_renderer);
}

void main() {
	// start main TaskProcessor
	_taskProcessor.start();

	// setup event filter
	static bool eventFilterSet = false;
	if (!eventFilterSet) {
		SDL_SetEventFilter(_eventFilter, nullptr);
		eventFilterSet = true;
	}

	// handle events
	SDL_Event sev;
	Event ev;
	while (_running) {
		auto eventReturned = !SDL_PollEvent(&sev);

		if (eventReturned) {
			_draw();
		} else if (sev.type == Event_QuitEvent) {
			// do nothing, allow loop exit
		} else if (sev.type == SDL_WINDOWEVENT) {
			if (sev.window.event == SDL_WINDOWEVENT_RESIZED) {
				_submgr.post(Event::ScreenSizeChange);
			}
		} else if (sev.type == SDL_QUIT) {
			_submgr.post(Event::Quit);
		} else if (sev.type == SDL_KEYUP) {
			ev.m_type = Event::KeyUp;
			ev.m_body.key = toWombatKey(sev);
			_submgr.post(ev);
		} else if (sev.type == SDL_KEYDOWN) {
			ev.m_type = Event::KeyDown;
			ev.m_body.key = toWombatKey(sev);
			_submgr.post(ev);
		}
	}

	// stop main TaskProcessor
	_taskProcessor.stop();
	_taskProcessor.done();
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

	_renderer = SDL_CreateRenderer(_display, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!_renderer)
		return -4;
	SDL_SetRenderDrawBlendMode(_renderer, SDL_BLENDMODE_BLEND);

	if (TTF_Init() != 0) {
		return -5;
	}

	_running = true;
	_updateEventTime();

	return 0;
}

}
}
