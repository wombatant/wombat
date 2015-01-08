/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "unknown.hpp"

namespace wombat {
namespace models {

unknown::unknown(json_t *jv) {
	m_val = jv;
}

unknown::unknown(const unknown &o) {
	*this = o;
}

unknown::~unknown() {
	if (m_val) {
		json_decref(m_val);
	}
}

unknown &unknown::operator=(const unknown &o) {
	if (o.m_val) {
		json_decref(o.m_val);
	}
	if (m_val) {
		json_incref(m_val);
	}
	m_val = o.m_val;
	return *this;
}

Type unknown::type() {
	auto type = json_typeof(m_val);
	switch (type) {
	case JSON_TRUE:
	case JSON_FALSE:
		return Type::Bool;
	case JSON_INTEGER:
		return Type::Int;
	case JSON_REAL:
		return Type::Int;
	case JSON_STRING:
		return Type::String;
	case JSON_OBJECT:
		return Type::Object;
	default:
		return Type::None;
	}
}

}
}
