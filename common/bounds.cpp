/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
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
		contains(b.x2(), b.Y) || contains(b.x2(), b.y2()) ||
		b.contains(X, Y) || b.contains(X, y2()) ||
		b.contains(x2(), Y) || b.contains(x2(), y2());
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

Point Bounds::pt1() {
	return Point(X, Y);
}

Point Bounds::pt2() {
	return Point(x2(), y2());
}

}
}
