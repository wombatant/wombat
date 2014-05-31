#ifndef WOMBAT_CORE__MISC_HPP
#define WOMBAT_CORE__MISC_HPP

#include "core.hpp"

namespace wombat {
namespace core {

/**
 * Gets the time used by the scheduler.
 * This time is not necessarily the actual time.
 * @return the time used by the scheduler
 */
uint64 _schedTime();

}
}

#endif
