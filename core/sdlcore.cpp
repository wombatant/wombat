/*
 * Copyright 2013 gtalent2@gmail.com
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
SDL_Thread *drawThread = 0;
SDL_Renderer *renderer = 0;

int draw(void *t) {
	for (int i = 0; i < drawers.size(); i++) {
		drawers[i]->draw(graphicsInstances[i]);
	}
	SDL_RenderPresent(renderer);
	return 0;
}

int pollEvents(void *t) {
	// handle events
	SDL_Event ev;
	while (SDL_PollEvent(&ev)) {
	}
}

int init(bool fullscreen, int w, int h) {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER) == -1) {
		return -1;
	}

	display = SDL_CreateWindow("Wombat", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_OPENGL);
	if (!display)
		return -3;
	renderer = SDL_CreateRenderer(display, -1, SDL_RENDERER_ACCELERATED);

	//drawThread = SDL_CreateThread(draw, "DrawThread", 0);
	//if (!drawThread) {
	//	SDL_DestroyWindow(display);
	//	return -4;
	//}

	return 0;
}

void addDrawer(Drawer *d) {
	graphicsInstances.push_back(new Graphics());
	drawers.push_back(d);
}

void sleep(uint64 ms) {
	SDL_Delay(ms);
}

}
}

#endif
