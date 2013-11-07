/*
 * Copyright 2013 gtalent2@gmail.com
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
//Generated Code

#ifndef ENGINEMODELS_HPP
#define ENGINEMODELS_HPP
#include <string>
#include <sstream>

#define CYBORGBEAR_USING_JANSSON


#ifdef CYBORGBEAR_USING_QT
#include <QString>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QMap>
#include <QVector>
#else
#include <vector>
#include <map>
#include <string>
#include <jansson.h>
#endif

namespace models {

namespace cyborgbear {

enum JsonSerializationSettings {
	Compact = 0,
	Readable = 1
};

#ifdef CYBORGBEAR_USING_QT
typedef QJsonObject& JsonObj;
typedef QJsonValue&  JsonVal;
typedef QJsonArray&  JsonArray;

typedef QJsonObject  JsonObjOut;
typedef QJsonValue   JsonValOut;
typedef QJsonArray   JsonArrayOut;

typedef QJsonObject::iterator JsonObjIterator;
typedef QString               JsonObjIteratorKey;
typedef QJsonValueRef         JsonObjIteratorVal;

typedef QString string;

typedef int VectorIterator;

#else

typedef json_t* JsonObj;
typedef json_t* JsonVal;
typedef json_t* JsonArray;

typedef json_t* JsonObjOut;
typedef json_t* JsonValOut;
typedef json_t* JsonArrayOut;

typedef const char* JsonObjIterator;
typedef const char* JsonObjIteratorKey;
typedef json_t*     JsonObjIteratorVal;

typedef std::string string;

typedef unsigned VectorIterator;
#endif

//string ops
std::string toStdString(string str);
const char* toCString(string str);


JsonObjOut read(string json);

int toInt(JsonVal);
double toDouble(JsonVal);
bool toBool(JsonVal);
string toString(JsonVal);
JsonArrayOut toArray(JsonVal);
JsonObjOut toObj(JsonVal);

JsonValOut toJsonVal(int);
JsonValOut toJsonVal(double);
JsonValOut toJsonVal(bool);
JsonValOut toJsonVal(string);
JsonValOut toJsonVal(JsonArray);
JsonValOut toJsonVal(JsonObj);


//value methods

bool isBool(JsonVal);
bool isInt(JsonVal);
bool isDouble(JsonVal);
bool isString(JsonVal);
bool isArray(JsonVal);
bool isObj(JsonVal);

JsonObj incref(JsonObj);
JsonVal incref(JsonVal);
JsonArray incref(JsonArray);

void decref(JsonObj);
void decref(JsonVal);
void decref(JsonArray);


JsonArrayOut newJsonArray();

void arrayAdd(JsonArray, JsonObj);
void arrayAdd(JsonArray, JsonVal);
void arrayAdd(JsonArray, JsonArray);

int arraySize(JsonArray);

JsonValOut arrayRead(JsonArray, int);


JsonObjOut newJsonObj();

void objSet(JsonObj, string, JsonObj);
void objSet(JsonObj, string, JsonVal);
void objSet(JsonObj, string, JsonArray);

JsonValOut objRead(JsonObj, string);


JsonObjIterator jsonObjIterator(JsonObj);
JsonObjIterator jsonObjIteratorNext(JsonObj, JsonObjIterator);
JsonObjIteratorKey jsonObjIteratorKey(JsonObjIterator);
JsonObjIteratorVal iteratorValue(JsonObjIterator);
bool iteratorAtEnd(JsonObjIterator, JsonObj);



inline string toString(string str) {
	return str;
}


#ifdef CYBORGBEAR_USING_QT

//string conversions
inline std::string toStdString(string str) {
	return str.toStdString();
}

inline const char* toCString(std::string str) {
	return str.c_str();
}

inline const char* toCString(string str) {
	return toStdString(str).c_str();
}

inline string toString(std::string str) {
	return QString::fromStdString(str);
}


inline JsonObjOut read(string json) {
	return QJsonDocument::fromJson(json.toUtf8()).object();
}


//from JsonObjIteratorVal
inline int toInt(JsonObjIteratorVal v) {
	return (int) v.toDouble();
}

inline double toDouble(JsonObjIteratorVal v) {
	return v.toDouble();
}

inline bool toBool(JsonObjIteratorVal v) {
	return v.toBool();
}

inline string toString(JsonObjIteratorVal v) {
	return v.toString();
}

inline JsonArrayOut toArray(JsonObjIteratorVal v) {
	return v.toArray();
}

inline JsonObjOut toObj(JsonObjIteratorVal v) {
	return v.toObject();
}

//from JsonVal
inline int toInt(JsonVal v) {
	return (int) v.toDouble();
}

inline double toDouble(JsonVal v) {
	return v.toDouble();
}

inline bool toBool(JsonVal v) {
	return v.toBool();
}

inline string toString(JsonVal v) {
	return v.toString();
}

inline JsonArrayOut toArray(JsonVal v) {
	return v.toArray();
}

inline JsonObjOut toObj(JsonVal v) {
	return v.toObject();
}


inline JsonValOut toJsonVal(int v) {
	return QJsonValue(v);
}

inline JsonValOut toJsonVal(double v) {
	return QJsonValue(v);
}

inline JsonValOut toJsonVal(bool v) {
	return QJsonValue(v);
}

inline JsonValOut toJsonVal(string v) {
	return QJsonValue(v);
}

inline JsonValOut toJsonVal(JsonArray v) {
	return QJsonValue(v);
}

inline JsonValOut toJsonVal(JsonObj v) {
	return v;
}


inline bool isNull(JsonObjIteratorVal v) {
	return v.isNull();
}

inline bool isBool(JsonObjIteratorVal v) {
	return v.isBool();
}

inline bool isInt(JsonObjIteratorVal v) {
	return v.isDouble();
}

inline bool isDouble(JsonObjIteratorVal v) {
	return v.isDouble();
}

inline bool isString(JsonObjIteratorVal v) {
	return v.isString();
}

inline bool isArray(JsonObjIteratorVal v) {
	return v.isArray();
}

inline bool isObj(JsonObjIteratorVal v) {
	return v.isObject();
}

inline bool isBool(JsonVal v) {
	return v.isBool();
}

inline bool isInt(JsonVal v) {
	return v.isDouble();
}

inline bool isDouble(JsonVal v) {
	return v.isDouble();
}

inline bool isString(JsonVal v) {
	return v.isString();
}

inline bool isArray(JsonVal v) {
	return v.isArray();
}

inline bool isObj(JsonVal v) {
	return v.isObject();
}

inline bool isNull(JsonVal v) {
	return v.isNull();
}


inline JsonVal incref(JsonVal v) {
	return v;
}

inline void decref(JsonVal) {}

inline JsonObj incref(JsonObj v) {
	return v;
}

inline void decref(JsonObj) {}

inline JsonArray incref(JsonArray v) {
	return v;
}

inline void decref(JsonArray) {}


inline JsonArrayOut newJsonArray() {
	return QJsonArray();
}

inline void arrayAdd(JsonArray a, JsonArray v) {
	JsonValOut tmp = cyborgbear::toJsonVal(v);
	a.append(tmp);
}

inline void arrayAdd(JsonArray a, JsonObj v) {
	JsonValOut tmp = cyborgbear::toJsonVal(v);
	a.append(tmp);
}

inline void arrayAdd(JsonArray a, JsonVal v) {
	a.append(v);
}


inline JsonValOut arrayRead(JsonArray a, int i) {
	return a[i];
}

inline int arraySize(JsonArray a) {
	return a.size();
}


inline JsonObjOut newJsonObj() {
	return QJsonObject();
}

inline void objSet(JsonObj o, string k, JsonArray v) {
	JsonValOut tmp = cyborgbear::toJsonVal(v);
	o.insert(k, tmp);
}

inline void objSet(JsonObj o, string k, JsonObj v) {
	JsonValOut tmp = cyborgbear::toJsonVal(v);
	o.insert(k, tmp);
}

inline void objSet(JsonObj o, string k, JsonVal v) {
	o.insert(k, v);
}


inline JsonValOut objRead(JsonObj o, string k) {
	return o[k];
}

inline JsonObjIterator jsonObjIterator(JsonObj o) {
	return o.begin();
}

inline JsonObjIterator jsonObjIteratorNext(JsonObj, JsonObjIterator i) {
	return i + 1;
}

inline JsonObjIteratorKey jsonObjIteratorKey(JsonObjIterator i) {
	return i.key();
}

inline bool iteratorAtEnd(JsonObjIterator i, JsonObj o) {
	return i == o.end();
}

inline JsonObjIteratorVal iteratorValue(JsonObjIterator i) {
	return i.value();
}

inline string write(JsonObj obj, JsonSerializationSettings sttngs) {
	QJsonDocument doc(obj);
	return doc.toJson(sttngs == Compact ? QJsonDocument::Compact : QJsonDocument::Indented);
}

#else

inline std::string toStdString(string str) {
	return str;
}

inline const char* toCString(string str) {
	return str.c_str();
}


inline JsonObjOut read(string json) {
	return json_loads(json.c_str(), 0, NULL);
}

inline string write(JsonObj obj, JsonSerializationSettings sttngs) {
	char *tmp = json_dumps(obj, sttngs == Compact ? JSON_COMPACT : JSON_INDENT(3));
	if (!tmp)
		return "{}";
	string out = tmp;
	free(tmp);
	cyborgbear::decref(obj);
	return out;
}

//value methods

inline int toInt(JsonVal v) {
	return (int) json_integer_value(v);
}

inline double toDouble(JsonVal v) {
	return (double) json_real_value(v);
}

inline bool toBool(JsonVal v) {
	return json_is_true(v);
}

inline string toString(JsonVal v) {
	return json_string_value(v);
}

inline JsonArray toArray(JsonVal v) {
	return v;
}

inline JsonObj toObj(JsonVal v) {
	return v;
}


inline JsonVal toJsonVal(int v) {
	return json_integer(v);
}

inline JsonVal toJsonVal(double v) {
	return json_real(v);
}

inline JsonVal toJsonVal(bool v) {
	return json_boolean(v);
}

inline JsonVal toJsonVal(string v) {
	return json_string(v.c_str());
}

inline JsonVal toJsonVal(JsonArray v) {
	return v;
}


inline bool isNull(JsonVal v) {
	return !v;
}

inline bool isBool(JsonVal v) {
	return json_is_boolean(v);
}

inline bool isInt(JsonVal v) {
	return json_is_integer(v);
}

inline bool isDouble(JsonVal v) {
	return json_is_real(v);
}

inline bool isString(JsonVal v) {
	return json_is_string(v);
}

inline bool isArray(JsonVal v) {
	return json_is_array(v);
}

inline bool isObj(JsonVal v) {
	return json_is_object(v);
}

inline JsonVal incref(JsonVal v) {
	return json_incref(v);
}

inline void decref(JsonVal v) {
	json_decref(v);
}

//array methods

inline JsonArrayOut newJsonArray() {
	return json_array();
}

inline void arrayAdd(JsonArray a, JsonVal v) {
	json_array_append(a, v);
}

inline JsonVal arrayRead(JsonArray a, int i) {
	return json_array_get(a, i);
}

inline int arraySize(JsonArray a) {
	return json_array_size(a);
}

//object methods

inline JsonObjOut newJsonObj() {
	return json_object();
}

inline void objSet(JsonObj o, string k, JsonVal v) {
	json_object_set(o, k.c_str(), v);
}

inline JsonVal objRead(JsonObj o, string k) {
	return json_object_get(o, k.c_str());
}


inline JsonObjIterator jsonObjIterator(JsonObj o) {
	return json_object_iter_key(json_object_iter(o));
}

inline JsonObjIterator jsonObjIteratorNext(JsonObj o, JsonObjIterator i) {
	return json_object_iter_key(json_object_iter_next(o, json_object_key_to_iter(i)));
}

inline JsonObjIteratorKey jsonObjIteratorKey(JsonObjIterator i) {
	return i;
}

inline JsonObjIteratorVal iteratorValue(JsonObjIterator i) {
	return json_object_iter_value(json_object_key_to_iter(i));
}

inline bool iteratorAtEnd(JsonObjIterator i, JsonObj) {
	return !i;
}

#endif

class unknown;

class Model {
	friend class unknown;
	public:
		/**
		 * Reads fields of this Model from file of the given path.
		 */
		bool readJsonFile(string path);

		/**
		 * Writes JSON representation of this Model to JSON file of the given path.
		 */
		void writeJsonFile(string path, cyborgbear::JsonSerializationSettings sttngs = Compact);

		/**
		 * Loads fields of this Model from file of the given path.
		 */
		void fromJson(string json);

		/**
		 * Returns JSON representation of this Model.
		 */
		string toJson(cyborgbear::JsonSerializationSettings sttngs = Compact);

#ifdef CYBORGBEAR_USING_QT
		bool loadJsonObj(cyborgbear::JsonObjIteratorVal &obj) { return loadJsonObj(obj); };
#endif
	protected:
		virtual cyborgbear::JsonValOut buildJsonObj() = 0;
		virtual bool loadJsonObj(cyborgbear::JsonVal obj) = 0;
};

class unknown: public Model {
	private:
		cyborgbear::JsonValOut m_obj;
	public:
		unknown();
		unknown(Model *v);
		unknown(bool v);
		unknown(int v);
		unknown(double v);
		unknown(string v);
		virtual ~unknown();

		bool loaded();
		bool loadJsonObj(cyborgbear::JsonVal obj);
		cyborgbear::JsonValOut buildJsonObj();

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

};




namespace models {

using cyborgbear::string;

class CreatureType: public cyborgbear::Model {

	public:

		CreatureType();

		bool loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		std::map< string, string > name;
		bool special;
		std::vector< string > strongAgainst;
		std::vector< string > weakAgainst;
};

}


namespace models {

using cyborgbear::string;

class StatusEffect: public cyborgbear::Model {

	public:

		StatusEffect();

		bool loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		int attackerEffect;
		int enemyEffect;
};

}


namespace models {

using cyborgbear::string;

class Fraction: public cyborgbear::Model {

	public:

		Fraction();

		bool loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		int current;
		int available;
};

}


namespace models {

using cyborgbear::string;

class ModelFile: public cyborgbear::Model {

	public:

		ModelFile();

		bool loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		string type;
};

}


namespace models {

using cyborgbear::string;

class Point: public cyborgbear::Model {

	public:

		Point();

		bool loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		int x;
		int y;
};

}


namespace models {

using cyborgbear::string;

class Size: public cyborgbear::Model {

	public:

		Size();

		bool loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		int width;
		int height;
};

}


namespace models {

using cyborgbear::string;

class Bounds: public cyborgbear::Model {

	public:

		Bounds();

		bool loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		int x;
		int y;
		int width;
		int height;
};

}


namespace models {

using cyborgbear::string;

class CreatureMove: public cyborgbear::Model {

	public:

		CreatureMove();

		bool loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		std::map< string, string > name;
		string type;
		int power;
		bool requiresRegarge;
		string script;
		StatusEffect burn;
		StatusEffect freeze;
		StatusEffect paralyze;
		StatusEffect poison;
		StatusEffect sleep;
};

}


namespace models {

using cyborgbear::string;

class CreatureMoveInstance: public cyborgbear::Model {

	public:

		CreatureMoveInstance();

		bool loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		int creatureMove;
		Fraction pP;
};

}


namespace models {

using cyborgbear::string;

class Creature: public cyborgbear::Model {

	public:

		Creature();

		bool loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		int iD;
		std::map< string, string > name;
		string creatureClass;
		bool male;
		int level;
		Fraction health;
		int attack;
		int specAttack;
		int defense;
		int specDefense;
		bool burned;
		bool frozen;
		bool poisoned;
		bool asleep;
		std::vector< CreatureMoveInstance > moves;
};

}


namespace models {

using cyborgbear::string;

class User: public cyborgbear::Model {

	public:

		User();

		bool loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		int personID;
		string world;
		string zone;
		int xAddress;
		int yAddress;
		int layer;
};

}


namespace models {

using cyborgbear::string;

class ZoneInstance: public cyborgbear::Model {

	public:

		ZoneInstance();

		bool loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		string accessorID;
		string path;
		Point location;
};

}


namespace models {

using cyborgbear::string;

class Image: public cyborgbear::Model {

	public:

		Image();

		bool loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		string path;
		Size defaultSize;
};

}


namespace models {

using cyborgbear::string;

class ZoneHeader: public cyborgbear::Model {

	public:

		ZoneHeader();

		bool loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		string path;
		Size size;
};

}


namespace models {

using cyborgbear::string;

class Animation: public cyborgbear::Model {

	public:

		Animation();

		bool loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		int interval;
		std::vector< Image > images;
};

}


namespace models {

using cyborgbear::string;

class AnimLayer: public cyborgbear::Model {

	public:

		AnimLayer();

		bool loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		Point point;
		Animation animation;
};

}


namespace models {

using cyborgbear::string;

class SaveFile: public cyborgbear::Model {

	public:

		SaveFile();

		bool loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		std::map< string, cyborgbear::unknown > vars;
		User user;
};

}


namespace models {

using cyborgbear::string;

class CreatureClass: public cyborgbear::Model {

	public:

		CreatureClass();

		bool loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		std::map< string, string > name;
		string successor;
		string predecessor;
		std::vector< string > types;
		std::vector< string > canLearn;
		std::map< int, string > learnsAtLevel;
		Animation frontView;
		Animation backView;
};

}


namespace models {

using cyborgbear::string;

class TileClass: public cyborgbear::Model {

	public:

		TileClass();

		bool loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		int terrainFlags;
		string import;
		std::vector< AnimLayer > lowerAnims;
		std::vector< AnimLayer > upperAnims;
};

}


namespace models {

using cyborgbear::string;

class Sprite: public cyborgbear::Model {

	public:

		Sprite();

		bool loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		std::vector< std::vector< AnimLayer > > animLayers;
		int spriteType;
		int personID;
		int speed;
		string name;
		string path;
		string scriptPath;
};

}


namespace models {

using cyborgbear::string;

class PersonClass: public cyborgbear::Model {

	public:

		PersonClass();

		bool loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		int iD;
		std::map< string, string > name;
		std::vector< int > creatures;
		std::vector< Animation > overhead;
		Animation frontView;
		Animation backView;
};

}


namespace models {

using cyborgbear::string;

class Person: public cyborgbear::Model {

	public:

		Person();

		bool loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		PersonClass personClass;
};

}


namespace models {

using cyborgbear::string;

class Tile: public cyborgbear::Model {

	public:

		Tile();

		bool loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		TileClass tileClass;
		Sprite occupant;
};

}


namespace models {

using cyborgbear::string;

class World: public cyborgbear::Model {

	public:

		World();

		bool loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		std::vector< ZoneInstance > zones;
};

}


namespace models {

using cyborgbear::string;

class Zone: public cyborgbear::Model {

	public:

		Zone();

		bool loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		std::vector< std::vector< std::vector< Tile > > > tiles;
		std::vector< string > initScripts;
		Point location;
};

}


#ifdef CYBORGBEAR_BOOST_ENABLED
#include <boost/serialization/list.hpp>
#include <boost/serialization/string.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

namespace boost {
namespace serialization {

template<class Archive>
void serialize(Archive &ar, models::CreatureType &model, const unsigned int) {
	ar & model.name;
	ar & model.special;
	ar & model.strongAgainst;
	ar & model.weakAgainst;
}

template<class Archive>
void serialize(Archive &ar, models::StatusEffect &model, const unsigned int) {
	ar & model.attackerEffect;
	ar & model.enemyEffect;
}

template<class Archive>
void serialize(Archive &ar, models::Fraction &model, const unsigned int) {
	ar & model.current;
	ar & model.available;
}

template<class Archive>
void serialize(Archive &ar, models::ModelFile &model, const unsigned int) {
	ar & model.type;
}

template<class Archive>
void serialize(Archive &ar, models::Point &model, const unsigned int) {
	ar & model.x;
	ar & model.y;
}

template<class Archive>
void serialize(Archive &ar, models::Size &model, const unsigned int) {
	ar & model.width;
	ar & model.height;
}

template<class Archive>
void serialize(Archive &ar, models::Bounds &model, const unsigned int) {
	ar & model.x;
	ar & model.y;
	ar & model.width;
	ar & model.height;
}

template<class Archive>
void serialize(Archive &ar, models::CreatureMove &model, const unsigned int) {
	ar & model.name;
	ar & model.type;
	ar & model.power;
	ar & model.requiresRegarge;
	ar & model.script;
	ar & model.burn;
	ar & model.freeze;
	ar & model.paralyze;
	ar & model.poison;
	ar & model.sleep;
}

template<class Archive>
void serialize(Archive &ar, models::CreatureMoveInstance &model, const unsigned int) {
	ar & model.creatureMove;
	ar & model.pP;
}

template<class Archive>
void serialize(Archive &ar, models::Creature &model, const unsigned int) {
	ar & model.iD;
	ar & model.name;
	ar & model.creatureClass;
	ar & model.male;
	ar & model.level;
	ar & model.health;
	ar & model.attack;
	ar & model.specAttack;
	ar & model.defense;
	ar & model.specDefense;
	ar & model.burned;
	ar & model.frozen;
	ar & model.poisoned;
	ar & model.asleep;
	ar & model.moves;
}

template<class Archive>
void serialize(Archive &ar, models::User &model, const unsigned int) {
	ar & model.personID;
	ar & model.world;
	ar & model.zone;
	ar & model.xAddress;
	ar & model.yAddress;
	ar & model.layer;
}

template<class Archive>
void serialize(Archive &ar, models::ZoneInstance &model, const unsigned int) {
	ar & model.accessorID;
	ar & model.path;
	ar & model.location;
}

template<class Archive>
void serialize(Archive &ar, models::Image &model, const unsigned int) {
	ar & model.path;
	ar & model.defaultSize;
}

template<class Archive>
void serialize(Archive &ar, models::ZoneHeader &model, const unsigned int) {
	ar & model.path;
	ar & model.size;
}

template<class Archive>
void serialize(Archive &ar, models::Animation &model, const unsigned int) {
	ar & model.interval;
	ar & model.images;
}

template<class Archive>
void serialize(Archive &ar, models::AnimLayer &model, const unsigned int) {
	ar & model.point;
	ar & model.animation;
}

template<class Archive>
void serialize(Archive &ar, models::SaveFile &model, const unsigned int) {
	ar & model.vars;
	ar & model.user;
}

template<class Archive>
void serialize(Archive &ar, models::CreatureClass &model, const unsigned int) {
	ar & model.name;
	ar & model.successor;
	ar & model.predecessor;
	ar & model.types;
	ar & model.canLearn;
	ar & model.learnsAtLevel;
	ar & model.frontView;
	ar & model.backView;
}

template<class Archive>
void serialize(Archive &ar, models::TileClass &model, const unsigned int) {
	ar & model.terrainFlags;
	ar & model.import;
	ar & model.lowerAnims;
	ar & model.upperAnims;
}

template<class Archive>
void serialize(Archive &ar, models::Sprite &model, const unsigned int) {
	ar & model.animLayers;
	ar & model.spriteType;
	ar & model.personID;
	ar & model.speed;
	ar & model.name;
	ar & model.path;
	ar & model.scriptPath;
}

template<class Archive>
void serialize(Archive &ar, models::PersonClass &model, const unsigned int) {
	ar & model.iD;
	ar & model.name;
	ar & model.creatures;
	ar & model.overhead;
	ar & model.frontView;
	ar & model.backView;
}

template<class Archive>
void serialize(Archive &ar, models::Person &model, const unsigned int) {
	ar & model.personClass;
}

template<class Archive>
void serialize(Archive &ar, models::Tile &model, const unsigned int) {
	ar & model.tileClass;
	ar & model.occupant;
}

template<class Archive>
void serialize(Archive &ar, models::World &model, const unsigned int) {
	ar & model.zones;
}

template<class Archive>
void serialize(Archive &ar, models::Zone &model, const unsigned int) {
	ar & model.tiles;
	ar & model.initScripts;
	ar & model.location;
}

}
}
#endif
#endif