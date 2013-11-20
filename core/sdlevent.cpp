#include <SDL.h>
#include "event.hpp"

namespace wombat {
namespace core {

EventType toEventType(int t) {
	switch (t) {
	case SDL_QUIT:
		return Quit;
	}
	return UnknownEvent;
}

}
}
