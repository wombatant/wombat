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
#ifndef WOMBAT_CORE_FLYWEIGHT_HPP
#define WOMBAT_CORE_FLYWEIGHT_HPP

#include <map>
#include <string>

namespace wombat {
namespace core {

using std::map;
using std::string;

class FlyweightNode {
	friend class Flyweight;
	protected:
		int dependents;
	public:
		virtual ~FlyweightNode();
		virtual string key() = 0;
};

class Flyweight {
	private:
		map<string, FlyweightNode*> m_cache;
		FlyweightNode *(*m_build)(string);
	public:
		Flyweight(FlyweightNode *(*build)(string));
		FlyweightNode* checkout(string key);
		void checkin(string key);
		void checkin(FlyweightNode *val);
};

}
}

#endif
