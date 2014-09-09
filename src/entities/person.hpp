#ifndef WOMBAT_ENTITIES_PERSON_HPP
#define WOMBAT_ENTITIES_PERSON_HPP

#include <string>
#include <vector>
#include "creature.hpp"

namespace wombat {
namespace entities {

class Person {
	private:
		std::vector<Creature*> m_creatures;

	public:
		std::string name();
		void name(std::string name);

		std::vector<Creature*> creatures();
		void creatures(std::vector<Creature*> creatures);
};

}
}

#endif
