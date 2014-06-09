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
#ifndef WOMBAT_CORE_EVENT_HPP
#define WOMBAT_CORE_EVENT_HPP

#include <functional>
#include <stdlib.h>
#include "types.hpp"

namespace wombat {
namespace core {

enum EventType {
	UnknownEvent = 1024,
	Timeout,
	ChannelMessage,
	GenericPost,
	InitTask,
	AppEvent, // Should always be the highest value listed here

	// Optional EventTypes
	QuitEvent = 0,
	KeyUpEvent,
	KeyDownEvent,
	ScreenSizeChange,
	OptionalEventTypeRange
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
		/**
		 * Used to specify the Task that received a message.
		 */
		Task *m_task;
		union {
			Key key;
			void *channel;
			struct {
				int size;
				Task *task;
				void *data;
			} other;
		} m_body;

	public:
		/**
		 * Constructor
		 * @param type the value for the type value of the Event
		 */
		Event(EventType type = UnknownEvent);

		/**
		 * Constructor
		 * @param type the value for the type value of the Event
		 * @param channel pointer to the Channel written to
		 */
		Event(EventType type, void *channel);

		/**
		 * Constructor
		 * @param type the value for the type value of the Event
		 * @param task the Task for the event to reference
		 */
		Event(EventType type, Task *task);

		/**
		 * Constructor
		 * @param event Event to copy
		 */
		Event(const Event &event);

		/**
		 * Constructor
		 * @param val the value that the event carries
		 */
		template<typename T>
		Event(T val) {
			m_body.other.size = sizeof(T);
			m_body.other.data = malloc(m_body.other.size);
			memcpy(m_body.other.data, &val, sizeof(T));
			m_type = AppEvent;
		}

		/**
		 * Constructor
		 * @param type the value for the type value of the Event
		 * @param val the value that the event carries
		 */
		template<typename T>
		Event(EventType type, T val) {
			m_body.other.size = sizeof(T);
			m_body.other.data = malloc(m_body.other.size);
			memcpy(m_body.other.data, &val, sizeof(T));
			m_type = type;
		}

		/**
		 * Destructor
		 */
		~Event();

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
		 * This method assumes type() returns KeyUpEvent, KeyDownEvent, or InitTask.
		 * @return the EventType describing this Event
		 */
		inline Task *task() const {
			return m_task;
		}

		/**
		 * Gets pointer to the Channel this Event is about.
		 * @return pointer to the Channel this Event is about
		 */
		void *channel() {
			return m_body.channel;
		}

		/**
		 * Reads the other data into the given value.
		 * Should only be used if type is >= AppEvent.
		 * @param val reference to the value to write to
		 * @return 0 if successful
		 */
		template<typename T>
		int read(T &val) {
			auto &data = (T*) m_body.other.data;
			if (data && m_body.other.size == sizeof(T)) {
				val = *data;
				free(data);
				data = 0;
				return 0;
			}
			return 1;
		}
};

}
}

#endif
