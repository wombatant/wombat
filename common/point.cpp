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
#include "point.hpp"

namespace wombat {
namespace common {

Point::Point() {
}

Point::Point(models::Point p) {
	X = p.X;
	Y = p.Y;
}

Point::Point(int x, int y) {
	X = x;
	Y = y;
}

Point Point::operator+(common::Point p) const {
	p.X += X;
	p.Y += Y;
	return p;
}

Point Point::operator-(common::Point p) const {
	p.X -= X;
	p.Y -= Y;
	return p;
}

Point Point::operator*(common::Point p) const {
	p.X *= X;
	p.Y *= Y;
	return p;
}

Point Point::operator/(common::Point p) const {
	p.X /= X;
	p.Y /= Y;
	return p;
}

Point Point::operator+=(common::Point p) {
	X += p.X;
	Y += p.Y;
	return *this;
}

Point Point::operator-=(common::Point p) {
	X -= p.X;
	Y -= p.Y;
	return *this;
}

Point Point::operator*=(common::Point p) {
	X *= p.X;
	Y *= p.Y;
	return *this;
}

Point Point::operator/=(common::Point p) {
	X /= p.X;
	Y /= p.Y;
	return *this;
}


Point Point::operator+(int i) const {
	Point p;
	p.X += i;
	p.Y += i;
	return p;
}

Point Point::operator-(int i) const {
	Point p;
	p.X -= i;
	p.Y -= i;
	return p;
}

Point Point::operator*(int i) const {
	Point p;
	p.X *= i;
	p.Y *= i;
	return p;
}

Point Point::operator/(int i) const {
	Point p;
	p.X /= i;
	p.Y /= i;
	return p;
}

Point Point::operator+=(int i) {
	X += i;
	Y += i;
	return *this;
}

Point Point::operator-=(int i) {
	X -= i;
	Y -= i;
	return *this;
}

Point Point::operator*=(int i) {
	X *= i;
	Y *= i;
	return *this;
}

Point Point::operator/=(int i) {
	X /= i;
	Y /= i;
	return *this;
}

}
}
