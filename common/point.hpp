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
