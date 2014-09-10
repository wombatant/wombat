#ifndef WOMBAT_UI_TEXTPANE_HPP
#define WOMBAT_UI_TEXTPANE_HPP

#include <core/core.hpp>

namespace wombat {
namespace ui {

class TextPane {
	private:
		core::Text *m_text = nullptr;

	public:
		void draw();
};

}
}

#endif
