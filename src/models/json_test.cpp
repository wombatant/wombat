#include <iostream>
#include "json_read.hpp"
#include "json_write.hpp"

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

inline Error toJson(TestModel1 model, json_t *jo) {
	auto err = Error::Ok;
	err |= writeVal(jo, "field1", model.field1);
	err |= writeVal(jo, "field2", model.field2);
	err |= writeVal(jo, "field3", model.field3);
	err |= writeVal(jo, "field4", model.field4);
	err |= writeVal(jo, "field5", model.field5);
	return err;
}

inline Error fromJson(TestModel1 *model, json_t *jo) {
	auto err = Error::Ok;
	err |= readVal(jo, "field1", &model->field1);
	err |= readVal(jo, "field2", &model->field2);
	err |= readVal(jo, "field3", &model->field3);
	err |= readVal(jo, "field4", &model->field4);
	err |= readVal(jo, "field5", &model->field5);
	return err;
}

int main() {
	TestModel1 model;
	string json = "{\"field1\":true,\"field2\":42,\"field3\":9.0,\"field4\":\"Narf!\",\"field5\":[42]}";
	auto err = fromJson(&model, json);
	if (err == Error::Ok) {
		auto pass = "fail";
		TestModel1 modelCopy;
		string generatedJson = toJson(model);
		if (json == generatedJson) {
			pass = "pass";
		}
		cout << "JSON encode/decode: " << pass << endl;
	} else {
		cout << "JSON reading broken.";
	}
	return 0;
}
