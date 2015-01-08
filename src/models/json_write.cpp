/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "json_write.hpp"

namespace wombat {
namespace models {

Error writeVal(json_t **jv, int v) {
	*jv = json_integer(v);
	return Error::Ok;
}

Error writeVal(json_t **jv, double v) {
	*jv = json_real(v);
	return Error::Ok;
}

Error writeVal(json_t **jv, bool v) {
	*jv = json_boolean(v);
	return Error::Ok;
}

Error writeVal(json_t **jv, std::string v) {
	*jv = json_stringn(v.c_str(), v.size());
	return Error::Ok;
}

}
}
