#ifndef WOMBAT_MODELS_JSON_WRITE_HPP
#define WOMBAT_MODELS_JSON_WRITE_HPP

#include "types.hpp"
#include <jansson.h>

namespace wombat {
namespace models {

Error writeVal(json_t **jv, int v);

Error writeVal(json_t **jv, double v);

Error writeVal(json_t **jv, bool v);

Error writeVal(json_t **jv, string v);

template<typename T>
Error writeVal(json_t **jv, std::vector<T> v);

template<typename Model>
Error writeVal(json_t **jv, Model v);

template<typename T>
Error writeVal(json_t *jo, const char *field, T v);

template<typename Model>
Error toJson(const Model &v);


// template definitions

template<typename T>
Error writeVal(json_t **jv, std::vector<T> l) {
	auto err = Error::Ok;
	*jv = json_array();
	for (auto v : l) {
		json_t *jve;
		writeVal(&jve, v);
		json_array_append(*jv, jve);
		json_decref(jve);
	}
	return err;
}

template<typename Model>
Error writeVal(json_t **jv, Model v) {
	return toJson(v, *jv);
}

template<typename T>
Error writeVal(json_t *jo, const char *field, T v) {
	json_t *jv;
	auto err = writeVal(&jv, v);
	json_object_set(jo, field, jv);
	json_decref(jv);
	return err;
}

template<typename Model>
Error toJson(const Model &v) {
	json_t *jo = json_object();
	auto out = writeVal(&jo, v);
	json_decref(jo);
	return out;
}

}
}

#endif
