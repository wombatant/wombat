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

#include <fstream>
#include "enginemodels.hpp"

using namespace models;
using namespace models::cyborgbear;

bool Model::readJsonFile(string path) {
	std::ifstream in;
	in.open(cyborgbear::toCString(path));
	std::string json;
	if (in.is_open()) {
		while (in.good()) {
			std::string s;
			in >> s;
			json += s;
		}
		in.close();
		fromJson(cyborgbear::toString(json));
		return true;
	}
	return false;
}

void Model::writeJsonFile(string path, cyborgbear::JsonSerializationSettings sttngs) {
	std::ofstream out;
	out.open(cyborgbear::toCString(path));
	std::string json = cyborgbear::toStdString(toJson(sttngs));
	out << json << "\n";
	out.close();
}

void Model::fromJson(string json) {
	cyborgbear::JsonValOut obj = cyborgbear::read(json);
	loadJsonObj(obj);
	cyborgbear::decref(obj);
}

string Model::toJson(cyborgbear::JsonSerializationSettings sttngs) {
	cyborgbear::JsonValOut val = buildJsonObj();
	cyborgbear::JsonObjOut obj = cyborgbear::toObj(val);
	return cyborgbear::write(obj, sttngs);
}

unknown::unknown() {
#ifndef CYBORGBEAR_USING_QT
	m_obj = 0;
#endif
}

unknown::unknown(Model *v) {
#ifndef CYBORGBEAR_USING_QT
	m_obj = 0;
#endif
	set(v);
}

unknown::unknown(bool v) {
#ifndef CYBORGBEAR_USING_QT
	m_obj = 0;
#endif
	set(v);
}

unknown::unknown(int v) {
#ifndef CYBORGBEAR_USING_QT
	m_obj = 0;
#endif
	set(v);
}

unknown::unknown(double v) {
#ifndef CYBORGBEAR_USING_QT
	m_obj = 0;
#endif
	set(v);
}

unknown::unknown(string v) {
#ifndef CYBORGBEAR_USING_QT
	m_obj = 0;
#endif
	set(v);
}

unknown::~unknown() {
	cyborgbear::decref(m_obj);
}

bool unknown::loadJsonObj(cyborgbear::JsonVal obj) {
#ifdef CYBORGBEAR_USING_JANSSON
	m_obj = cyborgbear::incref(obj);
#else
	m_obj = obj;
#endif
	return !cyborgbear::isNull(obj);
}

cyborgbear::JsonValOut unknown::buildJsonObj() {
#ifdef CYBORGBEAR_USING_JANSSON
	return cyborgbear::incref(m_obj);
#else
	return m_obj;
#endif
}

bool unknown::loaded() {
	return !cyborgbear::isNull(m_obj);
}

bool unknown::isBool() {
	return !cyborgbear::isNull(m_obj) && cyborgbear::isBool(m_obj);
}

bool unknown::isInt() {
	return !cyborgbear::isNull(m_obj) && cyborgbear::isInt(m_obj);
}

bool unknown::isDouble() {
	return !cyborgbear::isNull(m_obj) && cyborgbear::isDouble(m_obj);
}

bool unknown::isString() {
	return !cyborgbear::isNull(m_obj) && cyborgbear::isString(m_obj);
}

bool unknown::isObject() {
	return !cyborgbear::isNull(m_obj) && cyborgbear::isObj(m_obj);
}

bool unknown::toBool() {
	return cyborgbear::toBool(m_obj);
}

int unknown::toInt() {
	return cyborgbear::toInt(m_obj);
}

double unknown::toDouble() {
	return cyborgbear::toDouble(m_obj);
}

string unknown::toString() {
	return cyborgbear::toString(m_obj);
}

void unknown::set(Model *v) {
	cyborgbear::JsonValOut obj = v->buildJsonObj();
	cyborgbear::JsonVal old = m_obj;
	m_obj = obj;
	if (!cyborgbear::isNull(old)) {
		cyborgbear::decref(old);
	}
}

void unknown::set(bool v) {
	cyborgbear::JsonValOut obj = cyborgbear::toJsonVal(v);
	cyborgbear::JsonVal old = m_obj;
	m_obj = obj;
	if (!cyborgbear::isNull(old)) {
		cyborgbear::decref(old);
	}
}

void unknown::set(int v) {
	cyborgbear::JsonValOut obj = cyborgbear::toJsonVal(v);
	cyborgbear::JsonVal old = m_obj;
	m_obj = obj;
	if (!cyborgbear::isNull(old)) {
		cyborgbear::decref(old);
	}
}

void unknown::set(double v) {
	cyborgbear::JsonValOut obj = cyborgbear::toJsonVal(v);
	cyborgbear::JsonVal old = m_obj;
	m_obj = obj;
	if (!cyborgbear::isNull(old)) {
		cyborgbear::decref(old);
	}
}

void unknown::set(string v) {
	cyborgbear::JsonValOut obj = cyborgbear::toJsonVal(v);
	cyborgbear::JsonVal old = m_obj;
	m_obj = obj;
	if (!cyborgbear::isNull(old)) {
		cyborgbear::decref(old);
	}
}


#include "string.h"
#include "enginemodels.hpp"

using namespace models;
using std::stringstream;

CreatureType::CreatureType() {
	this->special = 0;
}

StatusEffect::StatusEffect() {
	this->attackerEffect = 0;
	this->enemyEffect = 0;
}

Fraction::Fraction() {
	this->current = 0;
	this->available = 0;
}

ModelFile::ModelFile() {
	this->type = "";
}

Point::Point() {
	this->x = 0;
	this->y = 0;
}

Size::Size() {
	this->width = 0;
	this->height = 0;
}

Bounds::Bounds() {
	this->x = 0;
	this->y = 0;
	this->width = 0;
	this->height = 0;
}

CreatureMove::CreatureMove() {
	this->type = "";
	this->power = 0;
	this->requiresRegarge = 0;
	this->script = "";
}

CreatureMoveInstance::CreatureMoveInstance() {
	this->creatureMove = 0;
}

Creature::Creature() {
	this->iD = 0;
	this->creatureClass = "";
	this->male = 0;
	this->level = 0;
	this->attack = 0;
	this->specAttack = 0;
	this->defense = 0;
	this->specDefense = 0;
	this->burned = 0;
	this->frozen = 0;
	this->poisoned = 0;
	this->asleep = 0;
}

User::User() {
	this->personID = 0;
	this->world = "";
	this->zone = "";
	this->xAddress = 0;
	this->yAddress = 0;
	this->layer = 0;
}

ZoneInstance::ZoneInstance() {
	this->accessorID = "";
	this->path = "";
}

Image::Image() {
	this->path = "";
}

ZoneHeader::ZoneHeader() {
	this->path = "";
}

Animation::Animation() {
	this->interval = 0;
}

AnimLayer::AnimLayer() {
}

SaveFile::SaveFile() {
}

CreatureClass::CreatureClass() {
	this->successor = "";
	this->predecessor = "";
}

TileClass::TileClass() {
	this->terrainFlags = 0;
	this->import = "";
}

Sprite::Sprite() {
	this->spriteType = 0;
	this->personID = 0;
	this->speed = 0;
	this->name = "";
	this->path = "";
	this->scriptPath = "";
}

PersonClass::PersonClass() {
	this->iD = 0;
}

Person::Person() {
}

Tile::Tile() {
}

World::World() {
}

Zone::Zone() {
}

bool CreatureType::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Name");
		if (!cyborgbear::isNull(obj0) && cyborgbear::isObj(obj0)) {
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
						this->name[i] = cyborgbear::toString(obj1);
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Special");
		{
			if (cyborgbear::isBool(obj0)) {
				this->special = cyborgbear::toBool(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "StrongAgainst");
		if (!cyborgbear::isNull(obj0) && cyborgbear::isArray(obj0)) {
			cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
			unsigned int size = cyborgbear::arraySize(array0);
			this->strongAgainst.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
				{
					if (cyborgbear::isString(obj1)) {
						this->strongAgainst[i] = cyborgbear::toString(obj1);
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "WeakAgainst");
		if (!cyborgbear::isNull(obj0) && cyborgbear::isArray(obj0)) {
			cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
			unsigned int size = cyborgbear::arraySize(array0);
			this->weakAgainst.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
				{
					if (cyborgbear::isString(obj1)) {
						this->weakAgainst[i] = cyborgbear::toString(obj1);
					}
				}
			}
		}
	}
	return true;
}

bool StatusEffect::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "AttackerEffect");
		{
			if (cyborgbear::isInt(obj0)) {
				this->attackerEffect = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "EnemyEffect");
		{
			if (cyborgbear::isInt(obj0)) {
				this->enemyEffect = cyborgbear::toInt(obj0);
			}
		}
	}
	return true;
}

bool Fraction::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Current");
		{
			if (cyborgbear::isInt(obj0)) {
				this->current = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Available");
		{
			if (cyborgbear::isInt(obj0)) {
				this->available = cyborgbear::toInt(obj0);
			}
		}
	}
	return true;
}

bool ModelFile::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Type");
		{
			if (cyborgbear::isString(obj0)) {
				this->type = cyborgbear::toString(obj0);
			}
		}
	}
	return true;
}

bool Point::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "X");
		{
			if (cyborgbear::isInt(obj0)) {
				this->x = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Y");
		{
			if (cyborgbear::isInt(obj0)) {
				this->y = cyborgbear::toInt(obj0);
			}
		}
	}
	return true;
}

bool Size::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Width");
		{
			if (cyborgbear::isInt(obj0)) {
				this->width = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Height");
		{
			if (cyborgbear::isInt(obj0)) {
				this->height = cyborgbear::toInt(obj0);
			}
		}
	}
	return true;
}

bool Bounds::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "X");
		{
			if (cyborgbear::isInt(obj0)) {
				this->x = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Y");
		{
			if (cyborgbear::isInt(obj0)) {
				this->y = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Width");
		{
			if (cyborgbear::isInt(obj0)) {
				this->width = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Height");
		{
			if (cyborgbear::isInt(obj0)) {
				this->height = cyborgbear::toInt(obj0);
			}
		}
	}
	return true;
}

bool CreatureMove::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Name");
		if (!cyborgbear::isNull(obj0) && cyborgbear::isObj(obj0)) {
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
						this->name[i] = cyborgbear::toString(obj1);
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Type");
		{
			if (cyborgbear::isString(obj0)) {
				this->type = cyborgbear::toString(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Power");
		{
			if (cyborgbear::isInt(obj0)) {
				this->power = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "RequiresRegarge");
		{
			if (cyborgbear::isBool(obj0)) {
				this->requiresRegarge = cyborgbear::toBool(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Script");
		{
			if (cyborgbear::isString(obj0)) {
				this->script = cyborgbear::toString(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Burn");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				this->burn.loadJsonObj(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Freeze");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				this->freeze.loadJsonObj(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Paralyze");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				this->paralyze.loadJsonObj(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Poison");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				this->poison.loadJsonObj(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Sleep");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				this->sleep.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

bool CreatureMoveInstance::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "CreatureMove");
		{
			if (cyborgbear::isInt(obj0)) {
				this->creatureMove = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "PP");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				this->pP.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

bool Creature::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "ID");
		{
			if (cyborgbear::isInt(obj0)) {
				this->iD = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Name");
		if (!cyborgbear::isNull(obj0) && cyborgbear::isObj(obj0)) {
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
						this->name[i] = cyborgbear::toString(obj1);
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "CreatureClass");
		{
			if (cyborgbear::isString(obj0)) {
				this->creatureClass = cyborgbear::toString(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Male");
		{
			if (cyborgbear::isBool(obj0)) {
				this->male = cyborgbear::toBool(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Level");
		{
			if (cyborgbear::isInt(obj0)) {
				this->level = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Health");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				this->health.loadJsonObj(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Attack");
		{
			if (cyborgbear::isInt(obj0)) {
				this->attack = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "SpecAttack");
		{
			if (cyborgbear::isInt(obj0)) {
				this->specAttack = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Defense");
		{
			if (cyborgbear::isInt(obj0)) {
				this->defense = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "SpecDefense");
		{
			if (cyborgbear::isInt(obj0)) {
				this->specDefense = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Burned");
		{
			if (cyborgbear::isBool(obj0)) {
				this->burned = cyborgbear::toBool(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Frozen");
		{
			if (cyborgbear::isBool(obj0)) {
				this->frozen = cyborgbear::toBool(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Poisoned");
		{
			if (cyborgbear::isBool(obj0)) {
				this->poisoned = cyborgbear::toBool(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Asleep");
		{
			if (cyborgbear::isBool(obj0)) {
				this->asleep = cyborgbear::toBool(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Moves");
		if (!cyborgbear::isNull(obj0) && cyborgbear::isArray(obj0)) {
			cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
			unsigned int size = cyborgbear::arraySize(array0);
			this->moves.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
				{
					cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj1);
					if (cyborgbear::isObj(finalObj)) {
						this->moves[i].loadJsonObj(obj1);
					}
				}
			}
		}
	}
	return true;
}

bool User::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "PersonID");
		{
			if (cyborgbear::isInt(obj0)) {
				this->personID = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "World");
		{
			if (cyborgbear::isString(obj0)) {
				this->world = cyborgbear::toString(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Zone");
		{
			if (cyborgbear::isString(obj0)) {
				this->zone = cyborgbear::toString(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "XAddress");
		{
			if (cyborgbear::isInt(obj0)) {
				this->xAddress = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "YAddress");
		{
			if (cyborgbear::isInt(obj0)) {
				this->yAddress = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Layer");
		{
			if (cyborgbear::isInt(obj0)) {
				this->layer = cyborgbear::toInt(obj0);
			}
		}
	}
	return true;
}

bool ZoneInstance::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "AccessorID");
		{
			if (cyborgbear::isString(obj0)) {
				this->accessorID = cyborgbear::toString(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Path");
		{
			if (cyborgbear::isString(obj0)) {
				this->path = cyborgbear::toString(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Location");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				this->location.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

bool Image::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Path");
		{
			if (cyborgbear::isString(obj0)) {
				this->path = cyborgbear::toString(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "DefaultSize");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				this->defaultSize.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

bool ZoneHeader::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Path");
		{
			if (cyborgbear::isString(obj0)) {
				this->path = cyborgbear::toString(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Size");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				this->size.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

bool Animation::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Interval");
		{
			if (cyborgbear::isInt(obj0)) {
				this->interval = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Images");
		if (!cyborgbear::isNull(obj0) && cyborgbear::isArray(obj0)) {
			cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
			unsigned int size = cyborgbear::arraySize(array0);
			this->images.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
				{
					cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj1);
					if (cyborgbear::isObj(finalObj)) {
						this->images[i].loadJsonObj(obj1);
					}
				}
			}
		}
	}
	return true;
}

bool AnimLayer::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Point");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				this->point.loadJsonObj(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Animation");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				this->animation.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

bool SaveFile::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Vars");
		if (!cyborgbear::isNull(obj0) && cyborgbear::isObj(obj0)) {
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
					this->vars[i].loadJsonObj(obj1);
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "User");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				this->user.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

bool CreatureClass::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Name");
		if (!cyborgbear::isNull(obj0) && cyborgbear::isObj(obj0)) {
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
						this->name[i] = cyborgbear::toString(obj1);
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Successor");
		{
			if (cyborgbear::isString(obj0)) {
				this->successor = cyborgbear::toString(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Predecessor");
		{
			if (cyborgbear::isString(obj0)) {
				this->predecessor = cyborgbear::toString(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Types");
		if (!cyborgbear::isNull(obj0) && cyborgbear::isArray(obj0)) {
			cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
			unsigned int size = cyborgbear::arraySize(array0);
			this->types.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
				{
					if (cyborgbear::isString(obj1)) {
						this->types[i] = cyborgbear::toString(obj1);
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "CanLearn");
		if (!cyborgbear::isNull(obj0) && cyborgbear::isArray(obj0)) {
			cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
			unsigned int size = cyborgbear::arraySize(array0);
			this->canLearn.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
				{
					if (cyborgbear::isString(obj1)) {
						this->canLearn[i] = cyborgbear::toString(obj1);
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "LearnsAtLevel");
		if (!cyborgbear::isNull(obj0) && cyborgbear::isObj(obj0)) {
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
						this->learnsAtLevel[i] = cyborgbear::toString(obj1);
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
				this->frontView.loadJsonObj(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "BackView");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				this->backView.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

bool TileClass::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "TerrainFlags");
		{
			if (cyborgbear::isInt(obj0)) {
				this->terrainFlags = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Import");
		{
			if (cyborgbear::isString(obj0)) {
				this->import = cyborgbear::toString(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "LowerAnims");
		if (!cyborgbear::isNull(obj0) && cyborgbear::isArray(obj0)) {
			cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
			unsigned int size = cyborgbear::arraySize(array0);
			this->lowerAnims.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
				{
					cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj1);
					if (cyborgbear::isObj(finalObj)) {
						this->lowerAnims[i].loadJsonObj(obj1);
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "UpperAnims");
		if (!cyborgbear::isNull(obj0) && cyborgbear::isArray(obj0)) {
			cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
			unsigned int size = cyborgbear::arraySize(array0);
			this->upperAnims.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
				{
					cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj1);
					if (cyborgbear::isObj(finalObj)) {
						this->upperAnims[i].loadJsonObj(obj1);
					}
				}
			}
		}
	}
	return true;
}

bool Sprite::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "AnimLayers");
		if (!cyborgbear::isNull(obj0) && cyborgbear::isArray(obj0)) {
			cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
			unsigned int size = cyborgbear::arraySize(array0);
			this->animLayers.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
				if (!cyborgbear::isNull(obj1) && cyborgbear::isArray(obj1)) {
					cyborgbear::JsonArrayOut array1 = cyborgbear::toArray(obj1);
					unsigned int size = cyborgbear::arraySize(array1);
					this->animLayers[i].resize(size);
					for (unsigned int ii = 0; ii < size; ii++) {
						cyborgbear::JsonValOut obj2 = cyborgbear::arrayRead(array1, ii);
						{
							cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj2);
							if (cyborgbear::isObj(finalObj)) {
								this->animLayers[i][ii].loadJsonObj(obj2);
							}
						}
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "SpriteType");
		{
			if (cyborgbear::isInt(obj0)) {
				this->spriteType = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "PersonID");
		{
			if (cyborgbear::isInt(obj0)) {
				this->personID = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Speed");
		{
			if (cyborgbear::isInt(obj0)) {
				this->speed = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Name");
		{
			if (cyborgbear::isString(obj0)) {
				this->name = cyborgbear::toString(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Path");
		{
			if (cyborgbear::isString(obj0)) {
				this->path = cyborgbear::toString(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "ScriptPath");
		{
			if (cyborgbear::isString(obj0)) {
				this->scriptPath = cyborgbear::toString(obj0);
			}
		}
	}
	return true;
}

bool PersonClass::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "ID");
		{
			if (cyborgbear::isInt(obj0)) {
				this->iD = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Name");
		if (!cyborgbear::isNull(obj0) && cyborgbear::isObj(obj0)) {
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
						this->name[i] = cyborgbear::toString(obj1);
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Creatures");
		if (!cyborgbear::isNull(obj0) && cyborgbear::isArray(obj0)) {
			cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
			unsigned int size = cyborgbear::arraySize(array0);
			this->creatures.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
				{
					if (cyborgbear::isInt(obj1)) {
						this->creatures[i] = cyborgbear::toInt(obj1);
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Overhead");
		if (!cyborgbear::isNull(obj0) && cyborgbear::isArray(obj0)) {
			cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
			unsigned int size = cyborgbear::arraySize(array0);
			this->overhead.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
				{
					cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj1);
					if (cyborgbear::isObj(finalObj)) {
						this->overhead[i].loadJsonObj(obj1);
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
				this->frontView.loadJsonObj(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "BackView");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				this->backView.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

bool Person::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "PersonClass");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				this->personClass.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

bool Tile::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "TileClass");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				this->tileClass.loadJsonObj(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Occupant");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				this->occupant.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

bool World::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Zones");
		if (!cyborgbear::isNull(obj0) && cyborgbear::isArray(obj0)) {
			cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
			unsigned int size = cyborgbear::arraySize(array0);
			this->zones.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
				{
					cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj1);
					if (cyborgbear::isObj(finalObj)) {
						this->zones[i].loadJsonObj(obj1);
					}
				}
			}
		}
	}
	return true;
}

bool Zone::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Tiles");
		if (!cyborgbear::isNull(obj0) && cyborgbear::isArray(obj0)) {
			cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
			unsigned int size = cyborgbear::arraySize(array0);
			this->tiles.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
				if (!cyborgbear::isNull(obj1) && cyborgbear::isArray(obj1)) {
					cyborgbear::JsonArrayOut array1 = cyborgbear::toArray(obj1);
					unsigned int size = cyborgbear::arraySize(array1);
					this->tiles[i].resize(size);
					for (unsigned int ii = 0; ii < size; ii++) {
						cyborgbear::JsonValOut obj2 = cyborgbear::arrayRead(array1, ii);
						if (!cyborgbear::isNull(obj2) && cyborgbear::isArray(obj2)) {
							cyborgbear::JsonArrayOut array2 = cyborgbear::toArray(obj2);
							unsigned int size = cyborgbear::arraySize(array2);
							this->tiles[i][ii].resize(size);
							for (unsigned int iii = 0; iii < size; iii++) {
								cyborgbear::JsonValOut obj3 = cyborgbear::arrayRead(array2, iii);
								{
									cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj3);
									if (cyborgbear::isObj(finalObj)) {
										this->tiles[i][ii][iii].loadJsonObj(obj3);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "InitScripts");
		if (!cyborgbear::isNull(obj0) && cyborgbear::isArray(obj0)) {
			cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
			unsigned int size = cyborgbear::arraySize(array0);
			this->initScripts.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
				{
					if (cyborgbear::isString(obj1)) {
						this->initScripts[i] = cyborgbear::toString(obj1);
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Location");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				this->location.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

cyborgbear::JsonValOut CreatureType::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< string, string >::iterator n = this->name.begin(); n != this->name.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgbear::toStdString(cyborgbear::toString(n->first));
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->name[n->first]);
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Name", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->special);
		cyborgbear::objSet(obj, "Special", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->strongAgainst.size(); i++) {
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->strongAgainst[i]);
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "StrongAgainst", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->weakAgainst.size(); i++) {
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->weakAgainst[i]);
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
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->attackerEffect);
		cyborgbear::objSet(obj, "AttackerEffect", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->enemyEffect);
		cyborgbear::objSet(obj, "EnemyEffect", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Fraction::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->current);
		cyborgbear::objSet(obj, "Current", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->available);
		cyborgbear::objSet(obj, "Available", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut ModelFile::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->type);
		cyborgbear::objSet(obj, "Type", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Point::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->x);
		cyborgbear::objSet(obj, "X", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->y);
		cyborgbear::objSet(obj, "Y", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Size::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->width);
		cyborgbear::objSet(obj, "Width", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->height);
		cyborgbear::objSet(obj, "Height", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Bounds::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->x);
		cyborgbear::objSet(obj, "X", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->y);
		cyborgbear::objSet(obj, "Y", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->width);
		cyborgbear::objSet(obj, "Width", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->height);
		cyborgbear::objSet(obj, "Height", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut CreatureMove::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< string, string >::iterator n = this->name.begin(); n != this->name.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgbear::toStdString(cyborgbear::toString(n->first));
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->name[n->first]);
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Name", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->type);
		cyborgbear::objSet(obj, "Type", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->power);
		cyborgbear::objSet(obj, "Power", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->requiresRegarge);
		cyborgbear::objSet(obj, "RequiresRegarge", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->script);
		cyborgbear::objSet(obj, "Script", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->burn.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Burn", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->freeze.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Freeze", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->paralyze.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Paralyze", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->poison.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Poison", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->sleep.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Sleep", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut CreatureMoveInstance::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->creatureMove);
		cyborgbear::objSet(obj, "CreatureMove", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->pP.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "PP", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Creature::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->iD);
		cyborgbear::objSet(obj, "ID", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< string, string >::iterator n = this->name.begin(); n != this->name.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgbear::toStdString(cyborgbear::toString(n->first));
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->name[n->first]);
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Name", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->creatureClass);
		cyborgbear::objSet(obj, "CreatureClass", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->male);
		cyborgbear::objSet(obj, "Male", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->level);
		cyborgbear::objSet(obj, "Level", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->health.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Health", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->attack);
		cyborgbear::objSet(obj, "Attack", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->specAttack);
		cyborgbear::objSet(obj, "SpecAttack", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->defense);
		cyborgbear::objSet(obj, "Defense", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->specDefense);
		cyborgbear::objSet(obj, "SpecDefense", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->burned);
		cyborgbear::objSet(obj, "Burned", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->frozen);
		cyborgbear::objSet(obj, "Frozen", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->poisoned);
		cyborgbear::objSet(obj, "Poisoned", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->asleep);
		cyborgbear::objSet(obj, "Asleep", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->moves.size(); i++) {
			cyborgbear::JsonValOut obj0 = this->moves[i].buildJsonObj();
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
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->personID);
		cyborgbear::objSet(obj, "PersonID", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->world);
		cyborgbear::objSet(obj, "World", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->zone);
		cyborgbear::objSet(obj, "Zone", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->xAddress);
		cyborgbear::objSet(obj, "XAddress", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->yAddress);
		cyborgbear::objSet(obj, "YAddress", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->layer);
		cyborgbear::objSet(obj, "Layer", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut ZoneInstance::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->accessorID);
		cyborgbear::objSet(obj, "AccessorID", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->path);
		cyborgbear::objSet(obj, "Path", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->location.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Location", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Image::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->path);
		cyborgbear::objSet(obj, "Path", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->defaultSize.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "DefaultSize", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut ZoneHeader::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->path);
		cyborgbear::objSet(obj, "Path", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->size.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Size", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Animation::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->interval);
		cyborgbear::objSet(obj, "Interval", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->images.size(); i++) {
			cyborgbear::JsonValOut obj0 = this->images[i].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Images", out1);
		cyborgbear::decref(out1);
	}
	return obj;
}

cyborgbear::JsonValOut AnimLayer::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut obj0 = this->point.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Point", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->animation.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Animation", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut SaveFile::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< string, cyborgbear::unknown >::iterator n = this->vars.begin(); n != this->vars.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgbear::toStdString(cyborgbear::toString(n->first));
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut obj0 = this->vars[n->first].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Vars", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut obj0 = this->user.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "User", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut CreatureClass::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< string, string >::iterator n = this->name.begin(); n != this->name.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgbear::toStdString(cyborgbear::toString(n->first));
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->name[n->first]);
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Name", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->successor);
		cyborgbear::objSet(obj, "Successor", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->predecessor);
		cyborgbear::objSet(obj, "Predecessor", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->types.size(); i++) {
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->types[i]);
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Types", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->canLearn.size(); i++) {
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->canLearn[i]);
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "CanLearn", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< int, string >::iterator n = this->learnsAtLevel.begin(); n != this->learnsAtLevel.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << n->first;
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->learnsAtLevel[n->first]);
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "LearnsAtLevel", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut obj0 = this->frontView.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "FrontView", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->backView.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "BackView", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut TileClass::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->terrainFlags);
		cyborgbear::objSet(obj, "TerrainFlags", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->import);
		cyborgbear::objSet(obj, "Import", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->lowerAnims.size(); i++) {
			cyborgbear::JsonValOut obj0 = this->lowerAnims[i].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "LowerAnims", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->upperAnims.size(); i++) {
			cyborgbear::JsonValOut obj0 = this->upperAnims[i].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "UpperAnims", out1);
		cyborgbear::decref(out1);
	}
	return obj;
}

cyborgbear::JsonValOut Sprite::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonArrayOut out2 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->animLayers.size(); i++) {
			cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
			for (cyborgbear::VectorIterator ii = 0; ii < this->animLayers[i].size(); ii++) {
				cyborgbear::JsonValOut obj0 = this->animLayers[i][ii].buildJsonObj();
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
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->spriteType);
		cyborgbear::objSet(obj, "SpriteType", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->personID);
		cyborgbear::objSet(obj, "PersonID", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->speed);
		cyborgbear::objSet(obj, "Speed", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->name);
		cyborgbear::objSet(obj, "Name", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->path);
		cyborgbear::objSet(obj, "Path", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->scriptPath);
		cyborgbear::objSet(obj, "ScriptPath", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut PersonClass::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->iD);
		cyborgbear::objSet(obj, "ID", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< string, string >::iterator n = this->name.begin(); n != this->name.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgbear::toStdString(cyborgbear::toString(n->first));
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->name[n->first]);
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Name", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->creatures.size(); i++) {
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->creatures[i]);
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Creatures", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->overhead.size(); i++) {
			cyborgbear::JsonValOut obj0 = this->overhead[i].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Overhead", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut obj0 = this->frontView.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "FrontView", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->backView.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "BackView", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Person::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut obj0 = this->personClass.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "PersonClass", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Tile::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut obj0 = this->tileClass.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "TileClass", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->occupant.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Occupant", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut World::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->zones.size(); i++) {
			cyborgbear::JsonValOut obj0 = this->zones[i].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Zones", out1);
		cyborgbear::decref(out1);
	}
	return obj;
}

cyborgbear::JsonValOut Zone::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonArrayOut out3 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->tiles.size(); i++) {
			cyborgbear::JsonArrayOut out2 = cyborgbear::newJsonArray();
			for (cyborgbear::VectorIterator ii = 0; ii < this->tiles[i].size(); ii++) {
				cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
				for (cyborgbear::VectorIterator iii = 0; iii < this->tiles[i][ii].size(); iii++) {
					cyborgbear::JsonValOut obj0 = this->tiles[i][ii][iii].buildJsonObj();
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
		for (cyborgbear::VectorIterator i = 0; i < this->initScripts.size(); i++) {
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->initScripts[i]);
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "InitScripts", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut obj0 = this->location.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Location", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}
