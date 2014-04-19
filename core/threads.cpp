#include "core.hpp"
#include "threads.hpp"

namespace wombat {
namespace core {

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

void TaskProcessor::start() {
	if (!m_running) {
		m_running = true;
		startThread([this]() {

			uint64 sleepTime = 0;

			while (m_running) {
				Semaphore::Post post;
				if (sleepTime) {
					post = m_sem.wait();
				} else {
					post = m_sem.wait(sleepTime);
				}

				while (1) {
					switch (post.reason()) {
					case Timeout:
						// Timeout means something wants to run
						{
							auto nt = nextTask();
							if (core::time() > nt.second) {
								auto state = nt.first->run(Timeout);
								schedule(nt.first, state);
							}
						}
						break;
					case ReceivedMessage:
						{
							auto task = post.task();
							auto state = task->run(ReceivedMessage);
							schedule(task, state);
						}
						break;
					default:
						break;
					}

					if (m_sem.hasPosts()) {
						post = m_sem.popPost();
					} else {
						break;
					}
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

std::pair<Task*, uint64> TaskProcessor::nextTask() {
	auto t = m_schedule.back();
	m_schedule.pop_back();
	return t;
}

void TaskProcessor::schedule(Task *task, TaskState state) {
	if (state.state == TaskState::Running) {
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
}

}
}
