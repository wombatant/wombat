/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_MODELS_TYPES_HPP
#define WOMBAT_MODELS_TYPES_HPP

#include <array>
#include <map>
#include <string>
#include <vector>
#include <cstdint>
#include <jansson.h>

namespace wombat {
namespace models {

typedef std::string string;
typedef std::int64_t int64_t;

enum class Error: std::uint64_t {
	Ok = 0,
	TypeMismatch = 1,
	MissingField = 2,
	CouldNotAccessFile = 4,
	GenericParsingError = 8
};

inline Error operator^(Error a, Error b) {
	return (Error) (((uint64_t) a) ^ ((uint64_t) b));
}

inline Error operator|(Error a, Error b) {
	return (Error) (((uint64_t) a) | ((uint64_t) b));
}

inline Error operator&(Error a, Error b) {
	return (Error) (((uint64_t) a) & ((uint64_t) b));
}

inline const Error &operator^=(Error &a, Error b) {
	return a = a ^ b;
}

inline const Error &operator|=(Error &a, Error b) {
	return a = a | b;
}

inline const Error &operator&=(Error &a, Error b) {
	return a = a & b;
}

enum class Type {
	None,
	Bool,
	Int,
	Double,
	String,
	Object
};

class Model {
};

}
}

#endif
