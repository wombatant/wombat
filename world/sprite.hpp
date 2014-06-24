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
#ifndef WOMBAT_WORLD_SPRITE_HPP
#define WOMBAT_WORLD_SPRITE_HPP

#include "spriteclass.hpp"

namespace wombat {
namespace world {

class Sprite {
	public:
		/**
		 * Constructor
		 */
		Sprite() = default;

		/**
		 * Constructor
		 * @param model model to build Sprite off of
		 */
		Sprite(models::Sprite model);

		void load(models::Sprite model);

		void unload();

		/**
		 * Default setAddress does nothing, this is just here for classes based
		 * on Sprite can acquire their address.
		 */
		virtual void setAddress(common::Point pt);

		/**
		 * Default setZone does nothing, this is just here for classes based
		 * on Sprite can acquire a reference to their Zone.
		 */
		virtual void setZone(class Zone *zone);

		virtual std::string id();

		virtual void draw(core::Graphics &gfx, common::Point pt) = 0;
};

Sprite *loadSprite(models::Sprite model);

}
}

#endif
