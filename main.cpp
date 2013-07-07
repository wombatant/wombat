/*
 * Copyright 2013 gtalent2@gmail.com
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
#include "core/core.hpp"
#include "models/enginemodels.hpp"
#include "tests.hpp"

using namespace models;
using namespace wombat;
using namespace tests;

int main(int argc, const char **args) {
	if (core::init(0, 800, 600))
		return 1;
	ImageTest imgTest("tests/boxman.json");
	core::addDrawer(&imgTest);
	while (1)
		core::sleep(200);
	return 0;
}
