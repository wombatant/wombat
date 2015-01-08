/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_MODELS_PTR_HPP
#define WOMBAT_MODELS_PTR_HPP

#include "json_read.hpp"

namespace wombat {
namespace models {

typedef string Path;
const extern Path NullPath;

template<typename Value>
class ptr {
	friend Error fromJson(ptr *model, json_t *jo);
	protected:
		Path m_key;

	public:
		ptr() = default;

	void setKey(Value key) {
		m_key = key;
	}

	Error writeValue(Value val) {
		return Error::Ok;
	}
};

template<typename Value>
inline Error fromJson(ptr<Value> *model, json_t *jo) {
	return readVal(jo, &model->m_key);
}

}
}

#endif
