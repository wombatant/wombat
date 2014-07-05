/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "app.hpp"

namespace wombat {

using core::EventType;
using core::TaskState;

App::App() {
	core::prependPath("active_path");
	setAutoDelete(true);
	models::InitFile initFile;
	models::World world;

	core::read(initFile, "Init");
	core::read(world, initFile.World);
	m_world = new world::World(world);

	auto camera = new world::Camera(m_world);
	camera->init(initFile);
	core::addDrawer(camera);
	core::addTask(camera);

	core::addTask(this);
}

App::~App() {
	delete m_world;
}

void App::init() {
	core::subscribe(EventType::KeyDown);
	core::subscribe(EventType::KeyUp);
	core::subscribe(EventType::ScreenSizeChange);
	core::subscribe(EventType::Quit);
}

TaskState App::run(core::Event e) {
	TaskState retval = TaskState::Continue;

	switch (e.type()) {
	case EventType::ScreenSizeChange:
		core::draw();
		break;
	case EventType::Timeout:
		core::draw();
		retval = 16;
		break;
	case EventType::Quit:
		quit();
		break;
	case EventType::KeyDown:
		switch (e.key()) {
		case core::Key::Escape:
		case core::Key::Q:
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
