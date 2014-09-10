/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include <string.h>
#include <core/core.hpp>
#include <ui/ui.hpp>
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

	if (ui::init() != 0) {
		return 2;
	}

	core::Drawer *test = nullptr;

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
		core::addTask(new App());
	}

	core::main();

	if (test)
		delete test;

	settings.writeJsonFile(SettingsPath, models::cyborgbear::Readable);

	return 0;
}
