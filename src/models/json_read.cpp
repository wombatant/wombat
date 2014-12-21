#include "json_read.hpp"

namespace wombat {
namespace models {

Error parseJson(string json, json_t **out) {
	*out = json_loads(json.c_str(), 0, nullptr);
	return Error::Ok;
}

Error readVal(json_t *jv, int *v) {
	if (json_is_integer(jv)) {
		*v = json_integer_value(jv);
		return Error::Ok;
	}
	return Error::TypeMismatch;
}

Error readVal(json_t *jv, double *v) {
	if (json_is_number(jv)) {
		*v = json_real_value(jv);
		return Error::Ok;
	}
	return Error::TypeMismatch;
}

Error readVal(json_t *jv, bool *v) {
	if (json_is_boolean(jv)) {
		*v = json_boolean_value(jv);
		return Error::Ok;
	}
	return Error::TypeMismatch;
}

Error readVal(json_t *jv, std::string *v) {
	if (json_is_string(jv)) {
		*v = json_string_value(jv);
		return Error::Ok;
	}
	return Error::TypeMismatch;
}

}
}
