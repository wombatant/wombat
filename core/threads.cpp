#include "threads.hpp"


namespace wombat {
namespace core {

SemaphorePost::SemaphorePost(SemaphorePost::Reason reason) {
	m_task = 0;
	m_reason = reason;
}

SemaphorePost::Reason SemaphorePost::reason() {
	return m_reason;
}

bool Semaphore::hasPosts() {
	return !m_posts.empty();
}

}
}
