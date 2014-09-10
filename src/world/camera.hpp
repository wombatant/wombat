/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_WORLD_CAMERA_HPP
#define WOMBAT_WORLD_CAMERA_HPP

#include <core/core.hpp>
#include <ui/ui.hpp>
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
		ui::TextPane m_textPane;

	public:
		/**
		 * Constructor
		 */
		Camera(World *world);

		void init() override;

		core::TaskState run(core::Event) override;

		/**
		 * Draws what the Camera is currently hovering over.
		 */
		void draw() override;

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

		void keyEvent(core::Event e);
};

}
}

#endif
