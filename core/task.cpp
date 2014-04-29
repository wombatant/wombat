#include "task.hpp"

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

// Task

Task::Task() {
	m_autoDelete = false;
}

Task::~Task() {
}

void Task::setAutoDelete(bool autoDelete) {
	m_autoDelete = true;
}

bool Task::autoDelete() {
	return m_autoDelete;
}

// FunctionTask

FunctionTask::FunctionTask(std::function<TaskState(Event)> func) {
	m_task = func;
	setAutoDelete(false);
}

FunctionTask::~FunctionTask() {
}

TaskState FunctionTask::run(Event e) {
	return m_task(e);
}

// TaskProcessor

TaskProcessor::TaskProcessor() {
	m_running = false;
}

TaskState TaskProcessor::run(Event post) {
	printf("TaskProcessor::run\n");
	switch (post.type()) {
	case Timeout:
		// Timeout means something wants to run
		{
			printf("TaskProcessor::run: Timeout\n");
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
	case ChannelMessage:
		printf("TaskProcessor::run: ChannelMessage\n");
		runTask(post.task(), ChannelMessage);
		break;
	case SemaphorePost:
		// SemaphorePost is already designated for use only as a
		//  sleep refresh in this switch
			printf("TaskProcessor::run: SemaphorePost\n");
		break;
	default:
			printf("TaskProcessor::run: default\n");
		break;
	}

	std::pair<Task*, uint64> nt;
	if (nextTask(nt) == 0) {
		auto time = core::time();
		if (time < nt.second) {
			return nt.second - time;
		} else {
			return 0;
		}
	} else {
		return TaskState::Waiting;
	}
}

void TaskProcessor::addTask(std::function<TaskState(Event)> task, TaskState state) {
	addTask(new FunctionTask(task), state);
}

void TaskProcessor::addTask(Task *task, TaskState state) {
	processTaskState(task, state);

	// post to the semaphore to refresh the sleep time
	m_sem.post();
}

void TaskProcessor::start() {
	if (!m_running) {
		m_running = true;
		startThread([this]() {
			TaskState taskState;
			while (m_running) {
				Event post;
				if (m_schedule.empty()) {
					post = m_sem.wait();
				} else {
					post = m_sem.wait(taskState.sleepDuration);
				}
				taskState = run(post);
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
	std::pair<Task*, uint64> nt;
	m_mutex.lock();
	if (nextTask(nt) == 0) {
		auto time = core::time();
		if (time >= nt.second) {
			m_schedule.pop_back();
			m_mutex.unlock();
			return nt.first;
		}
	}
	return 0;
}

int TaskProcessor::nextTask(std::pair<Task*, uint64> &t) {
	int retval = 0;
	m_mutex.lock();
	if (m_schedule.empty()) {
		retval = 1;
	} else {
		t = m_schedule.back();
	}
	m_mutex.unlock();
	return retval;
}

void TaskProcessor::processTaskState(Task *task, TaskState state) {
	m_mutex.lock();
	switch (state.state) {
	case TaskState::Running:
		{
			const auto wakeup = time() + state.sleepDuration;
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
		break;
	case TaskState::Done:
		if (task->autoDelete()) {
			// remove from schedule
			for (auto i = 0; i < m_schedule.size(); i++) {
				if (m_schedule[i].first == task) {
					m_schedule.erase(m_schedule.begin() + i);
				}
			}

			// actually delete the Task
			delete task;
		}
		break;
	default:
		// do nothing
		break;
	}
	m_mutex.unlock();
}

void TaskProcessor::runTask(Task *task, Event event) {
	auto state = task->run(event);
	processTaskState(task, state);
}

}
}
