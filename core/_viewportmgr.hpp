#ifndef WOMBAT_CORE__VIEWPORTMGR_HPP
#define WOMBAT_CORE__VIEWPORTMGR_HPP

#include "core.hpp"

namespace wombat {
namespace core {

class ViewportManager {
	private:
		struct Viewport {
			models::Bounds bounds;
			models::Point point;

			Viewport() {}
			Viewport(models::Bounds bounds) {
				this->bounds = bounds;
			}
		};
		std::vector<Viewport> m_viewports;
		int m_pt;

	public:
		/**
		 * Constructor
		 */
		ViewportManager();

		models::Point translate();

		models::Bounds bounds();

		void push(models::Bounds rect);

		void pop();

		void calcBounds();

		void clear();
};

}
}

#endif
