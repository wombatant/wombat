/*
 * Copyright 2013 gtalent2@gmail.com
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
#ifndef WOMBATCORE_CORE_HPP
#define WOMBATCORE_CORE_HPP

#include <string>
#include <functional>
#include "event.hpp"
#include "gfx.hpp"
#include "types.hpp"

namespace wombat {
namespace core {

/**
 * Initializes graphics, user input, and audio
 * @return 0 if successful
 */
int init(bool fullscreen = true, int w = 800, int h = 600);

void draw();

void main();

void addEventListener(std::function<void (Event)> func);

void addDrawer(Drawer*);

void startThread(std::function<void()> f);

void sleep(uint64 ms);

void debug(std::string);

}
}

#endif
