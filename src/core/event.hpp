/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_CORE_EVENT_HPP
#define WOMBAT_CORE_EVENT_HPP

#include <functional>
#include <stdlib.h>
#include "types.hpp"

namespace wombat {
namespace core {

enum class Key {
	Unknown,
	Escape,
	A,
	D,
	H,
	J,
	K,
	L,
	Q,
	S,
	W,
};

void main();

class Event {
	friend void core::main();
	friend class Task;
	friend class TaskProcessor;
	public:
		enum Type {
			UnknownEvent = 1024,
			Timeout,
			ChannelMessage,
			GenericPost,
			InitTask,
			FinishTask,
			AppEvent, // Should always be the highest value listed here

			// Optional EventTypes
			Quit = 0,
			KeyUp,
			KeyDown,
			ScreenSizeChange,
			OptionalEventTypeRange
		};

	private:
		union Body {
			Key key;
			void *channel;
			struct {
				int size;
				void *data;
			} other;
		};
		typedef std::function<void(Event*, void*, Body)> Copier;
		static const Copier DefaultCopy;
		static const std::function<void(void*)> DefaultFree;
		Type m_type;
		/**
		 * Used to specify the Task that received a message.
		 */
		class Task *m_task = nullptr;
		Body m_body;
		bool m_taskPost = false; // a Event posted through Task::post
		Copier m_copy = DefaultCopy;
		std::function<void(void *dest)> m_free = DefaultFree;

	public:
		/**
		 * Constructor
		 * @param type the value for the type value of the Event
		 */
		Event(Type type = Event::UnknownEvent);

		/**
		 * Constructor
		 * @param type the value for the type value of the Event
		 * @param channel pointer to the Channel written to
		 */
		Event(int type, void *channel);

		/**
		 * Constructor
		 * @param type the value for the type value of the Event
		 * @param task the Task for the event to reference
		 */
		Event(int type, class Task *task);

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
		explicit Event(T val);

		/**
		 * Constructor
		 * @param type the value for the type value of the Event
		 * @param val the value that the event carries, this needs to be a memcpy friendly type
		 */
		template<typename T>
		Event(int type, T val);

		/**
		 * Destructor
		 */
		~Event();

		/**
		 * Gets the Type describing this Event.
		 * @return the Type describing this Event
		 */
		inline Type type() const {
			return m_type;
		}

		/**
		 * Gets the Key associated with this Event.
		 * This method assumes type() returns KeyUpEvent or KeyDownEvent.
		 * @return the Type describing this Event
		 */
		inline Key key() const {
			return m_body.key;
		}

		/**
		 * Gets the Task this Event is for.
		 * This method assumes type() returns KeyUpEvent, KeyDownEvent, or InitTask.
		 * @return the Type describing this Event
		 */
		inline class Task *task() const {
			return m_task;
		}

		/**
		 * Gets pointer to the Channel this Event is about.
		 * @return pointer to the Channel this Event is about
		 */
		inline void *channel() const {
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

		/**
		 * Sets whether or not this is the result of a Task::post.
		 * @param taskPost whether or not this is the result of a Task::post
		 */
		void setTaskPost(bool taskPost = true);

		/**
		 * Gets whether or not this is the result of a Task::post.
		 * @return whether or not this is the result of a Task::post
		 */
		bool getTaskPost();

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
	m_copy = [](Event *me, void *dest, Event::Body src) {
		me->appEventCopy<T>(dest, src);
	};
	m_free = [](void *data) {
		delete (T*) data;
	};
	m_type = Event::AppEvent;
}

template<typename T>
Event::Event(int type, T val) {
	m_body.other.size = sizeof(T);
	m_body.other.data = new T;
	*((T*) m_body.other.data) = val;
	m_copy = [](Event *me, void *dest, Event::Body src) {
		me->appEventCopy<T>(dest, src);
	};
	m_free = [](void *data) {
		delete (T*) data;
	};
	m_type = (Event::Type) type;
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
