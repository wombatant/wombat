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
#include <string.h>
#include "core/core.hpp"
#include "models/enginemodels.hpp"
#include "tests.hpp"

using namespace models;
using namespace wombat;

int main(int argc, const char **args) {
	if (core::init(false) != 0) {
		return 1;
	}

	core::Drawer *test = 0;

	if (argc > 1 && !strcmp(args[1], "test")) {
		std::vector<std::string> vargs;
		for (int i = 0; i < argc; i++) {
			vargs.push_back(args[i]);
		}
		tests::test(vargs);
	}

	bool running = true;
	core::addEventListener([&running](core::Event e) {
		if (e.type == core::Quit) {
			running = false;
		}
	});
	while (running) {
		// draw
		core::pollEvents();
		core::draw();
		core::sleep(16);
	}

	if (test)
		delete test;

	return 0;
}
