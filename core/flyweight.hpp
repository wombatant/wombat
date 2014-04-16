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
#ifndef WOMBAT_CORE_FLYWEIGHT_HPP
#define WOMBAT_CORE_FLYWEIGHT_HPP

#include <map>
#include <string>
#include <functional>
#include "models/enginemodels.hpp"

namespace wombat {
namespace core {

using std::map;
using std::string;
using std::function;

template <class Model>
class Flyweight {
	public:
		class Value {
			friend class Flyweight;
			protected:
				int dependents;
			public:
				virtual ~Value() {};
				virtual string key() = 0;
		};
		class GenericValue: public Value {
			friend class Flyweight;
			protected:
				string m_key;
			public:
				virtual ~GenericValue() {};
				virtual string key() {
					return m_key;
				};
		};
		typedef function<Value*(Model&)> FlyweightNodeBuilder;

	private:
		map<string, Value*> m_cache;
		FlyweightNodeBuilder m_build;

	public:
		Flyweight(FlyweightNodeBuilder build) {
			m_build = build;
		}

		/**
		 * Takes a Model's path as the key.
		 * @param modelPath the path to the model
		 * @return the value associated with the given key
		 */
		Value* checkout(std::string modelPath) {
			Value *v = m_cache[modelPath];
			if (!v) {
				Model key;
				open(key, modelPath);
				m_cache[modelPath] = v = m_build(key);
			}
			if (v) {	
				v->dependents++;
			}
			return v;
		}

		Value* checkout(Model &key) {
			string keyStr = key.toJson();
			Value *v = m_cache[keyStr];
			if (!v) {
				m_cache[keyStr] = v = m_build(key);
			}
			if (v) {	
				v->dependents++;
			}
			return v;
		}

		void checkin(string key) {
			Value *v = m_cache[key];
			checkin(v);
		}

		void checkin(Value *v) {
			v->dependents--;
			if (!v->dependents) {
				m_cache.erase(v->key());
				delete v;
			}
		}
};

}
}

#endif
