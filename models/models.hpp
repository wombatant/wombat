/*
 * Copyright 2013-2014 gtalent2@gmail.com
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

#ifndef MODELS_HPP
#define MODELS_HPP
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

#ifdef CYBORGBEAR_BOOST_ENABLED
#include <boost/serialization/vector.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/string.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#endif

namespace models {

namespace cyborgbear {

typedef unsigned long int Error;
const Error Error_Ok = 0;
const Error Error_TypeMismatch = 1;
const Error Error_MissingField = 2;
const Error Error_CouldNotAccessFile = 4;
const Error Error_GenericParsingError = 8;

enum JsonSerializationSettings {
	Compact = 0,
	Readable = 1
};

enum Type {
	Bool,
	Integer,
	Double,
	String,
	Object
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

/**
 * Version of cyborgbear.
 */
extern string version;

//string ops
std::string toStdString(string str);


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
		int readJsonFile(string path);

		/**
		 * Writes JSON representation of this Model to JSON file of the given path.
		 */
		void writeJsonFile(string path, cyborgbear::JsonSerializationSettings sttngs = Compact);

		/**
		 * Loads fields of this Model from the given JSON text.
		 */
		int fromJson(string json);

		/**
		 * Returns JSON representation of this Model.
		 */
		string toJson(cyborgbear::JsonSerializationSettings sttngs = Compact);

#ifdef CYBORGBEAR_BOOST_ENABLED
		/**
		 * Returns Boost serialization version of this object.
		 */
		virtual string toBoostBinary() = 0;

		/**
		 * Loads fields of this Model from the given Boost serialization text.
		 */
		virtual void fromBoostBinary(string dat) = 0;
#endif

#ifdef CYBORGBEAR_USING_QT
		cyborgbear::Error loadJsonObj(cyborgbear::JsonObjIteratorVal &obj) { return loadJsonObj(obj); };
#endif
	protected:
		virtual cyborgbear::JsonValOut buildJsonObj() = 0;
		virtual cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj) = 0;
};

class unknown: public Model {
	cyborgbear::string m_data;
	cyborgbear::Type m_type;

#ifdef CYBORGBEAR_BOOST_ENABLED
	friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive &ar, const unsigned int) {
		ar & m_type;
		ar & m_data;
	}
#endif

	public:
		unknown();
		unknown(Model *v);
		unknown(bool v);
		unknown(int v);
		unknown(double v);
		unknown(string v);
		virtual ~unknown();

		bool loaded();
		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);
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

#ifdef CYBORGBEAR_BOOST_ENABLED
		/**
		 * Returns Boost serialization version of this object.
		 */
		string toBoostBinary();

		/**
		 * Loads fields of this Model from the given Boost serialization text.
		 */
		void fromBoostBinary(string dat);
#endif
};

};

};




namespace models {

using cyborgbear::string;

class Point: public cyborgbear::Model {

	public:

		Point();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();
#ifdef CYBORGBEAR_BOOST_ENABLED

		virtual string toBoostBinary();

		virtual void fromBoostBinary(string dat);
#endif
		int X;
		int Y;
};

}


namespace models {

using cyborgbear::string;

class Size: public cyborgbear::Model {

	public:

		Size();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();
#ifdef CYBORGBEAR_BOOST_ENABLED

		virtual string toBoostBinary();

		virtual void fromBoostBinary(string dat);
#endif
		int Width;
		int Height;
};

}


namespace models {

using cyborgbear::string;

class Bounds: public cyborgbear::Model {

	public:

		Bounds();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();
#ifdef CYBORGBEAR_BOOST_ENABLED

		virtual string toBoostBinary();

		virtual void fromBoostBinary(string dat);
#endif
		int X;
		int Y;
		int Width;
		int Height;
};

}


namespace models {

using cyborgbear::string;

class SaveVariables: public cyborgbear::Model {

	public:

		SaveVariables();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();
#ifdef CYBORGBEAR_BOOST_ENABLED

		virtual string toBoostBinary();

		virtual void fromBoostBinary(string dat);
#endif
		std::map< string, cyborgbear::unknown > Vars;
};

}


namespace models {

using cyborgbear::string;

class SpriteSheetImage: public cyborgbear::Model {

	public:

		SpriteSheetImage();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();
#ifdef CYBORGBEAR_BOOST_ENABLED

		virtual string toBoostBinary();

		virtual void fromBoostBinary(string dat);
#endif
		models::Bounds SrcBounds;
};

}


namespace models {

using cyborgbear::string;

class SpriteSheet: public cyborgbear::Model {

	public:

		SpriteSheet();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();
#ifdef CYBORGBEAR_BOOST_ENABLED

		virtual string toBoostBinary();

		virtual void fromBoostBinary(string dat);
#endif
		int TilesWide;
		int TilesHigh;
		int TileWidth;
		int TileHeight;
		string SrcFile;
		std::map< int, models::SpriteSheetImage > Images;
		int ImageIdIterator;
		std::vector< int > RecycledImageIds;
};

}


namespace models {

using cyborgbear::string;

class Image: public cyborgbear::Model {

	public:

		Image();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();
#ifdef CYBORGBEAR_BOOST_ENABLED

		virtual string toBoostBinary();

		virtual void fromBoostBinary(string dat);
#endif
		string SpriteSheet;
		int ImgId;
		models::Size DefaultSize;
};

}


namespace models {

using cyborgbear::string;

class AnimationSlide: public cyborgbear::Model {

	public:

		AnimationSlide();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();
#ifdef CYBORGBEAR_BOOST_ENABLED

		virtual string toBoostBinary();

		virtual void fromBoostBinary(string dat);
#endif
		int Interval;
		models::Image Image;
};

}


namespace models {

using cyborgbear::string;

class AnimLayer: public cyborgbear::Model {

	public:

		AnimLayer();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();
#ifdef CYBORGBEAR_BOOST_ENABLED

		virtual string toBoostBinary();

		virtual void fromBoostBinary(string dat);
#endif
		models::Point Point;
		string Animation;
};

}


namespace models {

using cyborgbear::string;

class Settings: public cyborgbear::Model {

	public:

		Settings();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();
#ifdef CYBORGBEAR_BOOST_ENABLED

		virtual string toBoostBinary();

		virtual void fromBoostBinary(string dat);
#endif
		bool Fullscreen;
		int Width;
		int Height;
};

}


namespace models {

using cyborgbear::string;

class ZoneInstance: public cyborgbear::Model {

	public:

		ZoneInstance();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();
#ifdef CYBORGBEAR_BOOST_ENABLED

		virtual string toBoostBinary();

		virtual void fromBoostBinary(string dat);
#endif
		string AccessorID;
		string ZonePath;
		models::Point Location;
};

}


namespace models {

using cyborgbear::string;

class ZoneHeader: public cyborgbear::Model {

	public:

		ZoneHeader();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();
#ifdef CYBORGBEAR_BOOST_ENABLED

		virtual string toBoostBinary();

		virtual void fromBoostBinary(string dat);
#endif
		string Path;
		models::Size Size;
};

}


namespace models {

using cyborgbear::string;

class Animation: public cyborgbear::Model {

	public:

		Animation();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();
#ifdef CYBORGBEAR_BOOST_ENABLED

		virtual string toBoostBinary();

		virtual void fromBoostBinary(string dat);
#endif
		string Import;
		std::vector< models::AnimationSlide > Images;
};

}


namespace models {

using cyborgbear::string;

class Sprite: public cyborgbear::Model {

	public:

		Sprite();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();
#ifdef CYBORGBEAR_BOOST_ENABLED

		virtual string toBoostBinary();

		virtual void fromBoostBinary(string dat);
#endif
		std::vector< std::vector< models::AnimLayer > > AnimLayers;
		int SpriteType;
		int PersonID;
		int Speed;
		string Name;
		string Path;
		string ScriptPath;
};

}


namespace models {

using cyborgbear::string;

class Tile: public cyborgbear::Model {

	public:

		Tile();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();
#ifdef CYBORGBEAR_BOOST_ENABLED

		virtual string toBoostBinary();

		virtual void fromBoostBinary(string dat);
#endif
		string Import;
		int TerrainFlags;
		std::vector< models::AnimLayer > LowerAnims;
		std::vector< models::AnimLayer > UpperAnims;
};

}


namespace models {

using cyborgbear::string;

class World: public cyborgbear::Model {

	public:

		World();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();
#ifdef CYBORGBEAR_BOOST_ENABLED

		virtual string toBoostBinary();

		virtual void fromBoostBinary(string dat);
#endif
		std::vector< models::ZoneInstance > Zones;
};

}


namespace models {

using cyborgbear::string;

class TileInstance: public cyborgbear::Model {

	public:

		TileInstance();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();
#ifdef CYBORGBEAR_BOOST_ENABLED

		virtual string toBoostBinary();

		virtual void fromBoostBinary(string dat);
#endif
		models::Tile Tile;
		models::Sprite Occupant;
};

}


namespace models {

using cyborgbear::string;

class Zone: public cyborgbear::Model {

	public:

		Zone();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();
#ifdef CYBORGBEAR_BOOST_ENABLED

		virtual string toBoostBinary();

		virtual void fromBoostBinary(string dat);
#endif
		std::vector< std::vector< std::vector< models::TileInstance > > > Tiles;
		std::vector< string > InitScripts;
		models::Point Location;
};

}


#ifdef CYBORGBEAR_BOOST_ENABLED
#include <boost/serialization/list.hpp>
#include <boost/serialization/string.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

namespace boost {
namespace serialization {

template<class Archive>
void serialize(Archive &ar, models::Point &model, const unsigned int) {
	ar & model.X;
	ar & model.Y;
}

template<class Archive>
void serialize(Archive &ar, models::Size &model, const unsigned int) {
	ar & model.Width;
	ar & model.Height;
}

template<class Archive>
void serialize(Archive &ar, models::Bounds &model, const unsigned int) {
	ar & model.X;
	ar & model.Y;
	ar & model.Width;
	ar & model.Height;
}

template<class Archive>
void serialize(Archive &ar, models::SaveVariables &model, const unsigned int) {
	ar & model.Vars;
}

template<class Archive>
void serialize(Archive &ar, models::SpriteSheetImage &model, const unsigned int) {
	ar & model.SrcBounds;
}

template<class Archive>
void serialize(Archive &ar, models::SpriteSheet &model, const unsigned int) {
	ar & model.TilesWide;
	ar & model.TilesHigh;
	ar & model.TileWidth;
	ar & model.TileHeight;
	ar & model.SrcFile;
	ar & model.Images;
	ar & model.ImageIdIterator;
	ar & model.RecycledImageIds;
}

template<class Archive>
void serialize(Archive &ar, models::Image &model, const unsigned int) {
	ar & model.SpriteSheet;
	ar & model.ImgId;
	ar & model.DefaultSize;
}

template<class Archive>
void serialize(Archive &ar, models::AnimationSlide &model, const unsigned int) {
	ar & model.Interval;
	ar & model.Image;
}

template<class Archive>
void serialize(Archive &ar, models::AnimLayer &model, const unsigned int) {
	ar & model.Point;
	ar & model.Animation;
}

template<class Archive>
void serialize(Archive &ar, models::Settings &model, const unsigned int) {
	ar & model.Fullscreen;
	ar & model.Width;
	ar & model.Height;
}

template<class Archive>
void serialize(Archive &ar, models::ZoneInstance &model, const unsigned int) {
	ar & model.AccessorID;
	ar & model.ZonePath;
	ar & model.Location;
}

template<class Archive>
void serialize(Archive &ar, models::ZoneHeader &model, const unsigned int) {
	ar & model.Path;
	ar & model.Size;
}

template<class Archive>
void serialize(Archive &ar, models::Animation &model, const unsigned int) {
	ar & model.Import;
	ar & model.Images;
}

template<class Archive>
void serialize(Archive &ar, models::Sprite &model, const unsigned int) {
	ar & model.AnimLayers;
	ar & model.SpriteType;
	ar & model.PersonID;
	ar & model.Speed;
	ar & model.Name;
	ar & model.Path;
	ar & model.ScriptPath;
}

template<class Archive>
void serialize(Archive &ar, models::Tile &model, const unsigned int) {
	ar & model.Import;
	ar & model.TerrainFlags;
	ar & model.LowerAnims;
	ar & model.UpperAnims;
}

template<class Archive>
void serialize(Archive &ar, models::World &model, const unsigned int) {
	ar & model.Zones;
}

template<class Archive>
void serialize(Archive &ar, models::TileInstance &model, const unsigned int) {
	ar & model.Tile;
	ar & model.Occupant;
}

template<class Archive>
void serialize(Archive &ar, models::Zone &model, const unsigned int) {
	ar & model.Tiles;
	ar & model.InitScripts;
	ar & model.Location;
}

}
}
#endif
#endif