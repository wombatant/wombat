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
#include <string.h>
#include "core/core.hpp"
#include "models/enginemodels.hpp"
#include "tests.hpp"

using namespace models;
using namespace wombat;

core::TaskProcessor *tp;

void quit() {
	tp->stop();
	delete tp;
	core::quit();
}

int main(int argc, const char **args) {
	if (core::init(false, 1024, 768) != 0) {
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

	tp = new core::TaskProcessor();
	tp->addTask([](core::Event e) {
		core::draw();
		return core::running() ? 16 : core::TaskState::Done;
	});
	tp->start();

	core::addEventHandler([](core::Event &e) {
		switch (e.type) {
		case core::QuitEvent:
			quit();
			break;
		case core::KeyDownEvent:
			switch (e.key) {
			case core::Key_Escape:
			case core::Key_Q:
				core::quit();
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	});

	core::main();

	if (test)
		delete test;

	return 0;
}
