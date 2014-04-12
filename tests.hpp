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
#ifndef WOMBAT_TESTS_HPP
#define WOMBAT_TESTS_HPP

#include <string>

#include "core/core.hpp"
#include "models/enginemodels.hpp"

namespace wombat {
namespace tests {

using namespace wombat::core;

class ImageTest: public Drawer {
	private:
		Image *m_img;
	public:
		ImageTest(std::string path);
		void draw(Graphics*);
};

class AnimationTest: public Drawer {
	private:
		models::Animation anim;
	public:
		AnimationTest(std::string path);
		void draw(Graphics*);
};

Drawer *test(std::vector<std::string>&);

}
}

#endif
