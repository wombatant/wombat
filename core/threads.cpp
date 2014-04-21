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
#include "core.hpp"
#include "threads.hpp"

namespace wombat {
namespace core {

// TaskState

TaskState::TaskState(uint64 sleep) {
	state = Running;
	sleepDuration = sleep;
}

TaskState::TaskState(TaskState::State state) {
	this->state = state;
	sleepDuration = 0;
}

// Semaphore

Semaphore::Post::Post(WakeupReason reason) {
	m_task = 0;
	m_reason = reason;
}

WakeupReason Semaphore::Post::reason() {
	return m_reason;
}

bool Semaphore::hasPosts() {
	return !m_posts.empty();
}

// TaskProcessor

void TaskProcessor::addTask(Task *task) {
	processTaskState(task, TaskState(TaskState::Running));

	// post to the semaphore to refresh the sleep time
	m_sem.post();
}

void TaskProcessor::start() {
	if (!m_running) {
		m_running = true;
		startThread([this]() {

			uint64 sleepTime = 0;

			while (m_running) {
				Semaphore::Post post;
				if (m_schedule.empty()) {
					post = m_sem.wait();
				} else {
					post = m_sem.wait(sleepTime);
				}

				while (1) {
					switch (post.reason()) {
					case Timeout:
						// Timeout means something wants to run
						{
							while (1) {
								auto nt = popActiveTask();
								if (nt) {
									runTask(nt, Timeout);
								} else {
									break;
								}
							}
						}
						break;
					case ReceivedMessage:
						runTask(post.task(), ReceivedMessage);
						break;
					case SemaphorePost:
						// SemaphorePost is already designated for use only as a
						//  sleep refresh in this switch
					default:
						break;
					}

					if (m_sem.hasPosts()) {
						post = m_sem.popPost();
					} else {
						break;
					}
				}

				auto time = core::time();
				auto nt = nextTask();
				if (time > nt.second) {
					sleepTime = time - nt.second;
				} else {
					sleepTime = 0;
				}
			}
			m_done.write(true);
		});
	}
}

void TaskProcessor::stop() {
	m_running = false;
}

void TaskProcessor::done() {
	m_done.read();
}

Task *TaskProcessor::popActiveTask() {
	auto nt = nextTask();
	auto time = core::time();
	if (time >= nt.second) {
		m_mutex.lock();
		m_schedule.pop_back();
		m_mutex.unlock();
		return nt.first;
	}
	return 0;
}

std::pair<Task*, uint64> TaskProcessor::nextTask() {
	m_mutex.lock();
	auto t = m_schedule.back();
	m_mutex.unlock();
	return t;
}

void TaskProcessor::processTaskState(Task *task, TaskState state) {
	m_mutex.lock();
	switch (state.state) {
	case TaskState::Running:
		{
			const auto wakeup = time() - state.sleepDuration;
			const auto val = std::pair<Task*, uint64>(task, wakeup);

			bool inserted = false;
			for (auto i = m_schedule.begin(); i < m_schedule.end(); i++) {
				if (wakeup > i->second) {
					m_schedule.insert(i, val);
					inserted = true;
				}
			}

			if (!inserted) {
				m_schedule.push_back(val);
			}
		}
	case TaskState::Done:
	default:
		// do nothing
		break;
	}
	m_mutex.unlock();
}

void TaskProcessor::runTask(Task *task, WakeupReason reason) {
	auto state = task->run(reason);
	processTaskState(task, state);
}

}
}
