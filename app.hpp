#ifndef WOMBAT_APP_HPP
#define WOMBAT_APP_HPP

#include "core/core.hpp"

namespace wombat {

class App: public core::Task {
	public:
		void init();

		core::TaskState run(core::Event);

	private:
		void quit();
};

}

#endif
