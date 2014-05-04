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

class TileClass: public core::Flyweight<models::TileClass>::GenericValue {
	private:
		static core::Flyweight<models::TileClass> c_tileClasses;

	private:
		int m_terrainFlags;
		std::vector<world::AnimLayer> m_upperAnims;
		std::vector<world::AnimLayer> m_lowerAnims;

	public:
		/**
		 * Constructor
		 */
		TileClass();

		/**
		 * Destructor
		 */
		~TileClass();

		void drawLower(core::Graphics *g, int x, int y);

		/**
		 * Checks out the TileClass object stored at the given path.
		 * @param path path of the TileClass to checkout
		 */
		static TileClass *checkout(std::string path);

	private:
		/**
		 * Checks in the given TileClass object.
		 * @param tc TileClass object to checkin
		 */
		static void checkin(TileClass*);

		TileClass(const TileClass&);
		TileClass &operator=(const TileClass&);
};

}
}

#endif
