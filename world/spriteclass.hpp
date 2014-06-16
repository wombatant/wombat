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
#ifndef WOMBAT_WORLD_SPRITECLASS_HPP
#define WOMBAT_WORLD_SPRITECLASS_HPP

#include <core/core.hpp>
#include "animlayer.hpp"

namespace wombat {
namespace world {

class SpriteClass: public core::Flyweight<models::SpriteClass>::GenericValue {
	private:
		static core::Flyweight<models::SpriteClass> c_spriteClasses;
		std::vector<std::vector<AnimLayer>> m_anims;

	public:
		/**
		 * Constructor
		 */
		SpriteClass();

		/**
		 * Destructor
		 */
		~SpriteClass();

		virtual void draw(core::Graphics &gfx, common::Point pt, models::SpriteDirection facing) = 0;

		/**
		 * Checks out the SpriteClass object from the given model.
		 * @param model model representing the desired SpriteClass
		 */
		static SpriteClass *checkout(models::SpriteClass model);

		/**
		 * Checks out the SpriteClass object stored at the given path.
		 * @param path path of the SpriteClass to checkout
		 */
		static SpriteClass *checkout(std::string path);

		/**
		 * Checks in the given SpriteClass object.
		 * @param pc SpriteClass object to checkin
		 */
		static void checkin(SpriteClass *&pc);
};

}
}

#endif
