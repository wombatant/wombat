/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_WORLD_CAMERA_HPP
#define WOMBAT_WORLD_CAMERA_HPP

#include <common/common.hpp>
#include <core/core.hpp>
#include "person.hpp"
#include "world.hpp"

namespace wombat {
namespace world {

class Camera: public core::Drawer, public core::Task {
	private:
		common::Bounds m_bounds;
		std::vector<Zone*> m_zones;
		World *m_world = nullptr;
		Person *m_person = nullptr;

	public:
		/**
		 * Constructor
		 */
		Camera(World *world);

		void init() override;

		core::TaskState run(core::Event) override;

		/**
		 * Draws what the Camera is currently hovering over.
		 * @param g the Graphics instance to draw the Camera's sight with
		 */
		void draw(core::Graphics &g) override;

		/**
		 * Gets the bounds of this Camera.
		 * @return the bounds of this Camera
		 */
		common::Bounds bounds();

		/**
		 * Takes an InitFile object to determine where to place the Camera on the map.
		 * @param init the InitFile used to load the application
		 */
		void init(models::InitFile init);

	private:
		void findZones();
		void updateSize();

		void keyDown(core::Event e);

		void keyUp(core::Event e);
};

}
}

#endif