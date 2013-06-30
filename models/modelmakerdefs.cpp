//Generated Code

#include <fstream>
#include "modelmakerdefs.hpp"

using namespace modelmaker;

bool Model::loadFile(string path) {
	std::ifstream in;
	in.open(path.c_str());
	string json;
	if (in.is_open()) {
		while (in.good()) {
			string s;
			in >> s;
			json += s;
		}
		in.close();
		load(json);
		return true;
	}
	return false;
}

void Model::writeFile(string path) {
	std::ofstream out;
	out.open(path.c_str());
	string json = write();
	out << json << "\n";
	out.close();
}

void Model::load(string json) {
	json_t *obj = json_loads(json.c_str(), 0, NULL);
	load_json_t(obj);
	json_decref(obj);
}

string Model::write() {
	json_t *obj = buildJsonObj();
	char *tmp = json_dumps(obj, JSON_COMPACT);
	if (!tmp)
		return "{}";
	string out = tmp;
	free(tmp);
	json_decref(obj);
	return out;
}

unknown::unknown() {
	m_obj = 0;
}

unknown::unknown(Model *v) {
	m_obj = 0;
	set(v);
}

unknown::unknown(bool v) {
	m_obj = 0;
	set(v);
}

unknown::unknown(int v) {
	m_obj = 0;
	set(v);
}

unknown::unknown(double v) {
	m_obj = 0;
	set(v);
}

unknown::unknown(string v) {
	m_obj = 0;
	set(v);
}

unknown::~unknown() {
	json_decref(m_obj);
}

bool unknown::load_json_t(json_t *obj) {
	m_obj = json_incref(obj);
	return obj != 0;
}

json_t* unknown::buildJsonObj() {
	return json_incref(m_obj);
}

bool unknown::loaded() {
	return m_obj;
}

bool unknown::isBool() {
	return m_obj && json_is_boolean(m_obj);
}

bool unknown::isInt() {
	return m_obj && json_is_integer(m_obj);
}

bool unknown::isDouble() {
	return m_obj && json_is_real(m_obj);
}

bool unknown::isString() {
	return m_obj && json_is_string(m_obj);
}

bool unknown::isObject() {
	return m_obj && json_is_object(m_obj);
}

bool unknown::toBool() {
	return json_is_true(m_obj);
}

int unknown::toInt() {
	return json_integer_value(m_obj);
}

double unknown::toDouble() {
	return json_real_value(m_obj);
}

string unknown::toString() {
	return json_string_value(m_obj);
}

void unknown::set(Model *v) {
	json_t *obj = v->buildJsonObj();
	json_t *old = m_obj;
	m_obj = obj;
	if (old) {
		json_decref(old);
	}
}

void unknown::set(bool v) {
	json_t *obj = json_boolean(v);
	json_t *old = m_obj;
	m_obj = obj;
	if (old) {
		json_decref(old);
	}
}

void unknown::set(int v) {
	json_t *obj = json_integer(v);
	json_t *old = m_obj;
	m_obj = obj;
	if (old) {
		json_decref(old);
	}
}

void unknown::set(double v) {
	json_t *obj = json_real(v);
	json_t *old = m_obj;
	m_obj = obj;
	if (old) {
		json_decref(old);
	}
}

void unknown::set(string v) {
	json_t *obj = json_string(v.c_str());
	json_t *old = m_obj;
	m_obj = obj;
	if (old) {
		json_decref(old);
	}
}
