#ifndef WOMBAT_WORLD_SPRITECLASS_HPP
#define WOMBAT_WORLD_SPRITECLASS_HPP

#include <core/core.hpp>
#include "animlayer.hpp"

namespace wombat {
namespace world {

class SpriteClass {
	private:
		std::vector<std::vector<AnimLayer>> m_anims;
		//int m_spriteType;
		//void *m_attr;

	public:
		void load(models::SpriteClass);
};

}
}

#endif
