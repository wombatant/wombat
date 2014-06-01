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
	core::read(world, user.World);
	m_world = new world::World(world);

	auto camera = new world::Camera(m_world);
	core::addDrawer(camera);
	core::addTask(camera);

	core::addTask(this);
}

App::~App() {
	delete m_world;
}

void App::init() {
	core::subscribe(core::KeyDownEvent);
	core::subscribe(core::KeyUpEvent);
	core::subscribe(core::ScreenSizeChange);
	core::subscribe(core::QuitEvent);
}

TaskState App::run(core::Event e) {
	TaskState retval = TaskState::Continue;

	switch (e.type()) {
	case core::ScreenSizeChange:
		core::draw();
		break;
	case core::Timeout:
		core::draw();
		retval = 16;
		break;
	case core::QuitEvent:
		quit();
		break;
	case core::KeyDownEvent:
		switch (e.key()) {
		case core::Key_Escape:
		case core::Key_Q:
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
