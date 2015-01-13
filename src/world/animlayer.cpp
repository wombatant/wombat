/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "animlayer.hpp"

namespace wombat {
namespace world {

AnimLayer::AnimLayer(models::AnimLayer model) {
	load(model);
}

AnimLayer::~AnimLayer() {
	if (animation) {
		core::checkinAnimation(animation);
	}
}

void AnimLayer::load(models::AnimLayer model) {
	animation = core::checkoutAnimation(model.Animation);
	point = model.Point;
}

}
}
