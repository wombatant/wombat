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
	case SDLK_b:
		return Key::B;
	case SDLK_c:
		return Key::C;
	case SDLK_d:
		return Key::D;
	case SDLK_e:
		return Key::E;
	case SDLK_f:
		return Key::F;
	case SDLK_g:
		return Key::G;
	case SDLK_h:
		return Key::H;
	case SDLK_i:
		return Key::I;
	case SDLK_j:
		return Key::J;
	case SDLK_k:
		return Key::K;
	case SDLK_l:
		return Key::L;
	case SDLK_m:
		return Key::M;
	case SDLK_n:
		return Key::N;
	case SDLK_o:
		return Key::O;
	case SDLK_p:
		return Key::P;
	case SDLK_q:
		return Key::Q;
	case SDLK_r:
		return Key::R;
	case SDLK_s:
		return Key::S;
	case SDLK_t:
		return Key::T;
	case SDLK_u:
		return Key::U;
	case SDLK_v:
		return Key::V;
	case SDLK_w:
		return Key::W;
	case SDLK_x:
		return Key::X;
	case SDLK_y:
		return Key::Y;
	case SDLK_z:
		return Key::Z;
	case SDLK_ESCAPE:
		return Key::Escape;
	}
	return Key::Unknown;
}

}
}
