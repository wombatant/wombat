/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include <fstream>
#include "json_read.hpp"

namespace wombat {
namespace models {

Error parseJson(string json, json_t **out) {
	*out = json_loads(json.c_str(), 0, nullptr);
	if (*out) {
		return Error::Ok;
	} else {
		return Error::GenericParsingError;
	}
}

Error parseJsonFile(string path, json_t **out) {
	auto err = Error::CouldNotAccessFile;
	try {
		std::ifstream in;
		in.open(path);
		if (in.is_open()) {
			std::string json((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
			in.close();
			err = parseJson(json, out);
		}
	} catch (...) {
	}
	return err;
}

Error readVal(json_t *jv, int *v) {
	if (json_is_integer(jv)) {
		*v = json_integer_value(jv);
		return Error::Ok;
	}
	return Error::TypeMismatch;
}

Error readVal(json_t *jv, double *v) {
	if (json_is_number(jv)) {
		*v = json_real_value(jv);
		return Error::Ok;
	}
	return Error::TypeMismatch;
}

Error readVal(json_t *jv, bool *v) {
	if (json_is_boolean(jv)) {
		*v = json_boolean_value(jv);
		return Error::Ok;
	}
	return Error::TypeMismatch;
}

Error readVal(json_t *jv, std::string *v) {
	if (json_is_string(jv)) {
		*v = json_string_value(jv);
		return Error::Ok;
	}
	return Error::TypeMismatch;
}

}
}
