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
#include "bounds.hpp"

namespace wombat {
namespace common {

Bounds::Bounds() {
}

Bounds::Bounds(models::Bounds bnds) {
	X = bnds.X;
	Y = bnds.Y;
	Width = bnds.Width;
	Height = bnds.Height;
}

bool Bounds::intersects(Bounds b) const {
	return contains(b.X, b.Y) || contains(b.X, b.y2()) ||
		contains(b.x2(), b.Y) || contains(b.x2(), b.y2());
}

bool Bounds::contains(int x, int y) const {
	return x >= X && y >= Y && x <= x2() && y <= y2();
}

bool Bounds::contains(models::Point p) const {
	return p.X >= X && p.Y >= Y && p.X <= x2() && p.Y <= y2();
}

int Bounds::x2() const {
	return X + Width;
}

int Bounds::y2() const {
	return Y + Height;
}

}
}
