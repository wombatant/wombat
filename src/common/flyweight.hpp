/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_COMMON_FLYWEIGHT_HPP
#define WOMBAT_COMMON_FLYWEIGHT_HPP

#include <functional>
#include <map>

namespace wombat {
namespace common {

template <typename Key, typename Value>
class Flyweight {
	private:
		class ValueContainer {
			friend class Flyweight;
			protected:
				Value val;
				int dependents = 0;
			public:
				ValueContainer() = default;

				ValueContainer(Value val) {
					this->val = val;
				}

				virtual ~ValueContainer() {};
		};
		typedef std::function<Value(Key)> FlyweightNodeBuilder;
		typedef std::function<void(Value&)> FlyweightNodeDestroyer;

	private:
		std::map<Key, ValueContainer> m_cache;
		FlyweightNodeBuilder m_build;
		FlyweightNodeDestroyer m_destroy;

	public:
		Flyweight(FlyweightNodeBuilder build) {
			m_build = build;
			m_destroy = [](Value &v) {};
		}

		Flyweight(FlyweightNodeBuilder build, FlyweightNodeDestroyer destroy) {
			m_build = build;
			m_destroy = destroy;
		}

		/**
		 * @param key key to the desired value
		 * @return the value associated with the given key
		 */
		Value checkout(Key key) {
			ValueContainer *v;
			try {
				v = &m_cache.at(key);
			} catch (std::out_of_range) {
				v = &(m_cache[key] = m_build(key));
			}
			v->dependents++;
			return v->val;
		}

		void checkin(Key key) {
			try {
				auto &v = m_cache.at(key);
				v.dependents--;
				if (v.dependents <= 0) {
					m_destroy(v.val);
					m_cache.erase(key);
				}
			} catch (std::out_of_range) {
			}
		}
};

}
}

#endif
