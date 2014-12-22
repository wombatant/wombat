#ifndef WOMBAT_MODELS_TYPES_HPP
#define WOMBAT_MODELS_TYPES_HPP

#include <array>
#include <map>
#include <string>
#include <vector>
#include <cstdint>

namespace wombat {
namespace models {

typedef std::string string;
typedef std::int64_t int64_t;

enum class Error: std::uint64_t {
	Ok = 0,
	TypeMismatch = 1
};

inline Error operator|(Error a, Error b) {
	return (Error) (((uint64_t) a) | ((uint64_t) b));
}

inline Error operator&(Error a, Error b) {
	return (Error) (((uint64_t) a) & ((uint64_t) b));
}

inline const Error &operator|=(Error &a, Error b) {
	return a = a | b;
}

inline const Error &operator&=(Error &a, Error b) {
	return a = a & b;
}

}
}

#endif
