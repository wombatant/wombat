/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "../_tls.hpp"

namespace wombat {
namespace core {

TlsData::TlsData() {
	taskProcessor = 0;
}

TlsData *getTls() {
	return 0;
}

void setActiveTaskProcessor(TaskProcessor *tp) {
	getTls()->taskProcessor = tp;
}

TaskProcessor *activeTaskProcessor() {
	return getTls()->taskProcessor;
}

}
}
