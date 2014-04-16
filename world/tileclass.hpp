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
#ifndef WOMBAT_WORLD_TILECLASS_HPP
#define WOMBAT_WORLD_TILECLASS_HPP

#include <string>
#include "core/core.hpp"
#include "animlayer.hpp"

namespace wombat {
namespace world {

using std::string;
using std::vector;
using core::Flyweight;

class TileClass: public Flyweight<models::TileClass>::GenericValue {
	private:
		static Flyweight<models::TileClass> tileClasses;

	private:
		int m_terrainFlags;
		vector<world::AnimLayer> m_upperAnims;
		vector<world::AnimLayer> m_lowerAnims;

	public:
		/**
		 * Checks out the TileClass object stored at the given path.
		 * @param path path of the TileClass to checkout
		 */
		static TileClass *checkout(string path);

		/**
		 * Checks in the given TileClass object.
		 * @param tc TileClass object to checkin
		 */
		static void checkin(TileClass*);
};

}
}

#endif
