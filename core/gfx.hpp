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
#ifndef WOMBAT_CORE_GFX_HPP
#define WOMBAT_CORE_GFX_HPP

#include <string>

#ifdef WITH_ALLEGRO
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#endif

namespace wombat {
namespace core {

class Image {
	protected:
#ifdef WITH_ALLEGRO
		ALLEGRO_BITMAP *m_alImg;
#endif

	public:
		Image();
		int width();
		int height();
};

Image* loadImage(std::string path);

}
}

#endif
