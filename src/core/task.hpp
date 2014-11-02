/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_CORE_TASK_HPP
#define WOMBAT_CORE_TASK_HPP

#include "_submgr.hpp"
#include "channel.hpp"
#include "event.hpp"
#include "types.hpp"

namespace wombat {
namespace core {

/**
 * Subscribes to events of the given type. This must be run from within
 * the Task it is called for.
 * @param et the Event::Type to subscribe to
 * @return 0 if success
 */
int subscribe(Event::Type et);
		
class TaskState {
	public:
		enum State {
			/**
			 * This option tell the TaskProcessor not to change any thing about the Task's state.
			 */
			Continue = 0,
			Running,
			Waiting,
			Done
		};

		State state = Continue;

		/**
		 * Time (milliseconds) til the Task wants to run again.
		 */
		uint64 sleepDuration = 0;

		/**
		 * Constructor
		 * @param state state of task, defaults to Waiting
		 */
		TaskState(State state = Continue);

		/**
		 * Constructor
		 * State is set to Running.
		 * @param sleep time to sleep in milliseconds
		 */
		TaskState(uint64 sleep);
};

class Task {
	friend class TaskProcessor;
	private:
		bool m_autoDelete = false;
		class TaskProcessor *m_taskProcessor = nullptr;

	public:
		/**
		 * Destructor
		 */
		virtual ~Task();

		/**
		 * Posts an Event for this Task to receive.
		 * @param event Event for this Task to receive
		 */
		void post(Event event);

		virtual void init();

		virtual TaskState run(Event) = 0;

	protected:
		/**
		 * Sets whether or not the Task should be auto-deleted when it completes.
		 * @param autoDelete whether or not the Task should be auto-deleted when it completes
		 */
		void setAutoDelete(bool autoDelete);

		/**
		 * Indicates whether or not the Task should be auto-deleted when it completes.
		 * @return value indicating whether or not the Task should be auto-deleted when it completes
		 */
		bool autoDelete();

		/**
		 * Used internally by core to set the TaskProcessor that manages this Task.
		 * @param tp the TaskProcessor that manages this Task
		 */
		void _setTaskProcessor(class TaskProcessor *tp);
};

class FunctionTask: public Task {
	private:
		std::function<TaskState(Event)> m_task;

	public:
		/**
		 * Constructor
		 * @param func the function to be called as Task::run(Event)
		 */
		FunctionTask(std::function<TaskState(Event)> func);

		/**
		 * Destructor
		 */
		~FunctionTask();

		TaskState run(Event);
};

class TaskProcessor: public Task {
	friend Task;
	friend int subscribe(Event::Type);
	private:
		struct ScheduleItem {
			Task *task = nullptr;
			uint64 wakeupTime;

			/**
			 * Constructor
			 */
			ScheduleItem() {
			}

			/**
			 * Constructor
			 * @param task the Task scheduled
			 * @param task the time the Task is scheduled to wake up
			 */
			ScheduleItem(Task *task, uint64 wakeupTime) {
				this->task = task;
				this->wakeupTime = wakeupTime;
			}
		};

		// this will loop back around in short order, that's ok
		//  this will be incremented on every call of run
		std::vector<ScheduleItem> m_schedule;
		SubscriptionManager m_submgr;
		bool m_running = false;
		bool m_semInternal;
		Mutex m_mutex;
		BaseEventQueue *m_events;
		Channel<bool> m_done;
		Task *m_currentTask;

	public:
		/**
		 * Constructor
		 * @param sem allows specifying an external EventQueue for this TaskProcessor
		 */
		TaskProcessor(class BaseEventQueue *sem = nullptr);

		/**
		 * Destructor
		 */
		virtual ~TaskProcessor();

		TaskState run(Event);

		/**
		 * Adds the given Task to this TaskProcessor.
		 * @param task the lambda for Task to add to this TaskProcessor
		 * @param state the initial state of the Task, defaults to Running
		 */
		void addTask(std::function<TaskState(Event)> task, TaskState state = TaskState::Running);

		/**
		 * Adds the given Task to this TaskProcessor.
		 * @param task the Task to add to this TaskProcessor
		 * @param state the initial state of the Task, defaults to Running
		 */
		void addTask(Task *task, TaskState state = TaskState::Running);

		/**
		 * Starts the thread for this TaskProcessor.
		 */
		void start();

		/**
		 * Stop the thread for this TaskProcessor.
		 */
		void stop();

		/**
		 * Blocks until this TaskProcessor has stopped.
		 */
		void done();

		/**
		 * Posts the given Event to this TaskProcessor's semaphore.
		 * @param event the Event to post to the semaphore
		 */
		void post(Event event);

	protected:
		/**
		 * Adds the given Task to the subscription list of the given Event::Type.
		 * @param et the Event::Type that the Task is subscribing to
		 */
		void addSubscription(Event::Type et);

	private:
		/**
		 * Pops the currently active Task if there is one. If there is no active
		 * Task, it returns null.
		 * @return the currently active Task, if there is one, null otherwise
		 */
		Task *popActiveTask();

		/**
		 * Gets the next Task to execute.
		 * @param t the next task will be read into this value
		 * @return 0 if success, 1 if there is no next task
		 */
		int nextTask(ScheduleItem &t);

		/**
		 * Sets the state of the task and schedules it appropriately.
		 * @param task the Task to update the state of
		 * @param state the state to give the task
		 */
		void processTaskState(Task *task, TaskState state);

		/**
		 * Runs the given Task.
		 * @param task the Task to run
		 * @param event the Event that this Task is waking up to process
		 */
		void runTask(Task *task, Event event);

		/**
		 * Removes the given Task from the schedule;
		 * @param task the Task to deschedule
		 */
		void deschedule(Task *task);
};

/**
 * Adds the given Task to the main TaskProcessor.
 * @param task the lambda for Task to add to the main TaskProcessor
 * @param state the initial state of the Task, defaults to Running
 */
void addTask(std::function<TaskState(Event)> task, TaskState state = TaskState::Running);

/**
 * Adds the given Task to the main TaskProcessor.
 * @param task the Task to add to the main TaskProcessor
 * @param state the initial state of the Task, defaults to Running
 */
void addTask(Task *task, TaskState state = TaskState::Running);

}
}

#endif
