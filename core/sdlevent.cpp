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
#include <SDL.h>
#include "event.hpp"

namespace wombat {
namespace core {

EventType toEventType(SDL_Event t) {
	if (t.type == SDL_QUIT) {
		return Quit;
	} else {
		switch (t.key.keysym.sym) {
		case SDLK_a:
			return Key_A;
		case SDLK_ESCAPE:
			return Key_Escape;
		}
	}
	return UnknownEvent;
}

}
}
