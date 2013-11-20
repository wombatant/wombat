#ifndef WOMBATCORE_EVENT_HPP
#define WOMBATCORE_EVENT_HPP

namespace wombat {
namespace core {

enum EventType {
	UnknownEvent = -1,
	Quit,
};

EventType toEventType(int);

class Event {
public:
	EventType type;
};

}
}

#endif
