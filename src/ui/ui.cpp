#include <core/core.hpp>
#include "ui.hpp"

namespace wombat {
namespace ui {

core::Font *_font = nullptr;

int init() {
	models::Font font;
	auto err = core::read(font, "Misc/Font");

	if (err) {
		return 1;
	}

	_font = new core::Font(font);

	if (!_font->good()) {
		return 2;
	}

	return 0;
}

}
}
