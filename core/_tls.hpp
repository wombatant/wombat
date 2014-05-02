#ifndef WOMBAT_CORE__TLS_HPP
#define WOMBAT_CORE__TLS_HPP

#include "core.hpp"

namespace wombat {
namespace core {

struct TlsData {
	/**
	 * The current TaskProcessor of the calling thread.
	 */
	TaskProcessor *taskProcessor;

	/**
	 * Constructor
	 */
	TlsData();
};

/**
 * Sets the TaskProcessor running the current Task that is running in
 * the calling thread.
 * @param tp the new active TaskProcessor
 */
void setActiveTaskProcessor(TaskProcessor *tp);

/**
 * Gets the TaskProcessor running the current Task that is running in 
 * the calling thread.
 * @return the TaskProcessor of the active Task that in calling thread
 */
TaskProcessor *activeTaskProcessor();

}
}

#endif
