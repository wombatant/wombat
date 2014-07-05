/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include <fstream>
#include "modelio.hpp"

namespace wombat {
namespace core {

using namespace models::cyborgbear;

std::vector<std::string> _path({"wombat_path/"});

std::vector<std::string> getPath() {
	return _path;
}

std::string path(Path path) {
	for (auto p : _path) {
		auto val = p + path;
		std::ifstream file(val);
		if (file.good()) {
			return val;
		}
	}
	return _path[0] + path;
}

void prependPath(std::string h) {
	_path.insert(_path.begin(), h + "/");
}

void appendPath(std::string h) {
	_path.push_back(h + "/");
}

/**
 * Adds the given suffix to the given string if it is not already there.
 */
string _suffix(string path, string suffix) {
	if (path.size() < suffix.size() || path.substr(path.size() - suffix.size()) != suffix) {
		path += suffix;
	}
	return path;
}

models::cyborgbear::Error read(models::cyborgbear::Model &m, Path path) {
	using namespace models::cyborgbear;
	auto retval = Error_Ok;

	if (path != core::NullPath) {
		auto p = core::path(_suffix(path, ".json"));
		retval = m.readJsonFile(p);

		if (retval & Error_TypeMismatch) {
			printf("Warning: type mismatch in \"%s\"\n", path.c_str());
		}
		if (retval & Error_GenericParsingError) {
			printf("Warning: generic parsing error in \"%s\"\n", path.c_str());
		}
		if (retval & Error_CouldNotAccessFile) {
			printf("Warning: could not access \"%s\"\n", path.c_str());
		}
	}

	return retval;
}

}
}
