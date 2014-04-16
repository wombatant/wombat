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
#include "tileclass.hpp"

namespace wombat {
namespace world {

// Static

Flyweight<models::TileClass> TileClass::tileClasses([](models::TileClass &model) {
	auto tc = new TileClass();
	tc->m_terrainFlags = model.TerrainFlags;
	for (auto alm : model.UpperAnims) {
		AnimLayer al;
		al.animation = core::checkoutAnimation(alm.Animation);
		al.point = alm.Point;
		tc->m_upperAnims.push_back(al);
	}
	for (auto alm : model.LowerAnims) {
		AnimLayer al;
		al.animation = core::checkoutAnimation(alm.Animation);
		al.point = alm.Point;
		tc->m_lowerAnims.push_back(al);
	}
	return tc;
});

TileClass *TileClass::checkout(string path) {
	return dynamic_cast<TileClass*>(tileClasses.checkout(path));
}

void TileClass::checkin(TileClass *tc) {
	tileClasses.checkin(tc);
}

}
}
