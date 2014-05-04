#ifndef WOMBAT_CORE__CLIPRECTSTACK_HPP
#define WOMBAT_CORE__CLIPRECTSTACK_HPP

#include "core.hpp"

namespace wombat {
namespace core {

class ClipRectStack {
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
		ClipRectStack();

		models::Point translate();

		models::Bounds bounds();

		void push(models::Bounds rect);

		void pop();

		void calcBounds();

		void clear();

		int size();
};

}
}

#endif
