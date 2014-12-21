#include <iostream>
#include "json_read.hpp"

using namespace wombat::models;
using namespace std;

class TestModel1 {
	public:
		bool        field1;
		int         field2;
		double      field3;
		string      field4;
		vector<int> field5;
};

inline Error fromJson(TestModel1 *model, json_t *jv) {
	Error err = Error::Ok;
	err |= readVal(jv, "field1", &model->field1);
	err |= readVal(jv, "field2", &model->field2);
	err |= readVal(jv, "field3", &model->field3);
	err |= readVal(jv, "field4", &model->field4);
	err |= readVal(jv, "field5", &model->field5);
	return err;
}

int main() {
	TestModel1 model;
	json_t *jv;
	auto err = parseJson("{\"field1\": true, \"field2\": 42, \"field3\": 9.9, \"field4\": \"Narf!\", \"field5\": [1, 2, 3, 4]}", &jv);
	if (err == Error::Ok) {
		fromJson(&model, jv);
		std::cout << "field1: " << model.field1 << std::endl;
		std::cout << "field2: " << model.field2 << std::endl;
		std::cout << "field3: " << model.field3 << std::endl;
		std::cout << "field4: " << model.field4 << std::endl;
	}
	return 0;
}
