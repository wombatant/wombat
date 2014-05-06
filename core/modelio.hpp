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
#ifndef WOMBAT_CORE_MODELIO_HPP
#define WOMBAT_CORE_MODELIO_HPP

#include <map>
#include <string>
#include <functional>
#include "threads.hpp"
#include "models/enginemodels.hpp"

namespace wombat {
namespace core {

using std::map;
using std::string;
using std::function;

/**
 * Prepends to the path to load models from.
 * Unless another path is prepended to the path, this will be the first
 * directory that files are looked for in.
 * @param path the new path
 */
void prependPath(std::string h);

/**
 * Adds to the path to load models from.
 * This will be the last directory the files are looked for in.
 * @param path the new path
 */
void appendPath(std::string path);

/**
 * Returns the given path with the wombat_home path prepended to it.
 * @param path the of the file to refer to within wombat_home
 * @return the given path with the wombat_home path prepended to it.
 */
std::string path(std::string path);

/**
 * Reads the file at the given path within the path into the given model.
 * @param model the model to load the file into
 * @prarm path the path within the path to read from
 */
uint64 read(models::cyborgbear::Model &model, std::string path);

/**
 * Manages Model IO, preventing redundancies in memory.
 */
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
		core::Mutex m_lock;

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
			m_lock.lock();
			Value *v = m_cache[modelPath];
			if (!v) {
				Model key;
				read(key, modelPath);
				m_cache[modelPath] = v = m_build(key);
			}
			if (v) {	
				v->dependents++;
			}
			m_lock.unlock();
			return v;
		}

		Value* checkout(Model &key) {
			m_lock.lock();
			string keyStr = key.toJson();
			Value *v = m_cache[keyStr];
			if (!v) {
				m_cache[keyStr] = v = m_build(key);
			}
			if (v) {	
				v->dependents++;
			}
			m_lock.unlock();
			return v;
		}

		void checkin(string key) {
			m_lock.lock();
			Value *v = m_cache[key];
			checkin(v);
			m_lock.unlock();
		}

		void checkin(Value *v) {
			m_lock.lock();
			v->dependents--;
			if (!v->dependents) {
				m_cache.erase(v->key());
				delete v;
			}
			m_lock.unlock();
		}
};

}
}

#endif
