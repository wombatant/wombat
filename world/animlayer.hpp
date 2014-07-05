/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_WORLD_ANIMLAYER_HPP
#define WOMBAT_WORLD_ANIMLAYER_HPP

#include <core/core.hpp>

namespace wombat {
namespace world {

class AnimLayer {
	public:
		core::Animation *animation = nullptr;
		common::Point point;

		/**
		 * Constructor
		 */
		AnimLayer() = default;

		/**
		 * Constructor
		 * @model model representing what this AnimLayer should contain
		 */
		AnimLayer(models::AnimLayer model);

		/**
		 * Destructor
		 */
		~AnimLayer();

		/**
		 * Loads the AnimLayer data from the given model.
		 * @model model representing what this AnimLayer should contain
		 */
		void load(models::AnimLayer model);
};

}
}

#endif
