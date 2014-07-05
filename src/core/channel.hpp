/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_CORE_CHANNEL_HPP
#define WOMBAT_CORE_CHANNEL_HPP

#include "misc.hpp"
#include "sync.hpp"

namespace wombat {
namespace core {

template<typename T>
class Channel {
	private:
		EventQueue *m_sem = nullptr;
		Mutex m_mutex;
		std::queue<T> m_msgs;

	public:
		/**
		 * Constructor
		 * @param sem the EventQueue for this Channel to listen on
		 */
		Channel(EventQueue *sem = new EventQueue()) {
			m_sem = sem;
		}

		/**
		 * Destructor
		 */
		~Channel() {
			if (m_sem) {
				delete m_sem;
			}
		}

	private:
		/**
		 *
		 * @return indicates whether or not a message was retrieved
		 */
		bool getMessage(T &msg) {
			bool retval = false;
			m_mutex.lock();
			if (!m_msgs.empty) {
				msg = m_msgs.front();
				m_msgs.pop();
				retval = true;
			}
			m_mutex.unlock();
			return retval;
		}

	public:
		/**
		 * Waits until a message is received, then discards the message.
		 * @return reason for the wake up
		 */
		EventType read() {
			auto reason = m_sem->wait().type();
			if (reason == EventType::ChannelMessage) {
				m_mutex.lock();
				m_msgs.pop();
				m_mutex.unlock();
			}
			return reason;
		}

		/**
		 * Read will wait until a message is received, then write it to the given
		 * destination.
		 * @param msg reference to the message to write to
		 * @return reason for the wake up
		 */
		EventType read(T &msg) {
			while (1) {
				auto reason = m_sem->wait().type();
				if (reason == EventType::ChannelMessage) {
					if (getMessage(msg)) {
						return reason;
					}
				} else {
					return reason;
				}
			}
		}

		/**
		 * Read will wait until a message is received, then write it to the given
		 * destination.
		 * @param msg reference to the message to write to
		 * @param timeout timeout duration to give up on
		 * @return reason for the wake up
		 */
		EventType read(T &msg, uint64 timeout) {
			auto startTime = core::time();
			auto currentTimeout = timeout;
			while (1) {
				auto reason = m_sem->wait(currentTimeout).type();
				if (reason == EventType::ChannelMessage) {
					if (getMessage(msg)) {
						return reason;
					}
				} else {
					return reason;
				}
				currentTimeout = timeout - (time() - startTime);
			}
		}

		/**
		 * Writes the given message to the message queue and wakes up any thread
		 * waiting for a message.
		 * @param msg the message to write
		 */
		void write(T msg) {
			m_mutex.lock();
			m_msgs.push(msg);
			m_mutex.unlock();
			m_sem->post(Event(EventType::ChannelMessage, this));
		}

	// disallow copying
	private:
		Channel(const Channel&);
		Channel &operator=(const Channel&);
};

}
}

#endif
