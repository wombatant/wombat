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

void main();

class Event {
	friend void core::main();
	friend class TaskProcessor;
	protected:
		EventType m_type;
		/**
		 * Used to specify the Task that received a message.
		 */
		class Task *m_task;
		union Body {
			Key key;
			void *channel;
			struct {
				int size;
				void *data;
			} other;
		} m_body;
		std::function<void(void *dest, Body src)> m_copy;
		std::function<void(void *dest)> m_free;

	private:
		static const std::function<void(void *dest, union Body src)> DefaultCopy;
		static const std::function<void(void *dest, union Body src)> AppEventCopy;

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
		Event(EventType type, class Task *task);

		/**
		 * Constructor
		 * @param event Event to copy
		 */
		Event(const Event &event);

		/**
		 * Constructor
		 * @param val the value that the event carries, this needs to be a memcpy friendly type
		 */
		template<typename T>
		Event(T val);

		/**
		 * Constructor
		 * @param type the value for the type value of the Event
		 * @param val the value that the event carries, this needs to be a memcpy friendly type
		 */
		template<typename T>
		Event(EventType type, T val);

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
		inline class Task *task() const {
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
		int read(T &val);

	protected:
		/**
		 * Sets the Task that this Event is meant for.
		 * @param task the Task that this Event is meant for
		 */
		void setTask(class Task *task);

	private:
		void defaultCopy(void *dest, union Event::Body src);

		template<typename T>
		void appEventCopy(void *dest, union Event::Body src);
};

template<typename T>
Event::Event(T val) {
	m_body.other.size = sizeof(T);
	m_body.other.data = new T;
	*((T*) m_body.other.data) = val;
	m_copy = [this](void *dest, Event::Body src) {
		appEventCopy<T>(dest, src);
	};
	m_free = [](void *data) {
		delete (T*) data;
	};
	m_type = AppEvent;
}

template<typename T>
Event::Event(EventType type, T val) {
	m_body.other.size = sizeof(T);
	m_body.other.data = new T;
	*((T*) m_body.other.data) = val;
	m_copy = [this](void *dest, Event::Body src) {
		appEventCopy<T>(dest, src);
	};
	m_free = [](void *data) {
		delete (T*) data;
	};
	m_type = type;
}

template<typename T>
void Event::appEventCopy(void *dest, union Event::Body src) {
	m_body.other.size = src.other.size;
	m_body.other.data = new T;
	*((T*) m_body.other.data) = *((T*) src.other.data);
}

template<typename T>
int Event::read(T &val) {
	auto &data = (T*) m_body.other.data;
	if (data && m_body.other.size == sizeof(T)) {
		val = *data;
		m_free(data);
		data = 0;
		return 0;
	}
	return 1;
}

}
}

#endif
