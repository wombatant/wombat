#include "threads.hpp"


namespace wombat {
namespace core {

SemaphorePost::SemaphorePost() {
	m_task = 0;
	m_reason = GenericPost;
}

bool Semaphore::hasPosts() {
	return !m_posts.empty();
}

}
}
