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
#ifndef WOMBAT_CORE_TLS_HPP
#define WOMBAT_CORE_TLS_HPP

#include "core.hpp"

namespace wombat {
namespace core {

/**
 * Gets the TaskProcessor running the current Task that is running in 
 * the calling thread.
 * @return the TaskProcessor of the active Task that in calling thread
 */
TaskProcessor *activeTaskProcessor();

}
}

#endif