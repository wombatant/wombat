/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_COMMON_BOUNDS_HPP
#define WOMBAT_COMMON_BOUNDS_HPP

#include <models/models.hpp>
#include "point.hpp"

namespace wombat {
namespace common {

class Bounds: public models::Bounds {
	public:
		/**
		 * Constructor
		 */
		Bounds();

		/**
		 * Constructor
		 * @param bnds the model::Bounds to build this Bounds off of
		 */
		Bounds(models::Bounds bnds);

		bool intersects(Bounds other) const;

		bool contains(models::Point pt) const;

		bool contains(int x, int y) const;

		int x2() const;

		int y2() const;

		Point pt1();

		Point pt2();
};

}
}

#endif
