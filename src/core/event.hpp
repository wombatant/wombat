/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_CORE_EVENT_HPP
#define WOMBAT_CORE_EVENT_HPP

#include <functional>
#include <iostream>
#include <stdlib.h>
#include "types.hpp"

namespace wombat {
namespace core {

enum class Key {
	Unknown,
	Escape,
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z
};

void main();

class Event {
	friend void ::wombat::core::main();
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
				void *data;
			} other;
			int32_t integer32;
		};

		Type m_type;
		/**
		 * Used to specify the Task that received a message.
		 */
		class Task *m_task = nullptr;
		Body m_body;
		bool m_taskPost = false; // a Event posted through Task::post

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
		 * @param type the value for the type value of the Event
		 * @param integer integer value to send
		 */
		Event(int type, int32_t integer);

		/**
		 * Constructor
		 * @param event Event to copy
		 */
		Event(const Event &event);

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
		int read(int32_t *integer);

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
};

}
}

#endif
