/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "app.hpp"

namespace wombat {

using core::Event;
using core::Key;
using core::TaskState;

App::App() {
	core::prependPath("active_path");
	setAutoDelete(true);
	models::InitFile initFile;
	models::World world;

	core::read(initFile, "Init");
	core::read(world, initFile.World);
	m_world = new world::World(world);

	m_camera = new world::Camera(m_world);
	m_camera->init(initFile);
	core::addDrawer(m_camera);
	core::addTask(m_camera);
}

App::~App() {
	core::removeDrawer(m_camera);
	delete m_world;
}

void App::init() {
	core::subscribe(Event::KeyDown);
	core::subscribe(Event::KeyUp);
	core::subscribe(Event::ScreenSizeChange);
	core::subscribe(Event::Quit);
}

TaskState App::run(Event e) {
	TaskState retval = TaskState::Continue;

	switch (e.type()) {
	case Event::Quit:
		quit();
		retval = TaskState::Done;
		break;
	case Event::KeyDown:
		switch (e.key()) {
		case Key::Escape:
		case Key::Q:
			quit();
			retval = TaskState::Done;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}

	return retval;
}

void App::quit() {
	core::quit();
}

}
