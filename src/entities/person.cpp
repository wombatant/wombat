#include "person.hpp"

namespace wombat {
namespace entities {

std::string Person::name() {
	return "";
}

void Person::name(std::string name) {
}

std::vector<Creature*> Person::creatures() {
	return m_creatures;
}

void Person::creatures(std::vector<Creature*> creatures) {
	m_creatures = creatures;
}

}
}
