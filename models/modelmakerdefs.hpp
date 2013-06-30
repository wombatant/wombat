//Generated Code

#ifndef MODELMAKERDEFS_HPP
#define MODELMAKERDEFS_HPP

#include <string>
#include <jansson.h>

using std::string;

namespace modelmaker {

class unknown;

class Model {
	friend class unknown;
	public:
		bool loadFile(string path);
		void writeFile(string path);
		void load(string json);
		string write();
	protected:
		virtual json_t* buildJsonObj() = 0;
		virtual bool load_json_t(json_t *obj) = 0;
};

class unknown: public Model {
	private:
		json_t *m_obj;
	public:
		unknown();
		unknown(Model *v);
		unknown(bool v);
		unknown(int v);
		unknown(double v);
		unknown(string v);
		virtual ~unknown();

		bool loaded();
		bool load_json_t(json_t *obj);
		json_t* buildJsonObj();

		bool toBool();
		int toInt();
		double toDouble();
		string toString();
		
		bool isBool();
		bool isInt();
		bool isDouble();
		bool isString();
		bool isObject();

		void set(Model* v);
		void set(bool v);
		void set(int v);
		void set(double v);
		void set(string v);
};

};

#endif
