/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_CORE__CLIPRECTSTACK_HPP
#define WOMBAT_CORE__CLIPRECTSTACK_HPP

#include "core.hpp"

namespace wombat {
namespace core {

class ClipRectStack {
	private:
		struct Viewport {
			common::Bounds bounds;
			common::Point point;

			Viewport();
			Viewport(common::Bounds bounds);
		};
		std::vector<Viewport> m_viewports;
		int m_pt;

	public:
		/**
		 * Constructor
		 */
		ClipRectStack();

		common::Point translate();

		common::Bounds bounds();

		void push(common::Bounds rect);

		void pop();

		void calcBounds();

		void clear();

		int size();
};

}
}

#endif
