#ifndef MODELS_JSON_HPP
#define MODELS_JSON_HPP

#include "types.hpp"
#include <jansson.h>

namespace wombat {
namespace models {

Error parseJson(string json, json_t **out);

Error readVal(json_t *jv, int *v);

Error readVal(json_t *jv, double *v);

Error readVal(json_t *jv, bool *v);

Error readVal(json_t *jv, string *v);

template<typename T>
Error readVal(json_t *jo, const char *field, std::vector<T> *v) {
	auto jv = json_object_get(jo, field);
	Error err;
	if (json_is_array(jv)) {
		auto &list = *v;
		size_t i;
		json_t *value;
		list.resize(json_array_size(jv));
		json_array_foreach(jv, i, value) {
			err |= readVal(value, &list[i]);
		}
	} else {
		err = Error::TypeMismatch;
	}
	return err;
}

template<typename Model>
Error readVal(json_t *jv, Model *v) {
	if (json_is_object(jv)) {
		return fromJson(v, jv);
	}
	return Error::TypeMismatch;
}

template<typename T>
static Error readVal(json_t *jo, const char *field, T *v) {
	auto jv = json_object_get(jo, field);
	return models::readVal(jv, v);
}

}
}

#endif
