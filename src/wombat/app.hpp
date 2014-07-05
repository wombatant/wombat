/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_APP_HPP
#define WOMBAT_APP_HPP

#include <core/core.hpp>
#include <world/camera.hpp>
#include <world/world.hpp>

namespace wombat {

class App: public core::Task {
	private:
		world::World *m_world;

	public:
		/**
		 * Constructor
		 */
		App();
		
		/**
		 * Destructor
		 */
		~App();

		void init() override;

		core::TaskState run(core::Event) override;

	private:
		/**
		 * Runs exit code.
		 */
		void quit();
};

}

#endif
