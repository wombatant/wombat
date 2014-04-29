#ifndef WOMBAT_CORE_TASK_HPP
#define WOMBAT_CORE_TASK_HPP

#include "event.hpp"
#include "threads.hpp"
#include "types.hpp"

namespace wombat {
namespace core {

class TaskProcessor;

class TaskState {
	public:
		enum State {
			Running,
			Waiting,
			Done
		} state;

		/**
		 * Time (milliseconds) til the Task wants to run again.
		 */
		uint64 sleepDuration;

		/**
		 * Constructor
		 * @param state state of task, defaults to Waiting
		 */
		TaskState(State state = Waiting);

		/**
		 * Constructor
		 * State is set to Running.
		 * @param sleep time to sleep in milliseconds
		 */
		TaskState(uint64 sleep);
};

class Task {
	friend TaskProcessor;
	protected:
		TaskProcessor *m_taskProcessor;

	private:
		bool m_autoDelete;

	public:
		/**
		 * Constructor
		 */
		Task();

		virtual ~Task();

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

class TaskProcessor {
	private:
		std::vector<std::pair<Task*, uint64>> m_schedule;
		bool m_running;
		Mutex m_mutex;
		Semaphore m_sem;
		Channel<bool> m_done;

	public:
		/**
		 * Constructor
		 */
		TaskProcessor();

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
		int nextTask(std::pair<Task*, uint64> &t);

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
};


}
}

#endif