#ifndef WOMBAT_UI_PKG
#define WOMBAT_UI_PKG

#include "ui.hpp"
#include "textpane.hpp"

#else

#ifndef WOMBAT_UI_UI_HPP
#define WOMBAT_UI_UI_HPP

#include "textpane.hpp"

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
