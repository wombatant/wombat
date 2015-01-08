/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
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
