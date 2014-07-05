/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef WOMBAT_WORLD_EVENT_HPP
#define WOMBAT_WORLD_EVENT_HPP

namespace wombat {
namespace world {

enum WorldEvent {
	SpriteHandover = core::EventType::AppEvent + 1,
	SpriteHandoverAck,
	MoveLeft,
	MoveUp,
	MoveDown,
	MoveRight
};

}
}

#endif
