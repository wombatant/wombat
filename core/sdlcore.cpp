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

#include "sdlglobs.hpp"
#include "core.hpp"

namespace wombat {
namespace core {

std::vector<Drawer*> drawers;
std::vector<Graphics*> graphicsInstances;
SDL_Window *display = 0;
SDL_Renderer *renderer = 0;
extern std::vector<EventHandler> eventHandlers;
const auto Event_DrawEvent = SDL_RegisterEvents(1);
extern bool vrunning;
Key toEventType(SDL_Event);

void _updateEventTime();

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
	while (vrunning) {
		SDL_WaitEvent(&sev);
		const auto t = sev.type;
		_updateEventTime();
		if (t == Event_DrawEvent) {
			_draw();
		} else {
			Event ev;
			if (sev.type == SDL_QUIT) {
				ev.type = QuitEvent;
			} else if (sev.type == SDL_KEYUP) {
				ev.type = KeyUpEvent;
			} else if (sev.type == SDL_KEYDOWN) {
				ev.type = KeyDownEvent;
			}
			ev.key = toEventType(sev);
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
