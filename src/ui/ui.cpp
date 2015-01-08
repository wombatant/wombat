/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include <core/core.hpp>
#include "ui.hpp"

namespace wombat {
namespace ui {

using models::Error;
core::Font *_font = nullptr;

int init() {
	models::Font font;
	auto err = core::read(font, "Misc/Font");

	if (err != Error::Ok) {
		return 1;
	}

	_font = new core::Font(font);

	if (!_font->good()) {
	cout << "Narf!\n";
		return 2;
	}

	return 0;
}

}
}
