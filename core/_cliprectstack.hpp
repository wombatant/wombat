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
