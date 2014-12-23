#ifndef WOMBAT_MODELS_JSON_HPP
#define WOMBAT_MODELS_JSON_HPP

#include <iostream>
#include <sstream>
#include <jansson.h>
#include "types.hpp"

namespace wombat {
namespace models {

Error parseJson(string json, json_t **out);

Error readVal(json_t *jv, int *v);

Error readVal(json_t *jv, double *v);

Error readVal(json_t *jv, bool *v);

Error readVal(json_t *jv, string *v);

template<typename T>
Error readVal(json_t *jv, std::vector<T> *v);

template<typename Key, typename Value>
Error readVal(json_t *jv, std::map<Key, Value> *v);

template<typename Model>
Error readVal(json_t *jv, Model *v);

template<typename Model>
Error fromJson(Model *model, string json);

template<typename T>
Error readVal(json_t *jo, const char *field, T *v);


// template definitions

template<typename T>
Error readVal(json_t *jv, std::vector<T> *v) {
	auto err = Error::Ok;
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

template<typename Key, typename Value>
Error readVal(json_t *jv, std::map<Key, Value> *v) {
	auto err = Error::Ok;
	if (json_is_object(jv)) {
		auto &list = *v;
		const char *i;
		json_t *value;
		json_object_foreach(jv, i, value) {
			std::stringstream conv;
			Key key;
			conv << i;
			conv >> key;
			err |= readVal(value, &list[key]);
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

template<typename Model>
Error fromJson(Model *model, string json) {
	json_t *jv;
	auto err = parseJson(json, &jv);
	err |= fromJson(model, jv);
	json_decref(jv);
	return err;
}

template<typename T>
Error readVal(json_t *jo, const char *field, T *v) {
	auto jv = json_object_get(jo, field);
	if (jv) {
		return models::readVal(jv, v);
	} else {
		return Error::MissingField;
	}
}

}
}

#endif
