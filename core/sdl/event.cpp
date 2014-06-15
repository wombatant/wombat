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
#include <SDL.h>
#include "../event.hpp"

namespace wombat {
namespace core {

Key toWombatKey(SDL_Event t) {
	switch (t.key.keysym.sym) {
	case SDLK_a:
		return Key::A;
	case SDLK_d:
		return Key::D;
	case SDLK_h:
		return Key::H;
	case SDLK_j:
		return Key::J;
	case SDLK_k:
		return Key::K;
	case SDLK_l:
		return Key::L;
	case SDLK_q:
		return Key::Q;
	case SDLK_s:
		return Key::S;
	case SDLK_ESCAPE:
		return Key::Escape;
	}
	return Key::Unknown;
}

}
}
