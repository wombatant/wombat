#include "tileclass.hpp"

#ifndef WOMBAT_WORLD_TILE_HPP
#define WOMBAT_WORLD_TILE_HPP

namespace wombat {
namespace world {

class Tile {
	private:
		TileClass *tileClass;
	
	public:
		void draw(core::Graphics gfx, models::Point pt);
};

}
}

#endif
