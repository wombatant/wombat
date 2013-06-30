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
#include <allegro5/allegro.h>

#include "allegro_globs.hpp"
#include "core.hpp"

namespace wombat {
namespace core {

int init(bool fullscreen, int w, int h) {
	if (!al_init())
		return -1;

	if (fullscreen) {
		ALLEGRO_DISPLAY_MODE dispMode;
		al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
		al_get_display_mode(al_get_num_display_modes() - 1, &dispMode);
		w = dispMode.width;
		h = dispMode.height;
	}

	if (!(disp = al_create_display(w, h)))
		return -2;

	return 0;
}

}
}

