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
#ifndef WOMBAT_WORLD_WORLD_HPP
#define WOMBAT_WORLD_WORLD_HPP

#include <core/core.hpp>
#include "zone.hpp"

namespace wombat {
namespace world {

class World: public core::Task {
	private:
		core::TaskProcessor m_taskProc;
		std::map<std::string, Zone*> m_zones;

	public:
		/**
		 * Constructor
		 * @param model Model to build the World off of
		 */
		World(models::World model);

		/**
		 * Destructor
		 */
		~World();

		core::TaskState run(core::Event) override;

		/**
		 * Gets the Zone with the given accessor ID.
		 * @param accessorId the accessor ID of the Zone to access
		 * @return the Zone with the given accessor ID
		 */
		Zone *getZone(std::string accessorId);

		/**
		 * Gets the Zones that intersect with the given bounds.
		 * @param bnds the bounds to find intersections with
		 * @return the Zones at the given coordinates
		 */
		void zonesAt(std::vector<Zone*> &zones, common::Bounds bnds);

		/**
		 * Gets the Zone at the given coordinates.
		 * @param x the x coordinate to query on
		 * @param y the y coordinate to query on
		 * @return the Zone at the given coordinates
		 */
		Zone *zoneAt(int x, int y);
};

}
}

#endif
