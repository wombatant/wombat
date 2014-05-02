#include <SDL.h>
#include "_tls.hpp"

namespace wombat {
namespace core {

static SDL_SpinLock _tlsLock;
static SDL_TLSID _tls;

TlsData::TlsData() {
	taskProcessor = 0;
}

TlsData *getTls() {
	if (!_tls) {
		SDL_AtomicLock(&_tlsLock);
		if (!_tls) {
			_tls = SDL_TLSCreate();
		}
		SDL_AtomicUnlock(&_tlsLock);
	}
	auto tlsData = (TlsData*) SDL_TLSGet(_tls);
	if (!tlsData) {
		tlsData = new TlsData();
		SDL_TLSSet(_tls, tlsData, [](void *tlsData) {
			delete ((TlsData*) tlsData);
		});
	}
	return tlsData;
}

void setActiveTaskProcessor(TaskProcessor *tp) {
	getTls()->taskProcessor = tp;
}

TaskProcessor *activeTaskProcessor() {
	return getTls()->taskProcessor;
}

}
}
