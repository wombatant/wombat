#include "animlayer.hpp"

namespace wombat {
namespace world {

AnimLayer::AnimLayer() {
}

AnimLayer::AnimLayer(core::Animation *anim, models::Point point) {
	this->animation = anim;
	this->point = point;
}

}
}
