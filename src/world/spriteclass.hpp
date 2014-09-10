/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
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

		virtual void draw(common::Point pt, models::SpriteDirection facing) = 0;

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
