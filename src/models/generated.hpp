//Generated Code

#ifndef GENERATED_HPP
#define GENERATED_HPP
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

typedef unsigned long int Error;
const Error Error_Ok = 0;
const Error Error_TypeMismatch = 1;
const Error Error_MissingField = 2;
const Error Error_CouldNotAccessFile = 4;
const Error Error_GenericParsingError = 8;
const Error Error_ArrayOverflow = 16;

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

template<typename T, long long len>
class Array {
	protected:
		T data[len];

	public:
		T &operator[](long long idx) {
			return data[idx];
		}

		long long size() const {
			return len;
		}

		bool operator==(const Array<T, len> &other) const {
			for (int i = 0; i < size(); i++) {
				if (data[i] != other.data[i]) {
					return false;
				}
			}
			return true;
		}

		bool operator!=(const Array<T, len> &other) const {
			return !(*this == other);
		}

		template<class Archive>
		void serialize(Archive &ar, const unsigned int) {
		}
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

class unknown;
cyborgbear::Error readVal(JsonObjOut v, class Model &val);

class Model {
	friend class unknown;
	friend cyborgbear::Error readVal(JsonObjOut v, class Model &val);
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

		bool operator==(const unknown&) const;
		bool operator!=(const unknown&) const;
};

/**
 * Version of cyborgbear.
 */
extern string version;

//string ops
std::string toStdString(string str);


JsonObjOut read(string json);


//value methods

template<typename T>
bool isBool(T);

template<typename T>
bool isInt(T);

template<typename T>
bool isDouble(T);

template<typename T>
bool isString(T);

template<typename T>
bool isArray(T);

template<typename T>
bool isObj(T);

template<typename T>
bool isNull(T v);


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


JsonArrayOut toArray(JsonVal);
JsonObjOut toObj(JsonVal);

JsonValOut toJsonVal(int);
JsonValOut toJsonVal(double);
JsonValOut toJsonVal(bool);
JsonValOut toJsonVal(string);
JsonValOut toJsonVal(JsonArray);
JsonValOut toJsonVal(JsonObj);


cyborgbear::Error readVal(JsonVal, int&);
cyborgbear::Error readVal(JsonVal, double&);
cyborgbear::Error readVal(JsonVal, bool&);
cyborgbear::Error readVal(JsonVal, string&);

template<typename T, long long len>
inline cyborgbear::Error readVal(JsonValOut v, Array<T, len> &val) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	if (!cyborgbear::isNull(v)) {
		if (cyborgbear::isArray(v)) {
			cyborgbear::JsonArrayOut array = cyborgbear::toArray(v);
			unsigned int size = cyborgbear::arraySize(array);
			if (size > val.size()) {
				size = val.size();
				retval |= cyborgbear::Error_ArrayOverflow;
			}
			for (unsigned int i = 0; i < size; i++) {
				retval |= cyborgbear::readVal(cyborgbear::arrayRead(array, i), val[i]);
			}
		} else {
			retval |= cyborgbear::Error_TypeMismatch;
		}
	} else {
		retval |= cyborgbear::Error_MissingField;
	}
	return retval;
}

template<typename T>
#ifdef CYBORGBEAR_USING_QT
inline cyborgbear::Error readVal(JsonValOut v, QVector<T> &val) {
#else
inline cyborgbear::Error readVal(JsonValOut v, std::vector<T> &val) {
#endif
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	if (!cyborgbear::isNull(v)) {
		if (cyborgbear::isArray(v)) {
			cyborgbear::JsonArrayOut array = cyborgbear::toArray(v);
			unsigned int size = cyborgbear::arraySize(array);
			val.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				retval |= cyborgbear::readVal(cyborgbear::arrayRead(array, i), val[i]);
			}
		} else {
			retval |= cyborgbear::Error_TypeMismatch;
		}
	} else {
		retval |= cyborgbear::Error_MissingField;
	}
	return retval;
}

inline cyborgbear::Error readVal(JsonObjOut v, class Model &val) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	if (cyborgbear::isObj(v)) {
		val.loadJsonObj(v);
	} else {
		if (cyborgbear::isNull(v)) {
			retval |= cyborgbear::Error_MissingField;
		} else {
			retval |= cyborgbear::Error_TypeMismatch;
		}
	}
	return retval;
}

inline cyborgbear::Error readVal(JsonObjOut v, class unknown &val) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	if (!cyborgbear::isNull(v)) {
		retval |= val.loadJsonObj(v);
	} else {
		retval |= cyborgbear::Error_MissingField;
	}
	return retval;
}

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


//from JsonObj or JsonObjIteratorVal
template<typename T>
inline cyborgbear::Error readVal(T v, int &val) {
	int retval = cyborgbear::Error_Ok;
	if (cyborgbear::isInt(v)) {
		val = v.toInt();
	} else {
		if (cyborgbear::isNull(v)) {
			retval |= cyborgbear::Error_MissingField;
		} else {
			retval |= cyborgbear::Error_TypeMismatch;
		}
	}
	return retval;
}

template<typename T>
inline cyborgbear::Error readVal(T v, double &val) {
	int retval = cyborgbear::Error_Ok;
	if (cyborgbear::isDouble(v)) {
		val = v.toDouble();
	} else {
		if (cyborgbear::isNull(v)) {
			retval |= cyborgbear::Error_MissingField;
		} else {
			retval |= cyborgbear::Error_TypeMismatch;
		}
	}
	return retval;
}

template<typename T>
inline cyborgbear::Error readVal(T v, bool &val) {
	int retval = cyborgbear::Error_Ok;
	if (cyborgbear::isBool(v)) {
		val = v.toBool();
	} else {
		if (cyborgbear::isNull(v)) {
			retval |= cyborgbear::Error_MissingField;
		} else {
			retval |= cyborgbear::Error_TypeMismatch;
		}
	}
	return retval;
}

template<typename T>
inline cyborgbear::Error readVal(T v, string &val) {
	int retval = cyborgbear::Error_Ok;
	if (cyborgbear::isString(v)) {
		val = v.toString();
	} else {
		if (cyborgbear::isNull(v)) {
			retval |= cyborgbear::Error_MissingField;
		} else {
			retval |= cyborgbear::Error_TypeMismatch;
		}
	}
	return retval;
}

inline int toArray(T v, JsonArrayOut &val) {
	val = v.toArray();
	return 0;
}

inline int toObj(T v, JsonArrayOut &val) {
	val = v.toObject();
	return 0;
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


template<typename T>
inline bool isNull(T v) {
	return v.isNull();
}

template<typename T>
inline bool isBool(T v) {
	return v.isBool();
}

template<typename T>
inline bool isInt(T v) {
	return v.isDouble();
}

template<typename T>
inline bool isDouble(T v) {
	return v.isDouble();
}

template<typename T>
inline bool isString(T v) {
	return v.isString();
}

template<typename T>
inline bool isArray(T v) {
	return v.isArray();
}

template<typename T>
inline bool isObj(T v) {
	return v.isObject();
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

inline cyborgbear::Error readVal(JsonVal v, int &val) {
	int retval = cyborgbear::Error_Ok;
	if (cyborgbear::isInt(v)) {
		val = (int) json_integer_value(v);
	} else {
		if (cyborgbear::isNull(v)) {
			retval |= cyborgbear::Error_MissingField;
		} else {
			retval |= cyborgbear::Error_TypeMismatch;
		}
	}
	return retval;
}

inline cyborgbear::Error readVal(JsonVal v, double &val) {
	int retval = cyborgbear::Error_Ok;
	if (cyborgbear::isDouble(v)) {
		val = (double) json_real_value(v);
	} else {
		if (cyborgbear::isNull(v)) {
			retval |= cyborgbear::Error_MissingField;
		} else {
			retval |= cyborgbear::Error_TypeMismatch;
		}
	}
	return retval;
}

inline cyborgbear::Error readVal(JsonVal v, bool &val) {
	int retval = cyborgbear::Error_Ok;
	if (cyborgbear::isBool(v)) {
		val = json_is_true(v);
	} else {
		if (cyborgbear::isNull(v)) {
			retval |= cyborgbear::Error_MissingField;
		} else {
			retval |= cyborgbear::Error_TypeMismatch;
		}
	}
	return retval;
}

inline cyborgbear::Error readVal(JsonVal v, string &val) {
	int retval = cyborgbear::Error_Ok;
	if (cyborgbear::isString(v)) {
		val = json_string_value(v);
	} else {
		if (cyborgbear::isNull(v)) {
			retval |= cyborgbear::Error_MissingField;
		} else {
			retval |= cyborgbear::Error_TypeMismatch;
		}
	}
	return retval;
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


template<typename T>
inline bool isNull(T v) {
	return !v;
}

template<typename T>
inline bool isBool(T v) {
	return json_is_boolean(v);
}

template<typename T>
inline bool isInt(T v) {
	return json_is_integer(v);
}

template<typename T>
inline bool isDouble(T v) {
	return json_is_real(v);
}

template<typename T>
inline bool isString(T v) {
	return json_is_string(v);
}

template<typename T>
inline bool isArray(T v) {
	return json_is_array(v);
}

template<typename T>
inline bool isObj(T v) {
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

};

};




namespace models {

using cyborgbear::string;

class Point: public cyborgbear::Model {

	public:

		Point();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		bool operator==(const Point&) const;

		bool operator!=(const Point&) const;
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

		bool operator==(const Size&) const;

		bool operator!=(const Size&) const;
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

		bool operator==(const Bounds&) const;

		bool operator!=(const Bounds&) const;
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

		bool operator==(const SaveVariables&) const;

		bool operator!=(const SaveVariables&) const;
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

		bool operator==(const SpriteSheetImage&) const;

		bool operator!=(const SpriteSheetImage&) const;
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

		bool operator==(const SpriteSheet&) const;

		bool operator!=(const SpriteSheet&) const;
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

		bool operator==(const Image&) const;

		bool operator!=(const Image&) const;
		string SpriteSheet;
		int ImgId;
		models::Size DefaultSize;
};

}


namespace models {

using cyborgbear::string;

class Interaction: public cyborgbear::Model {

	public:

		Interaction();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		bool operator==(const Interaction&) const;

		bool operator!=(const Interaction&) const;
		int Type;
		cyborgbear::unknown Next;
};

}


namespace models {

using cyborgbear::string;

class Sprite: public cyborgbear::Model {

	public:

		Sprite();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		bool operator==(const Sprite&) const;

		bool operator!=(const Sprite&) const;
		string Id;
		string SpriteClass;
		int Motion;
		int Facing;
		int SpriteType;
		models::Interaction Interaction;
		string Data;
};

}


namespace models {

using cyborgbear::string;

class ZoneHeader: public cyborgbear::Model {

	public:

		ZoneHeader();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		bool operator==(const ZoneHeader&) const;

		bool operator!=(const ZoneHeader&) const;
		string Zone;
		int TilesWide;
		int TilesHigh;
		int Layers;
};

}


namespace models {

using cyborgbear::string;

class ZoneInstance: public cyborgbear::Model {

	public:

		ZoneInstance();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		bool operator==(const ZoneInstance&) const;

		bool operator!=(const ZoneInstance&) const;
		string AccessorID;
		string ZoneHeader;
		models::Point Address;
};

}


namespace models {

using cyborgbear::string;

class CreatureType: public cyborgbear::Model {

	public:

		CreatureType();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		bool operator==(const CreatureType&) const;

		bool operator!=(const CreatureType&) const;
		std::map< string, string > Name;
		bool Special;
		std::vector< string > StrongAgainst;
		std::vector< string > WeakAgainst;
};

}


namespace models {

using cyborgbear::string;

class AnimationSlide: public cyborgbear::Model {

	public:

		AnimationSlide();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		bool operator==(const AnimationSlide&) const;

		bool operator!=(const AnimationSlide&) const;
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

		bool operator==(const AnimLayer&) const;

		bool operator!=(const AnimLayer&) const;
		models::Point Point;
		string Animation;
};

}


namespace models {

using cyborgbear::string;

class User: public cyborgbear::Model {

	public:

		User();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		bool operator==(const User&) const;

		bool operator!=(const User&) const;
		string Person;
};

}


namespace models {

using cyborgbear::string;

class Settings: public cyborgbear::Model {

	public:

		Settings();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		bool operator==(const Settings&) const;

		bool operator!=(const Settings&) const;
		bool Fullscreen;
		int Width;
		int Height;
};

}


namespace models {

using cyborgbear::string;

class InitFile: public cyborgbear::Model {

	public:

		InitFile();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		bool operator==(const InitFile&) const;

		bool operator!=(const InitFile&) const;
		string User;
		string World;
		string ZoneId;
		string SpriteId;
};

}


namespace models {

using cyborgbear::string;

class Font: public cyborgbear::Model {

	public:

		Font();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		bool operator==(const Font&) const;

		bool operator!=(const Font&) const;
		int Size;
		string TtfPath;
};

}


namespace models {

using cyborgbear::string;

class StatusEffect: public cyborgbear::Model {

	public:

		StatusEffect();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		bool operator==(const StatusEffect&) const;

		bool operator!=(const StatusEffect&) const;
		int AttackerEffect;
		int EnemyEffect;
};

}


namespace models {

using cyborgbear::string;

class Fraction: public cyborgbear::Model {

	public:

		Fraction();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		bool operator==(const Fraction&) const;

		bool operator!=(const Fraction&) const;
		int Current;
		int Available;
};

}


namespace models {

using cyborgbear::string;

class SpriteClass: public cyborgbear::Model {

	public:

		SpriteClass();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		bool operator==(const SpriteClass&) const;

		bool operator!=(const SpriteClass&) const;
		std::vector< std::vector< models::AnimLayer > > AnimLayers;
		string Attributes;
};

}


namespace models {

using cyborgbear::string;

class Animation: public cyborgbear::Model {

	public:

		Animation();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		bool operator==(const Animation&) const;

		bool operator!=(const Animation&) const;
		string Import;
		std::vector< models::AnimationSlide > Images;
};

}


namespace models {

using cyborgbear::string;

class CreatureMove: public cyborgbear::Model {

	public:

		CreatureMove();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		bool operator==(const CreatureMove&) const;

		bool operator!=(const CreatureMove&) const;
		std::map< string, string > Name;
		string Type;
		int Power;
		bool RequiresRegarge;
		string Script;
		models::StatusEffect Burn;
		models::StatusEffect Freeze;
		models::StatusEffect Paralyze;
		models::StatusEffect Poison;
		models::StatusEffect Sleep;
		int WorldAbilityFlags;
};

}


namespace models {

using cyborgbear::string;

class CreatureClass: public cyborgbear::Model {

	public:

		CreatureClass();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		bool operator==(const CreatureClass&) const;

		bool operator!=(const CreatureClass&) const;
		std::map< string, string > Name;
		string Successor;
		string Predecessor;
		std::vector< string > Types;
		std::vector< string > CanLearn;
		std::map< int, string > LearnsAtLevel;
		models::Animation FrontView;
		models::Animation BackView;
};

}


namespace models {

using cyborgbear::string;

class CreatureMoveInstance: public cyborgbear::Model {

	public:

		CreatureMoveInstance();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		bool operator==(const CreatureMoveInstance&) const;

		bool operator!=(const CreatureMoveInstance&) const;
		string CreatureMove;
		models::Fraction PP;
};

}


namespace models {

using cyborgbear::string;

class World: public cyborgbear::Model {

	public:

		World();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		bool operator==(const World&) const;

		bool operator!=(const World&) const;
		std::vector< models::ZoneInstance > Zones;
};

}


namespace models {

using cyborgbear::string;

class Creature: public cyborgbear::Model {

	public:

		Creature();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		bool operator==(const Creature&) const;

		bool operator!=(const Creature&) const;
		int ID;
		std::map< string, string > Name;
		string CreatureClass;
		bool Male;
		int Level;
		models::Fraction Health;
		int Attack;
		int SpecAttack;
		int Defense;
		int SpecDefense;
		bool Burned;
		bool Frozen;
		bool Poisoned;
		bool Asleep;
		std::vector< models::CreatureMoveInstance > Moves;
};

}


namespace models {

using cyborgbear::string;

class TileClass: public cyborgbear::Model {

	public:

		TileClass();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		bool operator==(const TileClass&) const;

		bool operator!=(const TileClass&) const;
		string Import;
		int TerrainType;
		models::AnimLayer LowerAnim;
		models::AnimLayer UpperAnim;
};

}


namespace models {

using cyborgbear::string;

class PersonClass: public cyborgbear::Model {

	public:

		PersonClass();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		bool operator==(const PersonClass&) const;

		bool operator!=(const PersonClass&) const;
		string Import;
		std::map< string, string > Title;
		std::vector< std::vector< std::vector< models::AnimLayer > > > Overhead;
		models::Animation FrontView;
		models::Animation BackView;
};

}


namespace models {

using cyborgbear::string;

class Tile: public cyborgbear::Model {

	public:

		Tile();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		bool operator==(const Tile&) const;

		bool operator!=(const Tile&) const;
		models::TileClass TileClass;
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

		bool operator==(const Zone&) const;

		bool operator!=(const Zone&) const;
		std::vector< std::vector< std::vector< models::Tile > > > Tiles;
};

}


namespace models {

using cyborgbear::string;

class Person: public cyborgbear::Model {

	public:

		Person();

		cyborgbear::Error loadJsonObj(cyborgbear::JsonVal obj);

		cyborgbear::JsonValOut buildJsonObj();

		bool operator==(const Person&) const;

		bool operator!=(const Person&) const;
		models::PersonClass PersonClass;
		std::map< string, string > Name;
		std::vector< string > Creatures;
};

}


#endif