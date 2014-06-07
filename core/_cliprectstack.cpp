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
#include "gfx.hpp"
#include "_cliprectstack.hpp"

namespace wombat {
namespace core {

ClipRectStack::Viewport::Viewport() {
}

ClipRectStack::Viewport::Viewport(common::Bounds bounds) {
	this->bounds = bounds;
}

ClipRectStack::ClipRectStack() {
	Viewport v;
	v.bounds.X = 0;
	v.bounds.Y = 0;
	v.bounds.Width = 0;
	v.bounds.Height = 0;
	m_viewports.push_back(v);
}

common::Point ClipRectStack::translate() {
	return m_viewports[m_pt].point;
}

common::Bounds ClipRectStack::bounds() {
	return m_viewports[m_pt].bounds;
}

void ClipRectStack::push(common::Bounds rect) {
	m_pt++;
	m_viewports.push_back(rect);
	calcBounds();
}

void ClipRectStack::pop() {
	if (m_pt < 1) {
		return;
	}
	m_viewports.erase(m_viewports.begin() + m_viewports.size() - 1);
	m_pt--;
}

void ClipRectStack::calcBounds() {
	if (m_pt == 0) {
		return;
	}

	auto p = m_viewports[m_pt - 1].bounds;
	auto &n = m_viewports[m_pt].bounds;
	auto &t = m_viewports[m_pt].point;
	t = m_viewports[m_pt - 1].point;
	n.X += p.X;
	n.Y += p.Y;

	if (m_pt == 1) { // base viewport
		p.Width = displayWidth();
		p.Height = displayHeight();
	}

	// make sure the point of origin is not negative
	if (n.X < p.X) {
		t.X = n.X - p.X;
		n.Width -= p.X - n.X;
		n.X = p.X;
		if (n.Width < 0) {
			n.Width = 0;
		}
	}
	if (n.Y < p.Y) {
		t.Y = n.Y - p.Y;
		n.Height -= p.Y - n.Y;
		n.Y = p.Y;
		if (n.Height < 0) {
			n.Height = 0;
		}
	}

	// make sure the point of origin is not beyond the edge
	if (n.X > (p.X + p.Width)) {
		n.X = p.X + p.Width;
	}
	if (n.Y > (p.Y + p.Height)) {
		n.Y = p.Y + p.Height;
	}

	// make sure the new edge is not beyond the old edge
	if ((n.X + n.Width) > (p.X + p.Width)) {
		n.Width = (p.X + p.Width) - n.X;
	}
	if ((n.Y + n.Height) > (p.Y + p.Height)) {
		n.Height = (p.Y + p.Height) - n.Y;
	}
}

void ClipRectStack::clear() {
	m_viewports.erase(m_viewports.begin(), m_viewports.end());
	Viewport v;
	v.bounds.X = 0;
	v.bounds.Y = 0;
	v.bounds.Width = 0;
	v.bounds.Height = 0;
	v.point.X = 0;
	v.point.Y = 0;
	m_viewports.push_back(v);
	m_pt = 0;
	calcBounds();
}

int ClipRectStack::size() {
	return m_pt;
}

}
}
