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
#include <vector>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "allegro_globs.hpp"
#include "core.hpp"


namespace wombat {
namespace core {

std::vector<Drawer*> drawers;
std::vector<Graphics*> graphicsInstances;

static void* drawThreadFunc(ALLEGRO_THREAD *t, void *arg) {
	while (1) {
		for (int i = 0; i < drawers.size(); i++) {
			drawers[i]->draw(graphicsInstances[i]);
		}
		al_flip_display();
		al_rest(0.016);
	}
	return 0;
}

int init(bool fullscreen, int w, int h) {
	if (!al_init())
		return -1;
	if (!al_init_image_addon())
		return -2;

	if (fullscreen) {
		ALLEGRO_DISPLAY_MODE dispMode;
		al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
		al_get_display_mode(al_get_num_display_modes() - 1, &dispMode);
		w = dispMode.width;
		h = dispMode.height;
	}

	display = al_create_display(w, h);
	if (!display)
		return -3;

	drawThread = al_create_thread(drawThreadFunc, 0);
	if (drawThread) {
		al_start_thread(drawThread);
	} else {
		al_destroy_display(display);
		return -4;
	}

	al_rest(30);

	return 0;
}

void addDrawer(Drawer *d) {
	graphicsInstances.push_back(new Graphics());
	drawers.push_back(d);
}

}
}

