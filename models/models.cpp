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

#include <fstream>
#include "models.hpp"

using namespace models;
using namespace models::cyborgbear;

string models::cyborgbear::version = "1.0.0";

int Model::readJsonFile(string path) {
	std::ifstream in;
	in.open(cyborgbear::toStdString(path).c_str());
	if (in.is_open()) {
		std::string json((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
		in.close();
		return fromJson(cyborgbear::toString(json));
	}
	return cyborgbear::Error_CouldNotAccessFile;
}

void Model::writeJsonFile(string path, cyborgbear::JsonSerializationSettings sttngs) {
	std::ofstream out;
	out.open(cyborgbear::toStdString(path).c_str());
	std::string json = cyborgbear::toStdString(toJson(sttngs));
	out << json << "\0";
	out.close();
}

int Model::fromJson(string json) {
	cyborgbear::JsonValOut obj = cyborgbear::read(json);
	cyborgbear::Error retval = loadJsonObj(obj);
	cyborgbear::decref(obj);
	return retval;
}

string Model::toJson(cyborgbear::JsonSerializationSettings sttngs) {
	cyborgbear::JsonValOut val = buildJsonObj();
	cyborgbear::JsonObjOut obj = cyborgbear::toObj(val);
	return cyborgbear::write(obj, sttngs);
}

unknown::unknown() {
}

unknown::unknown(Model *v) {
	set(v);
}

unknown::unknown(bool v) {
	set(v);
}

unknown::unknown(int v) {
	set(v);
}

unknown::unknown(double v) {
	set(v);
}

unknown::unknown(string v) {
	set(v);
}

unknown::~unknown() {
}

cyborgbear::Error unknown::loadJsonObj(cyborgbear::JsonVal obj) {
	cyborgbear::JsonObjOut wrapper = cyborgbear::newJsonObj();
	cyborgbear::objSet(wrapper, "Value", obj);
	m_data = cyborgbear::write(wrapper, cyborgbear::Compact);
	if (cyborgbear::isBool(obj)) {
		m_type = cyborgbear::Bool;
	} else if (cyborgbear::isInt(obj)) {
		m_type = cyborgbear::Integer;
	} else if (cyborgbear::isDouble(obj)) {
		m_type = cyborgbear::Double;
	} else if (cyborgbear::isString(obj)) {
		m_type = cyborgbear::String;
	} else if (cyborgbear::isObj(obj)) {
		m_type = cyborgbear::Object;
	}

	if (cyborgbear::isNull(obj)) {
		return cyborgbear::Error_GenericParsingError;
	} else {
		return cyborgbear::Error_Ok;
	}
}

cyborgbear::JsonValOut unknown::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::read(m_data);
#ifdef CYBORGBEAR_USING_QT
	cyborgbear::JsonValOut val = cyborgbear::objRead(obj, "Value");
#else
	cyborgbear::JsonValOut val = cyborgbear::incref(cyborgbear::objRead(obj, "Value"));
#endif
	cyborgbear::decref(obj);
	return val;
}

bool unknown::loaded() {
	return m_data != "";
}

bool unknown::isBool() {
	return m_type == cyborgbear::Bool;
}

bool unknown::isInt() {
	return m_type == cyborgbear::Integer;
}

bool unknown::isDouble() {
	return m_type == cyborgbear::Double;
}

bool unknown::isString() {
	return m_type == cyborgbear::String;
}

bool unknown::isObject() {
	return m_type == cyborgbear::Object;
}

bool unknown::toBool() {
	cyborgbear::JsonValOut out = buildJsonObj();
	return cyborgbear::toBool(out);
}

int unknown::toInt() {
	cyborgbear::JsonValOut out = buildJsonObj();
	return cyborgbear::toInt(out);
}

double unknown::toDouble() {
	cyborgbear::JsonValOut out = buildJsonObj();
	return cyborgbear::toDouble(out);
}

string unknown::toString() {
	cyborgbear::JsonValOut out = buildJsonObj();
	return cyborgbear::toString(out);
}

void unknown::set(Model *v) {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	cyborgbear::JsonValOut val = v->buildJsonObj();
	cyborgbear::objSet(obj, "Value", val);
	m_type = cyborgbear::Object;
	m_data = cyborgbear::write(obj, cyborgbear::Compact);
	cyborgbear::decref(obj);

	unknown *unk = dynamic_cast<unknown*>(v);
	if (unk)
		m_type = unk->m_type;
}

void unknown::set(bool v) {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	cyborgbear::JsonValOut val = cyborgbear::toJsonVal(v);
	cyborgbear::objSet(obj, "Value", val);
	m_type = cyborgbear::Bool;
	m_data = cyborgbear::write(obj, cyborgbear::Compact);
	cyborgbear::decref(obj);
}

void unknown::set(int v) {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	cyborgbear::JsonValOut val = cyborgbear::toJsonVal(v);
	cyborgbear::objSet(obj, "Value", val);
	m_type = cyborgbear::Integer;
	m_data = cyborgbear::write(obj, cyborgbear::Compact);
	cyborgbear::decref(obj);
}

void unknown::set(double v) {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	cyborgbear::JsonValOut val = cyborgbear::toJsonVal(v);
	cyborgbear::objSet(obj, "Value", val);
	m_type = cyborgbear::Double;
	m_data = cyborgbear::write(obj, cyborgbear::Compact);
	cyborgbear::decref(obj);
}

void unknown::set(string v) {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	cyborgbear::JsonValOut val = cyborgbear::toJsonVal(v);
	cyborgbear::objSet(obj, "Value", val);
	m_type = cyborgbear::String;
	m_data = cyborgbear::write(obj, cyborgbear::Compact);
	cyborgbear::decref(obj);
}

#ifdef CYBORGBEAR_BOOST_ENABLED

void unknown::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string unknown::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}
	string str;
	while (out.good())
		str += out.get();
	return str;
}
#endif


#include "string.h"
#include "models.hpp"

using namespace models;
using std::stringstream;

CreatureType::CreatureType() {
	this->Special = 0;
}

StatusEffect::StatusEffect() {
	this->AttackerEffect = 0;
	this->EnemyEffect = 0;
}

Fraction::Fraction() {
	this->Current = 0;
	this->Available = 0;
}

ModelFile::ModelFile() {
	this->Type = "";
}

Point::Point() {
	this->X = 0;
	this->Y = 0;
}

Size::Size() {
	this->Width = 0;
	this->Height = 0;
}

Bounds::Bounds() {
	this->X = 0;
	this->Y = 0;
	this->Width = 0;
	this->Height = 0;
}

SaveVariables::SaveVariables() {
}

SpriteSheetImage::SpriteSheetImage() {
}

SpriteSheet::SpriteSheet() {
	this->TilesWide = 0;
	this->TilesHigh = 0;
	this->TileWidth = 0;
	this->TileHeight = 0;
	this->SrcFile = "";
	this->ImageIdIterator = 0;
}

Image::Image() {
	this->SpriteSheet = "";
	this->ImgId = 0;
}

AnimationSlide::AnimationSlide() {
	this->Interval = 0;
}

AnimLayer::AnimLayer() {
	this->Animation = "";
}

Settings::Settings() {
	this->Fullscreen = 0;
	this->Width = 0;
	this->Height = 0;
}

CreatureMove::CreatureMove() {
	this->Type = "";
	this->Power = 0;
	this->RequiresRegarge = 0;
	this->Script = "";
}

CreatureMoveInstance::CreatureMoveInstance() {
	this->CreatureMove = 0;
}

Creature::Creature() {
	this->ID = 0;
	this->CreatureClass = "";
	this->Male = 0;
	this->Level = 0;
	this->Attack = 0;
	this->SpecAttack = 0;
	this->Defense = 0;
	this->SpecDefense = 0;
	this->Burned = 0;
	this->Frozen = 0;
	this->Poisoned = 0;
	this->Asleep = 0;
}

User::User() {
	this->PersonID = 0;
	this->World = "";
	this->Zone = "";
	this->XAddress = 0;
	this->YAddress = 0;
	this->Layer = 0;
}

ZoneInstance::ZoneInstance() {
	this->AccessorID = "";
	this->ZonePath = "";
}

Animation::Animation() {
	this->Import = "";
}

Sprite::Sprite() {
	this->SpriteType = 0;
	this->PersonID = 0;
	this->Speed = 0;
	this->Name = "";
	this->Path = "";
	this->ScriptPath = "";
}

TileClass::TileClass() {
	this->Import = "";
	this->TerrainFlags = 0;
}

Tile::Tile() {
}

CreatureClass::CreatureClass() {
	this->Successor = "";
	this->Predecessor = "";
}

World::World() {
}

PersonClass::PersonClass() {
	this->ID = 0;
}

Person::Person() {
}

SaveFile::SaveFile() {
}

Zone::Zone() {
}

ZoneHeader::ZoneHeader() {
	this->Path = "";
}

cyborgbear::Error CreatureType::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Name");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isObj(obj0)) {
				cyborgbear::JsonObjOut map0 = cyborgbear::toObj(obj0);
				for (cyborgbear::JsonObjIterator it1 = cyborgbear::jsonObjIterator(map0); !cyborgbear::iteratorAtEnd(it1, map0); it1 = cyborgbear::jsonObjIteratorNext(map0,  it1)) {
					string i;
					cyborgbear::JsonValOut obj1 = cyborgbear::iteratorValue(it1);
					{
						std::string key = cyborgbear::toStdString(cyborgbear::jsonObjIteratorKey(it1));
						std::string o;
						std::stringstream s;
						s << key;
						s >> o;
						i = o.c_str();
					}
					{
						if (cyborgbear::isString(obj1)) {
							this->Name[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Special");
		{
			if (cyborgbear::isBool(obj0)) {
				this->Special = cyborgbear::toBool(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "StrongAgainst");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->StrongAgainst.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						if (cyborgbear::isString(obj1)) {
							this->StrongAgainst[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "WeakAgainst");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->WeakAgainst.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						if (cyborgbear::isString(obj1)) {
							this->WeakAgainst[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	return retval;
}

cyborgbear::Error StatusEffect::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "AttackerEffect");
		{
			if (cyborgbear::isInt(obj0)) {
				this->AttackerEffect = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "EnemyEffect");
		{
			if (cyborgbear::isInt(obj0)) {
				this->EnemyEffect = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error Fraction::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Current");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Current = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Available");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Available = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error ModelFile::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Type");
		{
			if (cyborgbear::isString(obj0)) {
				this->Type = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error Point::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "X");
		{
			if (cyborgbear::isInt(obj0)) {
				this->X = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Y");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Y = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error Size::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Width");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Width = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Height");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Height = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error Bounds::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "X");
		{
			if (cyborgbear::isInt(obj0)) {
				this->X = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Y");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Y = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Width");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Width = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Height");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Height = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error SaveVariables::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Vars");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isObj(obj0)) {
				cyborgbear::JsonObjOut map0 = cyborgbear::toObj(obj0);
				for (cyborgbear::JsonObjIterator it1 = cyborgbear::jsonObjIterator(map0); !cyborgbear::iteratorAtEnd(it1, map0); it1 = cyborgbear::jsonObjIteratorNext(map0,  it1)) {
					string i;
					cyborgbear::JsonValOut obj1 = cyborgbear::iteratorValue(it1);
					{
						std::string key = cyborgbear::toStdString(cyborgbear::jsonObjIteratorKey(it1));
						std::string o;
						std::stringstream s;
						s << key;
						s >> o;
						i = o.c_str();
					}
					{
						retval |= this->Vars[i].loadJsonObj(obj1);
					}
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error SpriteSheetImage::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "SrcBounds");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->SrcBounds.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error SpriteSheet::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "TilesWide");
		{
			if (cyborgbear::isInt(obj0)) {
				this->TilesWide = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "TilesHigh");
		{
			if (cyborgbear::isInt(obj0)) {
				this->TilesHigh = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "TileWidth");
		{
			if (cyborgbear::isInt(obj0)) {
				this->TileWidth = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "TileHeight");
		{
			if (cyborgbear::isInt(obj0)) {
				this->TileHeight = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "SrcFile");
		{
			if (cyborgbear::isString(obj0)) {
				this->SrcFile = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Images");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isObj(obj0)) {
				cyborgbear::JsonObjOut map0 = cyborgbear::toObj(obj0);
				for (cyborgbear::JsonObjIterator it1 = cyborgbear::jsonObjIterator(map0); !cyborgbear::iteratorAtEnd(it1, map0); it1 = cyborgbear::jsonObjIteratorNext(map0,  it1)) {
					int i;
					cyborgbear::JsonValOut obj1 = cyborgbear::iteratorValue(it1);
					{
						std::string key = cyborgbear::toStdString(cyborgbear::jsonObjIteratorKey(it1));
						std::stringstream s;
						s << key;
						s >> i;
					}
					{
						cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj1);
						if (cyborgbear::isObj(finalObj)) {
							retval |= this->Images[i].loadJsonObj(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "ImageIdIterator");
		{
			if (cyborgbear::isInt(obj0)) {
				this->ImageIdIterator = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "RecycledImageIds");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->RecycledImageIds.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						if (cyborgbear::isInt(obj1)) {
							this->RecycledImageIds[i] = cyborgbear::toInt(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	return retval;
}

cyborgbear::Error Image::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "SpriteSheet");
		{
			if (cyborgbear::isString(obj0)) {
				this->SpriteSheet = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "ImgId");
		{
			if (cyborgbear::isInt(obj0)) {
				this->ImgId = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "DefaultSize");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->DefaultSize.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error AnimationSlide::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Interval");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Interval = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Image");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->Image.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error AnimLayer::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Point");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->Point.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Animation");
		{
			if (cyborgbear::isString(obj0)) {
				this->Animation = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error Settings::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Fullscreen");
		{
			if (cyborgbear::isBool(obj0)) {
				this->Fullscreen = cyborgbear::toBool(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Width");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Width = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Height");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Height = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error CreatureMove::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Name");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isObj(obj0)) {
				cyborgbear::JsonObjOut map0 = cyborgbear::toObj(obj0);
				for (cyborgbear::JsonObjIterator it1 = cyborgbear::jsonObjIterator(map0); !cyborgbear::iteratorAtEnd(it1, map0); it1 = cyborgbear::jsonObjIteratorNext(map0,  it1)) {
					string i;
					cyborgbear::JsonValOut obj1 = cyborgbear::iteratorValue(it1);
					{
						std::string key = cyborgbear::toStdString(cyborgbear::jsonObjIteratorKey(it1));
						std::string o;
						std::stringstream s;
						s << key;
						s >> o;
						i = o.c_str();
					}
					{
						if (cyborgbear::isString(obj1)) {
							this->Name[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Type");
		{
			if (cyborgbear::isString(obj0)) {
				this->Type = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Power");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Power = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "RequiresRegarge");
		{
			if (cyborgbear::isBool(obj0)) {
				this->RequiresRegarge = cyborgbear::toBool(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Script");
		{
			if (cyborgbear::isString(obj0)) {
				this->Script = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Burn");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->Burn.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Freeze");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->Freeze.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Paralyze");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->Paralyze.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Poison");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->Poison.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Sleep");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->Sleep.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error CreatureMoveInstance::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "CreatureMove");
		{
			if (cyborgbear::isInt(obj0)) {
				this->CreatureMove = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "PP");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->PP.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error Creature::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "ID");
		{
			if (cyborgbear::isInt(obj0)) {
				this->ID = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Name");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isObj(obj0)) {
				cyborgbear::JsonObjOut map0 = cyborgbear::toObj(obj0);
				for (cyborgbear::JsonObjIterator it1 = cyborgbear::jsonObjIterator(map0); !cyborgbear::iteratorAtEnd(it1, map0); it1 = cyborgbear::jsonObjIteratorNext(map0,  it1)) {
					string i;
					cyborgbear::JsonValOut obj1 = cyborgbear::iteratorValue(it1);
					{
						std::string key = cyborgbear::toStdString(cyborgbear::jsonObjIteratorKey(it1));
						std::string o;
						std::stringstream s;
						s << key;
						s >> o;
						i = o.c_str();
					}
					{
						if (cyborgbear::isString(obj1)) {
							this->Name[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "CreatureClass");
		{
			if (cyborgbear::isString(obj0)) {
				this->CreatureClass = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Male");
		{
			if (cyborgbear::isBool(obj0)) {
				this->Male = cyborgbear::toBool(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Level");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Level = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Health");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->Health.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Attack");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Attack = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "SpecAttack");
		{
			if (cyborgbear::isInt(obj0)) {
				this->SpecAttack = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Defense");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Defense = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "SpecDefense");
		{
			if (cyborgbear::isInt(obj0)) {
				this->SpecDefense = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Burned");
		{
			if (cyborgbear::isBool(obj0)) {
				this->Burned = cyborgbear::toBool(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Frozen");
		{
			if (cyborgbear::isBool(obj0)) {
				this->Frozen = cyborgbear::toBool(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Poisoned");
		{
			if (cyborgbear::isBool(obj0)) {
				this->Poisoned = cyborgbear::toBool(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Asleep");
		{
			if (cyborgbear::isBool(obj0)) {
				this->Asleep = cyborgbear::toBool(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Moves");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->Moves.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj1);
						if (cyborgbear::isObj(finalObj)) {
							retval |= this->Moves[i].loadJsonObj(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	return retval;
}

cyborgbear::Error User::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "PersonID");
		{
			if (cyborgbear::isInt(obj0)) {
				this->PersonID = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "World");
		{
			if (cyborgbear::isString(obj0)) {
				this->World = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Zone");
		{
			if (cyborgbear::isString(obj0)) {
				this->Zone = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "XAddress");
		{
			if (cyborgbear::isInt(obj0)) {
				this->XAddress = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "YAddress");
		{
			if (cyborgbear::isInt(obj0)) {
				this->YAddress = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Layer");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Layer = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error ZoneInstance::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "AccessorID");
		{
			if (cyborgbear::isString(obj0)) {
				this->AccessorID = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "ZonePath");
		{
			if (cyborgbear::isString(obj0)) {
				this->ZonePath = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Location");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->Location.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error Animation::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Import");
		{
			if (cyborgbear::isString(obj0)) {
				this->Import = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Images");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->Images.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj1);
						if (cyborgbear::isObj(finalObj)) {
							retval |= this->Images[i].loadJsonObj(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	return retval;
}

cyborgbear::Error Sprite::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "AnimLayers");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->AnimLayers.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					if (!cyborgbear::isNull(obj1)) {
						if (cyborgbear::isArray(obj1)) {
							cyborgbear::JsonArrayOut array1 = cyborgbear::toArray(obj1);
							unsigned int size = cyborgbear::arraySize(array1);
							this->AnimLayers[i].resize(size);
							for (unsigned int ii = 0; ii < size; ii++) {
								cyborgbear::JsonValOut obj2 = cyborgbear::arrayRead(array1, ii);
								{
									cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj2);
									if (cyborgbear::isObj(finalObj)) {
										retval |= this->AnimLayers[i][ii].loadJsonObj(obj2);
									} else {
										if (cyborgbear::isNull(obj2)) {
											retval |= cyborgbear::Error_MissingField;
										} else {
											retval |= cyborgbear::Error_TypeMismatch;
										}
									}
								}
							}
						} else {
							retval |= cyborgbear::Error_TypeMismatch;
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "SpriteType");
		{
			if (cyborgbear::isInt(obj0)) {
				this->SpriteType = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "PersonID");
		{
			if (cyborgbear::isInt(obj0)) {
				this->PersonID = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Speed");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Speed = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Name");
		{
			if (cyborgbear::isString(obj0)) {
				this->Name = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Path");
		{
			if (cyborgbear::isString(obj0)) {
				this->Path = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "ScriptPath");
		{
			if (cyborgbear::isString(obj0)) {
				this->ScriptPath = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error TileClass::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Import");
		{
			if (cyborgbear::isString(obj0)) {
				this->Import = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "TerrainFlags");
		{
			if (cyborgbear::isInt(obj0)) {
				this->TerrainFlags = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "LowerAnims");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->LowerAnims.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj1);
						if (cyborgbear::isObj(finalObj)) {
							retval |= this->LowerAnims[i].loadJsonObj(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "UpperAnims");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->UpperAnims.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj1);
						if (cyborgbear::isObj(finalObj)) {
							retval |= this->UpperAnims[i].loadJsonObj(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	return retval;
}

cyborgbear::Error Tile::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "TileClass");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->TileClass.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Occupant");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->Occupant.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error CreatureClass::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Name");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isObj(obj0)) {
				cyborgbear::JsonObjOut map0 = cyborgbear::toObj(obj0);
				for (cyborgbear::JsonObjIterator it1 = cyborgbear::jsonObjIterator(map0); !cyborgbear::iteratorAtEnd(it1, map0); it1 = cyborgbear::jsonObjIteratorNext(map0,  it1)) {
					string i;
					cyborgbear::JsonValOut obj1 = cyborgbear::iteratorValue(it1);
					{
						std::string key = cyborgbear::toStdString(cyborgbear::jsonObjIteratorKey(it1));
						std::string o;
						std::stringstream s;
						s << key;
						s >> o;
						i = o.c_str();
					}
					{
						if (cyborgbear::isString(obj1)) {
							this->Name[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Successor");
		{
			if (cyborgbear::isString(obj0)) {
				this->Successor = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Predecessor");
		{
			if (cyborgbear::isString(obj0)) {
				this->Predecessor = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Types");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->Types.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						if (cyborgbear::isString(obj1)) {
							this->Types[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "CanLearn");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->CanLearn.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						if (cyborgbear::isString(obj1)) {
							this->CanLearn[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "LearnsAtLevel");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isObj(obj0)) {
				cyborgbear::JsonObjOut map0 = cyborgbear::toObj(obj0);
				for (cyborgbear::JsonObjIterator it1 = cyborgbear::jsonObjIterator(map0); !cyborgbear::iteratorAtEnd(it1, map0); it1 = cyborgbear::jsonObjIteratorNext(map0,  it1)) {
					int i;
					cyborgbear::JsonValOut obj1 = cyborgbear::iteratorValue(it1);
					{
						std::string key = cyborgbear::toStdString(cyborgbear::jsonObjIteratorKey(it1));
						std::stringstream s;
						s << key;
						s >> i;
					}
					{
						if (cyborgbear::isString(obj1)) {
							this->LearnsAtLevel[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "FrontView");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->FrontView.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "BackView");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->BackView.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error World::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Zones");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->Zones.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj1);
						if (cyborgbear::isObj(finalObj)) {
							retval |= this->Zones[i].loadJsonObj(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	return retval;
}

cyborgbear::Error PersonClass::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "ID");
		{
			if (cyborgbear::isInt(obj0)) {
				this->ID = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Name");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isObj(obj0)) {
				cyborgbear::JsonObjOut map0 = cyborgbear::toObj(obj0);
				for (cyborgbear::JsonObjIterator it1 = cyborgbear::jsonObjIterator(map0); !cyborgbear::iteratorAtEnd(it1, map0); it1 = cyborgbear::jsonObjIteratorNext(map0,  it1)) {
					string i;
					cyborgbear::JsonValOut obj1 = cyborgbear::iteratorValue(it1);
					{
						std::string key = cyborgbear::toStdString(cyborgbear::jsonObjIteratorKey(it1));
						std::string o;
						std::stringstream s;
						s << key;
						s >> o;
						i = o.c_str();
					}
					{
						if (cyborgbear::isString(obj1)) {
							this->Name[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Creatures");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->Creatures.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						if (cyborgbear::isInt(obj1)) {
							this->Creatures[i] = cyborgbear::toInt(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Overhead");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->Overhead.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj1);
						if (cyborgbear::isObj(finalObj)) {
							retval |= this->Overhead[i].loadJsonObj(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "FrontView");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->FrontView.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "BackView");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->BackView.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error Person::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "PersonClass");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->PersonClass.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error SaveFile::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Vars");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isObj(obj0)) {
				cyborgbear::JsonObjOut map0 = cyborgbear::toObj(obj0);
				for (cyborgbear::JsonObjIterator it1 = cyborgbear::jsonObjIterator(map0); !cyborgbear::iteratorAtEnd(it1, map0); it1 = cyborgbear::jsonObjIteratorNext(map0,  it1)) {
					string i;
					cyborgbear::JsonValOut obj1 = cyborgbear::iteratorValue(it1);
					{
						std::string key = cyborgbear::toStdString(cyborgbear::jsonObjIteratorKey(it1));
						std::string o;
						std::stringstream s;
						s << key;
						s >> o;
						i = o.c_str();
					}
					{
						retval |= this->Vars[i].loadJsonObj(obj1);
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "User");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->User.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error Zone::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Tiles");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->Tiles.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					if (!cyborgbear::isNull(obj1)) {
						if (cyborgbear::isArray(obj1)) {
							cyborgbear::JsonArrayOut array1 = cyborgbear::toArray(obj1);
							unsigned int size = cyborgbear::arraySize(array1);
							this->Tiles[i].resize(size);
							for (unsigned int ii = 0; ii < size; ii++) {
								cyborgbear::JsonValOut obj2 = cyborgbear::arrayRead(array1, ii);
								if (!cyborgbear::isNull(obj2)) {
									if (cyborgbear::isArray(obj2)) {
										cyborgbear::JsonArrayOut array2 = cyborgbear::toArray(obj2);
										unsigned int size = cyborgbear::arraySize(array2);
										this->Tiles[i][ii].resize(size);
										for (unsigned int iii = 0; iii < size; iii++) {
											cyborgbear::JsonValOut obj3 = cyborgbear::arrayRead(array2, iii);
											{
												cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj3);
												if (cyborgbear::isObj(finalObj)) {
													retval |= this->Tiles[i][ii][iii].loadJsonObj(obj3);
												} else {
													if (cyborgbear::isNull(obj3)) {
														retval |= cyborgbear::Error_MissingField;
													} else {
														retval |= cyborgbear::Error_TypeMismatch;
													}
												}
											}
										}
									} else {
										retval |= cyborgbear::Error_TypeMismatch;
									}
								}
							}
						} else {
							retval |= cyborgbear::Error_TypeMismatch;
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "InitScripts");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->InitScripts.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						if (cyborgbear::isString(obj1)) {
							this->InitScripts[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Location");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->Location.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error ZoneHeader::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Path");
		{
			if (cyborgbear::isString(obj0)) {
				this->Path = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Size");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->Size.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::JsonValOut CreatureType::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< string, string >::iterator n = this->Name.begin(); n != this->Name.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgbear::toStdString(cyborgbear::toString(n->first));
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Name[n->first]);
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Name", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Special);
		cyborgbear::objSet(obj, "Special", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->StrongAgainst.size(); i++) {
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->StrongAgainst[i]);
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "StrongAgainst", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->WeakAgainst.size(); i++) {
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->WeakAgainst[i]);
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "WeakAgainst", out1);
		cyborgbear::decref(out1);
	}
	return obj;
}

cyborgbear::JsonValOut StatusEffect::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->AttackerEffect);
		cyborgbear::objSet(obj, "AttackerEffect", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->EnemyEffect);
		cyborgbear::objSet(obj, "EnemyEffect", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Fraction::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Current);
		cyborgbear::objSet(obj, "Current", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Available);
		cyborgbear::objSet(obj, "Available", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut ModelFile::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Type);
		cyborgbear::objSet(obj, "Type", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Point::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->X);
		cyborgbear::objSet(obj, "X", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Y);
		cyborgbear::objSet(obj, "Y", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Size::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Width);
		cyborgbear::objSet(obj, "Width", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Height);
		cyborgbear::objSet(obj, "Height", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Bounds::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->X);
		cyborgbear::objSet(obj, "X", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Y);
		cyborgbear::objSet(obj, "Y", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Width);
		cyborgbear::objSet(obj, "Width", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Height);
		cyborgbear::objSet(obj, "Height", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut SaveVariables::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< string, cyborgbear::unknown >::iterator n = this->Vars.begin(); n != this->Vars.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgbear::toStdString(cyborgbear::toString(n->first));
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut obj0 = this->Vars[n->first].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Vars", out1);
		cyborgbear::decref(out1);
	}
	return obj;
}

cyborgbear::JsonValOut SpriteSheetImage::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut obj0 = this->SrcBounds.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "SrcBounds", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut SpriteSheet::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->TilesWide);
		cyborgbear::objSet(obj, "TilesWide", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->TilesHigh);
		cyborgbear::objSet(obj, "TilesHigh", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->TileWidth);
		cyborgbear::objSet(obj, "TileWidth", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->TileHeight);
		cyborgbear::objSet(obj, "TileHeight", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->SrcFile);
		cyborgbear::objSet(obj, "SrcFile", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< int, models::SpriteSheetImage >::iterator n = this->Images.begin(); n != this->Images.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << n->first;
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut obj0 = this->Images[n->first].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Images", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->ImageIdIterator);
		cyborgbear::objSet(obj, "ImageIdIterator", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->RecycledImageIds.size(); i++) {
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->RecycledImageIds[i]);
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "RecycledImageIds", out1);
		cyborgbear::decref(out1);
	}
	return obj;
}

cyborgbear::JsonValOut Image::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->SpriteSheet);
		cyborgbear::objSet(obj, "SpriteSheet", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->ImgId);
		cyborgbear::objSet(obj, "ImgId", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->DefaultSize.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "DefaultSize", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut AnimationSlide::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Interval);
		cyborgbear::objSet(obj, "Interval", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->Image.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Image", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut AnimLayer::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut obj0 = this->Point.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Point", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Animation);
		cyborgbear::objSet(obj, "Animation", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Settings::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Fullscreen);
		cyborgbear::objSet(obj, "Fullscreen", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Width);
		cyborgbear::objSet(obj, "Width", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Height);
		cyborgbear::objSet(obj, "Height", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut CreatureMove::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< string, string >::iterator n = this->Name.begin(); n != this->Name.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgbear::toStdString(cyborgbear::toString(n->first));
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Name[n->first]);
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Name", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Type);
		cyborgbear::objSet(obj, "Type", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Power);
		cyborgbear::objSet(obj, "Power", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->RequiresRegarge);
		cyborgbear::objSet(obj, "RequiresRegarge", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Script);
		cyborgbear::objSet(obj, "Script", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->Burn.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Burn", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->Freeze.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Freeze", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->Paralyze.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Paralyze", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->Poison.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Poison", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->Sleep.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Sleep", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut CreatureMoveInstance::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->CreatureMove);
		cyborgbear::objSet(obj, "CreatureMove", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->PP.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "PP", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Creature::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->ID);
		cyborgbear::objSet(obj, "ID", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< string, string >::iterator n = this->Name.begin(); n != this->Name.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgbear::toStdString(cyborgbear::toString(n->first));
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Name[n->first]);
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Name", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->CreatureClass);
		cyborgbear::objSet(obj, "CreatureClass", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Male);
		cyborgbear::objSet(obj, "Male", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Level);
		cyborgbear::objSet(obj, "Level", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->Health.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Health", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Attack);
		cyborgbear::objSet(obj, "Attack", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->SpecAttack);
		cyborgbear::objSet(obj, "SpecAttack", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Defense);
		cyborgbear::objSet(obj, "Defense", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->SpecDefense);
		cyborgbear::objSet(obj, "SpecDefense", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Burned);
		cyborgbear::objSet(obj, "Burned", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Frozen);
		cyborgbear::objSet(obj, "Frozen", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Poisoned);
		cyborgbear::objSet(obj, "Poisoned", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Asleep);
		cyborgbear::objSet(obj, "Asleep", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->Moves.size(); i++) {
			cyborgbear::JsonValOut obj0 = this->Moves[i].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Moves", out1);
		cyborgbear::decref(out1);
	}
	return obj;
}

cyborgbear::JsonValOut User::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->PersonID);
		cyborgbear::objSet(obj, "PersonID", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->World);
		cyborgbear::objSet(obj, "World", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Zone);
		cyborgbear::objSet(obj, "Zone", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->XAddress);
		cyborgbear::objSet(obj, "XAddress", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->YAddress);
		cyborgbear::objSet(obj, "YAddress", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Layer);
		cyborgbear::objSet(obj, "Layer", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut ZoneInstance::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->AccessorID);
		cyborgbear::objSet(obj, "AccessorID", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->ZonePath);
		cyborgbear::objSet(obj, "ZonePath", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->Location.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Location", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Animation::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Import);
		cyborgbear::objSet(obj, "Import", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->Images.size(); i++) {
			cyborgbear::JsonValOut obj0 = this->Images[i].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Images", out1);
		cyborgbear::decref(out1);
	}
	return obj;
}

cyborgbear::JsonValOut Sprite::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonArrayOut out2 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->AnimLayers.size(); i++) {
			cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
			for (cyborgbear::VectorIterator ii = 0; ii < this->AnimLayers[i].size(); ii++) {
				cyborgbear::JsonValOut obj0 = this->AnimLayers[i][ii].buildJsonObj();
				cyborgbear::JsonValOut out0 = obj0;
				cyborgbear::arrayAdd(out1, out0);
				cyborgbear::decref(out0);
			}
			cyborgbear::arrayAdd(out2, out1);
			cyborgbear::decref(out1);
		}
		cyborgbear::objSet(obj, "AnimLayers", out2);
		cyborgbear::decref(out2);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->SpriteType);
		cyborgbear::objSet(obj, "SpriteType", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->PersonID);
		cyborgbear::objSet(obj, "PersonID", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Speed);
		cyborgbear::objSet(obj, "Speed", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Name);
		cyborgbear::objSet(obj, "Name", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Path);
		cyborgbear::objSet(obj, "Path", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->ScriptPath);
		cyborgbear::objSet(obj, "ScriptPath", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut TileClass::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Import);
		cyborgbear::objSet(obj, "Import", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->TerrainFlags);
		cyborgbear::objSet(obj, "TerrainFlags", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->LowerAnims.size(); i++) {
			cyborgbear::JsonValOut obj0 = this->LowerAnims[i].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "LowerAnims", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->UpperAnims.size(); i++) {
			cyborgbear::JsonValOut obj0 = this->UpperAnims[i].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "UpperAnims", out1);
		cyborgbear::decref(out1);
	}
	return obj;
}

cyborgbear::JsonValOut Tile::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut obj0 = this->TileClass.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "TileClass", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->Occupant.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Occupant", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut CreatureClass::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< string, string >::iterator n = this->Name.begin(); n != this->Name.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgbear::toStdString(cyborgbear::toString(n->first));
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Name[n->first]);
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Name", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Successor);
		cyborgbear::objSet(obj, "Successor", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Predecessor);
		cyborgbear::objSet(obj, "Predecessor", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->Types.size(); i++) {
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Types[i]);
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Types", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->CanLearn.size(); i++) {
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->CanLearn[i]);
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "CanLearn", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< int, string >::iterator n = this->LearnsAtLevel.begin(); n != this->LearnsAtLevel.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << n->first;
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->LearnsAtLevel[n->first]);
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "LearnsAtLevel", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut obj0 = this->FrontView.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "FrontView", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->BackView.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "BackView", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut World::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->Zones.size(); i++) {
			cyborgbear::JsonValOut obj0 = this->Zones[i].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Zones", out1);
		cyborgbear::decref(out1);
	}
	return obj;
}

cyborgbear::JsonValOut PersonClass::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->ID);
		cyborgbear::objSet(obj, "ID", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< string, string >::iterator n = this->Name.begin(); n != this->Name.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgbear::toStdString(cyborgbear::toString(n->first));
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Name[n->first]);
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Name", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->Creatures.size(); i++) {
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Creatures[i]);
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Creatures", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->Overhead.size(); i++) {
			cyborgbear::JsonValOut obj0 = this->Overhead[i].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Overhead", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut obj0 = this->FrontView.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "FrontView", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->BackView.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "BackView", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Person::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut obj0 = this->PersonClass.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "PersonClass", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut SaveFile::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< string, cyborgbear::unknown >::iterator n = this->Vars.begin(); n != this->Vars.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgbear::toStdString(cyborgbear::toString(n->first));
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut obj0 = this->Vars[n->first].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Vars", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut obj0 = this->User.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "User", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Zone::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonArrayOut out3 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->Tiles.size(); i++) {
			cyborgbear::JsonArrayOut out2 = cyborgbear::newJsonArray();
			for (cyborgbear::VectorIterator ii = 0; ii < this->Tiles[i].size(); ii++) {
				cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
				for (cyborgbear::VectorIterator iii = 0; iii < this->Tiles[i][ii].size(); iii++) {
					cyborgbear::JsonValOut obj0 = this->Tiles[i][ii][iii].buildJsonObj();
					cyborgbear::JsonValOut out0 = obj0;
					cyborgbear::arrayAdd(out1, out0);
					cyborgbear::decref(out0);
				}
				cyborgbear::arrayAdd(out2, out1);
				cyborgbear::decref(out1);
			}
			cyborgbear::arrayAdd(out3, out2);
			cyborgbear::decref(out2);
		}
		cyborgbear::objSet(obj, "Tiles", out3);
		cyborgbear::decref(out3);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->InitScripts.size(); i++) {
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->InitScripts[i]);
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "InitScripts", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut obj0 = this->Location.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Location", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut ZoneHeader::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Path);
		cyborgbear::objSet(obj, "Path", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->Size.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Size", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void CreatureType::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string CreatureType::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void StatusEffect::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string StatusEffect::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Fraction::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Fraction::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void ModelFile::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string ModelFile::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Point::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Point::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Size::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Size::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Bounds::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Bounds::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void SaveVariables::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string SaveVariables::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void SpriteSheetImage::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string SpriteSheetImage::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void SpriteSheet::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string SpriteSheet::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Image::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Image::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void AnimationSlide::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string AnimationSlide::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void AnimLayer::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string AnimLayer::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Settings::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Settings::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void CreatureMove::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string CreatureMove::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void CreatureMoveInstance::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string CreatureMoveInstance::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Creature::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Creature::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void User::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string User::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void ZoneInstance::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string ZoneInstance::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Animation::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Animation::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Sprite::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Sprite::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void TileClass::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string TileClass::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Tile::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Tile::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void CreatureClass::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string CreatureClass::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void World::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string World::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void PersonClass::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string PersonClass::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Person::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Person::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void SaveFile::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string SaveFile::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Zone::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Zone::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void ZoneHeader::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string ZoneHeader::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}
