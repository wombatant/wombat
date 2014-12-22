#ifndef WOMBAT_MODELS_JSON_WRITE_HPP
#define WOMBAT_MODELS_JSON_WRITE_HPP

#include "types.hpp"
#include <sstream>
#include <jansson.h>

namespace wombat {
namespace models {

Error writeVal(json_t **jv, int v);

Error writeVal(json_t **jv, double v);

Error writeVal(json_t **jv, bool v);

Error writeVal(json_t **jv, string v);

template<typename Key, typename Value>
Error writeVal(json_t **jv, std::map<Key, Key> l);

template<typename T>
Error writeVal(json_t **jv, std::vector<T> v);

template<typename Model>
Error writeVal(json_t **jv, Model v);

template<typename T>
Error writeVal(json_t *jo, const char *field, T v);

template<typename Model>
string toJson(const Model &v);


// template definitions

template<typename Key, typename Value>
Error writeVal(json_t **jv, std::map<Key, Value> l) {
	auto err = Error::Ok;
	*jv = json_object();
	for (auto i = l.begin(); i != l.end(); i++) {
		// build key
		std::stringstream conv;
		string key;
		conv << i->first;
		conv >> key;
		// build value
		json_t *jve;
		writeVal(&jve, i->second);
		// place key/value in object
		json_object_set(*jv, key.c_str(), jve);
		json_decref(jve);
	}
	return err;
}

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
	*jv = json_object();
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
string toJson(const Model &v) {
	json_t *jo;
	writeVal(&jo, v);
	auto flags = JSON_COMPACT | JSON_PRESERVE_ORDER;
	auto cstr = json_dumps(jo, flags);
	string out = cstr;
	free(cstr);
	json_decref(jo);
	return out;
}

}
}

#endif
