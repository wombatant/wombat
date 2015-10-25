/*
 * Copyright 2013-2015 gtalent2@gmail.com
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

using namespace wombat::models;
using namespace wombat;
using core::TaskState;

const auto SettingsPath = "settings.json";

class ClArgs {
	private:
		std::map<std::string, bool> m_args;

	public:
		ClArgs(int argc, const char **args);

		bool operator[](std::string arg);
};

ClArgs::ClArgs(int argc, const char **args) {
	for (int i = 0; i < argc; i++) {
		std::string arg = args[i];
		if (arg[0] == '-') {
			while (arg[0] == '-' && arg.size()) {
				arg = arg.substr(1);
			}
			m_args[arg] = true;
		}
	}
}

bool ClArgs::operator[](std::string arg) {
	return m_args[arg];
}

Settings loadSettings(Path path) {
	Settings settings;
	if (readJsonFile(&settings, path) != Error::Ok) {
		settings.Fullscreen = false;
		settings.Width = 800;
		settings.Height = 600;
		writeJsonFile(settings, path);
	}
	return settings;
}

int run(ClArgs args) {
	core::debugOn(args["debug"]);
	auto settings = loadSettings(SettingsPath);
	// init subsystems
	if (core::init(settings) != 0) {
		return 1;
	}
	if (ui::init() != 0) {
		return 2;
	}

	// start app
	core::addTask(new App());
	core::main();

	// save current settings and exit
	writeJsonFile(settings, SettingsPath);
	return 0;
}

int main(int argc, const char **args) {
	return run(ClArgs(argc, args));
}
