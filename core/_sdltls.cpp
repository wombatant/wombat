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
