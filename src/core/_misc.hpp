/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_CORE__MISC_HPP
#define WOMBAT_CORE__MISC_HPP

#include "core.hpp"
#include "task.hpp"

namespace wombat {
namespace core {

/**
 * Gets the time used by the scheduler.
 * This time is not necessarily the actual time.
 * @return the time used by the scheduler
 */
uint64_t _schedTime();

extern BaseEventQueue &_mainEventQueue;

}
}

#endif
