/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
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
