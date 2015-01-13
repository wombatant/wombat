/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_UI_TEXTPANE_HPP
#define WOMBAT_UI_TEXTPANE_HPP

#include <core/gfx.hpp>

namespace wombat {
namespace ui {

class TextPane {
	private:
		core::Text *m_text = nullptr;

	public:
		TextPane();

		~TextPane();

		void draw();

		void setText(std::string txt);

		/**
		 * Deletes the current text if there is any.
		 */
		void dumpText();
};

}
}

#endif
