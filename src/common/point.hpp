/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_COMMON_POINT_HPP
#define WOMBAT_COMMON_POINT_HPP

#include <models/models.hpp>

namespace wombat {
namespace common {

class Point: public models::Point {
	public:
		Point();

		Point(models::Point);

		Point(int x, int y);

		Point operator+(common::Point p) const;

		Point operator-(common::Point p) const;

		Point operator*(common::Point p) const;

		Point operator/(common::Point p) const;


		Point operator+=(common::Point p);

		Point operator-=(common::Point p);

		Point operator*=(common::Point p);

		Point operator/=(common::Point p);


		Point operator+(int i) const;

		Point operator-(int i) const;

		Point operator*(int i) const;

		Point operator/(int i) const;


		Point operator+=(int i);

		Point operator-=(int i);

		Point operator*=(int i);

		Point operator/=(int i);
};

}
}

#endif
