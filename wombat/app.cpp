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
#include "app.hpp"

namespace wombat {

using core::TaskState;

App::App() {
	core::prependPath("active_path");
	setAutoDelete(true);
	models::InitFile initFile;
	models::World world;
	models::User user;

	core::read(initFile, "Init");
	core::read(user, initFile.User);
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
	core::subscribe(core::EventType::KeyDown);
	core::subscribe(core::EventType::KeyUp);
	core::subscribe(core::EventType::ScreenSizeChange);
	core::subscribe(core::EventType::Quit);
}

TaskState App::run(core::Event e) {
	TaskState retval = TaskState::Continue;

	switch (e.type()) {
	case core::EventType::ScreenSizeChange:
		core::draw();
		break;
	case core::EventType::Timeout:
		core::draw();
		retval = 16;
		break;
	case core::EventType::Quit:
		quit();
		break;
	case core::EventType::KeyDown:
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
