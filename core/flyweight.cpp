/*
 * Copyright 2013 gtalent2@gmail.com
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
#include "flyweight.hpp"

namespace wombat {
namespace core {

Flyweight::Flyweight(FlyweightNode *(*build)(string)) {
	m_build = build;
}

FlyweightNode* Flyweight::checkout(string key) {
	FlyweightNode *v = m_cache[key];
	if (!v) {
		v = m_build(key);
	}
	v->dependents++;
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
