#include "sync.hpp"

namespace wombat {
namespace core {

BaseEventQueue::~BaseEventQueue() {
}

bool EventQueue::hasPosts() {
	return !m_posts.empty();
}

int EventQueue::popPost(Event &post) {
	m_mutex.lock();
	if (hasPosts()) {
		post = m_posts.front();
		m_posts.pop();
		m_mutex.unlock();
		return 0;
	}
	m_mutex.unlock();
	return 1;
}

}
}
