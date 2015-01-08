/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_CORE__THREADS_HPP
#define WOMBAT_CORE__THREADS_HPP

#include <functional>
#include <map>
#include <queue>

#include "event.hpp"
#include "misc.hpp"
#include "types.hpp"

namespace wombat {
namespace core {

void startThread(std::function<void()> f);

void sleep(uint64 ms);

}
}

#endif
