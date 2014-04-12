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
#include "core.hpp"
#include "flyweight.hpp"

namespace wombat {
namespace core {

Flyweight::Flyweight(FlyweightNode *(*build)(models::cyborgbear::Model&)) {
	m_build = build;
}

FlyweightNode::~FlyweightNode() {
}

FlyweightNode* Flyweight::checkout(models::cyborgbear::Model &key) {
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

void Flyweight::checkin(string key) {
	FlyweightNode *v = m_cache[key];
	checkin(v);
}

void Flyweight::checkin(FlyweightNode *v) {
	v->dependents--;
	if (!v->dependents) {
		m_cache.erase(v->key());
		delete v;
	}
}

}
}
