/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef WOMBATCORE_EVENT_HPP
#define WOMBATCORE_EVENT_HPP

#include <functional>

namespace wombat {
namespace core {

enum EventType {
	UnknownEvent   = 1,
	SemaphorePost  = 2 * UnknownEvent,
	Timeout        = 2 * SemaphorePost,
	ChannelMessage = 2 * Timeout,
	QuitEvent      = 2 * ChannelMessage,
	KeyUpEvent     = 2 * QuitEvent,
	KeyDownEvent   = 2 * KeyUpEvent
};

enum Key {
	Key_Unknown,
	Key_Escape,
	Key_A,
	Key_Q,
};

class Task;

void main();

class Event {
	friend void main();
	protected:
		EventType m_type;
		union {
			/**
			 * Used to specify the Task that received a message.
			 */
			Task *task;
			Key key;
		} m_body;

	public:
		/**
		 * Constructor
		 * @param type the value for the type value of the Event
		 */
		Event(EventType type = UnknownEvent);

		/**
		 * Gets the EventType describing this Event.
		 * @return the EventType describing this Event
		 */
		inline EventType type() const {
			return m_type;
		}

		/**
		 * Gets the Key associated with this Event.
		 * This method assumes type() returns KeyUpEvent or KeyDownEvent.
		 * @return the EventType describing this Event
		 */
		inline Key key() const {
			return m_body.key;
		}

		/**
		 * Gets the Task this Event is for.
		 * This method assumes type() returns KeyUpEvent or KeyDownEvent.
		 * @return the EventType describing this Event
		 */
		inline Task *task() const {
			return m_body.task;
		}
};

typedef std::function<void(const Event&)> EventHandler;

void addEventHandler(EventHandler func);

}
}

#endif
