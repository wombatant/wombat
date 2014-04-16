#include "modelio.hpp"

namespace wombat {
namespace core {

std::string home = "wombat_home/";


std::string getHome() {
	return home;
}

std::string path(std::string path) {
	return home + path;
}

void setHome(std::string h) {
	home = h + "/";
}

int open(models::cyborgbear::Model &m, std::string path) {
	if (path.substr(path.size() - 5) != ".json") {
		path += ".json";
	}
	m.readJsonFile(core::path(path));
	return 0;
}

}
}
