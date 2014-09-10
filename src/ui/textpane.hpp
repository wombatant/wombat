#ifndef WOMBAT_UI_TEXTPANE_HPP
#define WOMBAT_UI_TEXTPANE_HPP

#include <core/core.hpp>

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
