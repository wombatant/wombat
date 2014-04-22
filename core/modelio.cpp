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
#include "modelio.hpp"

namespace wombat {
namespace core {

using namespace models::cyborgbear;

std::string home = "wombat_home/";


std::string getHome() {
	return home;
}

std::string path(std::string path) {
	return home + path;
}

void setHome(std::string h) {
	home = h + "/";
}

/**
 * Adds the given suffix to the given string if it is not already there.
 */
string _suffix(string path, string suffix) {
	if (path.substr(path.size() - suffix.size()) != suffix) {
		path += suffix;
	}
	return path;
}

int open(models::cyborgbear::Model &m, std::string path) {
	auto retval = m.readJsonFile(core::path(_suffix(path, ".json")));
	if (retval == Error_CouldNotAccessFile) {
		// see if it is in "hidden" model file
		retval = m.readJsonFile(core::path(_suffix(path, ".hjson")));
	};
	return retval;
}

}
}
