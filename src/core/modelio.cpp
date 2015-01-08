/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include <fstream>
#include "modelio.hpp"

namespace wombat {
namespace core {

std::vector<std::string> _path({"wombat_path/"});

std::vector<std::string> getPath() {
	return _path;
}

void prependPath(std::string h) {
	_path.insert(_path.begin(), h + "/");
}

void appendPath(std::string h) {
	_path.push_back(h + "/");
}

std::string _suffix(std::string path, std::string suffix) {
	if (path.size() < suffix.size() || path.substr(path.size() - suffix.size()) != suffix) {
		path += suffix;
	}
	return path;
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

}
}
