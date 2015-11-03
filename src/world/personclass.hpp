/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_WORLD_PERSONCLASS_HPP
#define WOMBAT_WORLD_PERSONCLASS_HPP

#include <core/modelio.hpp>
#include "animlayer.hpp"

namespace wombat {
namespace world {

class PersonClass: public core::Flyweight<models::PersonClass>::GenericValue {
	private:
		static core::Flyweight<models::PersonClass> c_personClasses;
		std::string m_title;
		std::vector<std::vector<std::vector<AnimLayer>>> m_animations;

	public:
		/**
		 * Constructor
		 * @param model the model that the PersonClass will reflect
		 */
		explicit PersonClass(models::PersonClass model);

		void draw(common::Point pt,
		          models::TerrainType tt,
		          models::SpriteDirection facing,
		          models::SpriteMotion motion);

	private:
		AnimLayer *anim(models::TerrainType tt, models::SpriteDirection, models::SpriteMotion);

	public:
		/**
		 * Checks out the PersonClass object from the given model.
		 * @param model model representing the desired PersonClass
		 */
		static PersonClass *checkout(models::PersonClass model);

		/**
		 * Checks out the PersonClass object stored at the given path.
		 * @param path path of the PersonClass to checkout
		 */
		static PersonClass *checkout(std::string path);

		/**
		 * Checks in the given PersonClass object.
		 * @param pc PersonClass object to checkin
		 */
		static void checkin(PersonClass *pc);
};

}
}

#endif
