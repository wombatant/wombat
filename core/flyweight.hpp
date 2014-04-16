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
using models::cyborgbear::Model;


template <class Model>
class Flyweight {
	public:
		class FlyweightNode {
			friend class Flyweight;
			protected:
				int dependents;
			public:
				virtual ~FlyweightNode() {};
				virtual string key() = 0;
		};
		typedef function<FlyweightNode*(Model&)> FlyweightNodeBuilder;
	private:
		map<string, FlyweightNode*> m_cache;
		FlyweightNodeBuilder m_build;
	public:
		Flyweight(FlyweightNodeBuilder build) {
			m_build = build;
		}

		FlyweightNode* checkout(std::string modelPath) {
			Model m;
			open(m, modelPath);
			return checkout(m);
		}

		FlyweightNode* checkout(Model &key) {
			string keyStr = key.toJson();
			FlyweightNode *v = m_cache[keyStr];
			if (!v) {
				m_cache[keyStr] = v = m_build(key);
			}
			if (v) {	
				v->dependents++;
			}
			return v;
		}

		void checkin(string key) {
			FlyweightNode *v = m_cache[key];
			checkin(v);
		}

		void checkin(FlyweightNode *v) {
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
