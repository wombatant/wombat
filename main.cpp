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
#include <core/core.hpp>
#include "app.hpp"
#include "tests.hpp"

using namespace models;
using namespace wombat;
using core::TaskState;

const auto SettingsPath = "settings.json";

int main(int argc, const char **args) {
	models::Settings settings;
	if (settings.readJsonFile(SettingsPath) != 0) {
		settings.Fullscreen = false;
		settings.Width = 800;
		settings.Height = 600;
		settings.writeJsonFile(SettingsPath, models::cyborgbear::Readable);
	}

	if (core::init(settings) != 0) {
		return 1;
	}

	core::Drawer *test = 0;

	if (argc > 1 && !strcmp(args[1], "test")) {
		std::vector<std::string> vargs;
		for (int i = 0; i < argc; i++) {
			vargs.push_back(args[i]);
		}
		test = tests::test(vargs);

		if (test) {
			core::addDrawer(test);
		}
	} else {
		new App();
	}

	core::main();

	if (test)
		delete test;

	settings.writeJsonFile(SettingsPath, models::cyborgbear::Readable);

	return 0;
}
