#include "textpane.hpp"

namespace wombat {
namespace ui {

void TextPane::draw() {
	static const auto Padding = 8;
	const auto w = core::displayWidth() - (Padding * 2);
	const auto h = 250;
	const auto x = Padding;
	const auto y = (core::displayHeight() - h) - Padding;

	core::pushClipRect(x, y, w, h);

	core::setRGB(64, 42, 12);
	core::fillRect(0, 0, w, h);

	core::setRGB(170, 143, 124);
	core::drawRect(0, 0, w, h);

	if (m_text) {
		core::draw(m_text, 15, 15);
	}

	core::popClipRect();
}

}
}
