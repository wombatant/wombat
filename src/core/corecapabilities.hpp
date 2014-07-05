/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_CORE_CORECAPABILITIES_HPP
#define WOMBAT_CORE_CORECAPABILITIES_HPP

namespace wombat {
namespace core {

// This may seem like something that should use the preprocessor, but 
//  executables linking with the library don't care about the #defines set
//  when the executable is built, they need to know the #defines set when the
//  library was built. This just eliminates a very painful class of bugs.

extern const bool SupportsThreads;

}
}

#endif
