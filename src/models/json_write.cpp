/*
 * Copyright 2013-2015 gtalent2@gmail.com
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
	*jv = json_string(v.c_str());
	return Error::Ok;
}

Error writeVal(json_t **jv, ptr v) {
	return writeVal(jv, v.m_key);
}

Error writeVal(json_t **jv, unknown v) {
	*jv = json_incref(v.m_val);
	return Error::Ok;
}

}
}
