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
#ifndef WOMBAT_CORE_CORE_HPP
#define WOMBAT_CORE_CORE_HPP

#include <string>
#include "gfx.hpp"

namespace wombat {
namespace core {

typedef char int8;
typedef unsigned char uint8;
typedef short int16;
typedef unsigned short uint16;
typedef unsigned uint;
typedef long long int64;
typedef unsigned long long uint64;

/**
 * Initializes graphics, user input, and audio
 * @return 0 if successful
 */
int init(bool fullscreen = true, int w = 800, int h = 600);

void addDrawer(Drawer*);

void sleep(uint64 ms);

void debug(std::string);

}
}

#endif
