/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_UI_PKG
#define WOMBAT_UI_PKG

#include "textpane.hpp"
#include "ui.hpp"

#else

#ifndef WOMBAT_UI_UI_HPP
#define WOMBAT_UI_UI_HPP

#include "ui.hpp"

namespace wombat {
namespace ui {

/**
 * Sets up and loads data used by the UI package.
 */
int init();

}
}

#endif
#endif
