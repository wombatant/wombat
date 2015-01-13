/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_MODELS_UNKNOWN_HPP
#define WOMBAT_MODELS_UNKNOWN_HPP

#include "types.hpp"

namespace wombat {
namespace models {

class unknown {
	friend Error writeVal(json_t **jv, unknown v);
	friend Error readVal(json_t *jv, unknown *v);
	protected:
		json_t *m_val = nullptr;

	public:

		unknown() = default;

		unknown(json_t *jv);

		unknown(const unknown&);

		~unknown();

		unknown &operator=(const unknown&);

		template<typename T>
		Error getVal(T *val);

		template<typename T>
		Error setVal(T val);

		Type type();

		bool operator==(const unknown &o) const {
			return json_equal(m_val, o.m_val);
		}

		bool operator!=(const unknown &o) const {
			return !json_equal(m_val, o.m_val);
		}

};

template<typename T>
Error unknown::getVal(T *val) {
	return readVal(m_val, val);
}

template<typename T>
Error unknown::setVal(T val) {
	return writeVal(&m_val, val);
}

}
}

#endif
