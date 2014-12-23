#include <iostream>
#include "json_read.hpp"
#include "json_write.hpp"

using namespace wombat::models;
using namespace std;

class TestModel2 {
	public:
		int field1;
};

inline Error toJson(TestModel2 model, json_t *jo) {
	auto err = Error::Ok;
	err |= writeVal(jo, "field1", model.field1);
	return err;
}

inline Error fromJson(TestModel2 *model, json_t *jo) {
	auto err = Error::Ok;
	err |= readVal(jo, "field1", &model->field1);
	return err;
}

class TestModel1 {
	public:
		bool          field1;
		int           field2;
		double        field3;
		string        field4;
		vector<int>   field5;
		TestModel2    field6;
		map<string, int> field7;
};

inline Error toJson(TestModel1 model, json_t *jo) {
	auto err = Error::Ok;
	err |= writeVal(jo, "field1", model.field1);
	err |= writeVal(jo, "field2", model.field2);
	err |= writeVal(jo, "field3", model.field3);
	err |= writeVal(jo, "field4", model.field4);
	err |= writeVal(jo, "field5", model.field5);
	err |= writeVal(jo, "field6", model.field6);
	err |= writeVal(jo, "field7", model.field7);
	return err;
}

inline Error fromJson(TestModel1 *model, json_t *jo) {
	auto err = Error::Ok;
	err |= readVal(jo, "field1", &model->field1);
	err |= readVal(jo, "field2", &model->field2);
	err |= readVal(jo, "field3", &model->field3);
	err |= readVal(jo, "field4", &model->field4);
	err |= readVal(jo, "field5", &model->field5);
	err |= readVal(jo, "field6", &model->field6);
	err |= readVal(jo, "field7", &model->field7);
	return err;
}

int readWriteTest() {
	TestModel1 model;
	string json = "{\"field1\":true,\"field2\":42,\"field3\":9.0,\"field4\":\"Narf!\",\"field5\":[42],\"field6\":{\"field1\":42},\"field7\":{\"4\":5}}";
	bool pass = false;
	auto err = fromJson(&model, json);
	if (err == Error::Ok) {
		TestModel1 modelCopy;
		string generatedJson = toJson(model);
		if (json == generatedJson) {
			pass = true;
		}
	}
	// report result
	if (pass) {
		cout << "JSON read/write:              pass\n";
		return 0;
	} else {
		cout << "JSON read/write:              fail\n";
		return 1;
	}
}

int missingFieldTest() {
	TestModel1 model;
	string good = "{\"field1\":true,\"field2\":42,\"field3\":9.0,\"field4\":\"Narf!\",\"field5\":[42],\"field6\":{\"field1\":42},\"field7\":{\"4\":5}}";
	string bad = "{\"field1\":true}";
	bool pass = true;
	if ((bool) (fromJson(&model, good) & Error::MissingField)) {
		pass = false;
	}
	if (!(bool) (fromJson(&model, bad) & Error::MissingField)) {
		pass = false;
	}
	// report result
	if (pass) {
		cout << "JSON missing field detection: pass\n";
		return 0;
	} else {
		cout << "JSON missing field detection: fail\n";
		return 1;
	}
}

int main(int argc, char **args) {
	cout << args[0] << endl;
	int testNo;
	if (argc > 1) {
		testNo = args[1][0] - '0';
	}
	int retval = 0;
	// general read/write test
	if (argc == 1 || testNo == 0) {
		retval |= readWriteTest();
	}
	// missing field detection test
	if (argc == 1 || testNo == 1) {
		retval |= missingFieldTest();
	}
	return retval;
}
