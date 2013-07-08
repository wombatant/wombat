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

PersonClass::PersonClass() {
	this->iD = 0;
}

Person::Person() {
}

World::World() {
}

Sprite::Sprite() {
	this->spriteType = 0;
	this->personID = 0;
	this->speed = 0;
	this->name = "";
	this->path = "";
	this->scriptPath = "";
}

Tile::Tile() {
}

Zone::Zone() {
}

bool CreatureType::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "Name");
		if (obj0 != NULL && json_typeof(obj0) == JSON_OBJECT) {
			const char *key;
			json_t *obj1;
			json_object_foreach(obj0, key, obj1) {
				string i;
				{
					std::stringstream s;
					s << key;
					s >> i;
				}
				string val;
				this->name.insert(make_pair(i, val));
				{
					if (json_is_string(obj1)) {
						this->name[i] = json_string_value(obj1);
					}
				}
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Special");
		{
			if (json_is_boolean(obj0)) {
				this->special = json_is_true(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "StrongAgainst");
		if (obj0 != NULL && json_typeof(obj0) == JSON_ARRAY) {
			unsigned int size = json_array_size(obj0);
			this->strongAgainst.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				json_t *obj1 = json_array_get(obj0, i);
				{
					if (json_is_string(obj1)) {
						this->strongAgainst[i] = json_string_value(obj1);
					}
				}
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "WeakAgainst");
		if (obj0 != NULL && json_typeof(obj0) == JSON_ARRAY) {
			unsigned int size = json_array_size(obj0);
			this->weakAgainst.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				json_t *obj1 = json_array_get(obj0, i);
				{
					if (json_is_string(obj1)) {
						this->weakAgainst[i] = json_string_value(obj1);
					}
				}
			}
		}
	}
	return true;
}

bool StatusEffect::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "AttackerEffect");
		{
			if (json_is_integer(obj0)) {
				this->attackerEffect = (int) json_integer_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "EnemyEffect");
		{
			if (json_is_integer(obj0)) {
				this->enemyEffect = (int) json_integer_value(obj0);
			}
		}
	}
	return true;
}

bool Fraction::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "Current");
		{
			if (json_is_integer(obj0)) {
				this->current = (int) json_integer_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Available");
		{
			if (json_is_integer(obj0)) {
				this->available = (int) json_integer_value(obj0);
			}
		}
	}
	return true;
}

bool ModelFile::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "Type");
		{
			if (json_is_string(obj0)) {
				this->type = json_string_value(obj0);
			}
		}
	}
	return true;
}

bool Point::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "X");
		{
			if (json_is_integer(obj0)) {
				this->x = (int) json_integer_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Y");
		{
			if (json_is_integer(obj0)) {
				this->y = (int) json_integer_value(obj0);
			}
		}
	}
	return true;
}

bool Size::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "Width");
		{
			if (json_is_integer(obj0)) {
				this->width = (int) json_integer_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Height");
		{
			if (json_is_integer(obj0)) {
				this->height = (int) json_integer_value(obj0);
			}
		}
	}
	return true;
}

bool CreatureMove::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "Name");
		if (obj0 != NULL && json_typeof(obj0) == JSON_OBJECT) {
			const char *key;
			json_t *obj1;
			json_object_foreach(obj0, key, obj1) {
				string i;
				{
					std::stringstream s;
					s << key;
					s >> i;
				}
				string val;
				this->name.insert(make_pair(i, val));
				{
					if (json_is_string(obj1)) {
						this->name[i] = json_string_value(obj1);
					}
				}
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Type");
		{
			if (json_is_string(obj0)) {
				this->type = json_string_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Power");
		{
			if (json_is_integer(obj0)) {
				this->power = (int) json_integer_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "RequiresRegarge");
		{
			if (json_is_boolean(obj0)) {
				this->requiresRegarge = json_is_true(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Script");
		{
			if (json_is_string(obj0)) {
				this->script = json_string_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Burn");
		{
			if (json_is_object(obj0)) {
				this->burn.load_json_t(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Freeze");
		{
			if (json_is_object(obj0)) {
				this->freeze.load_json_t(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Paralyze");
		{
			if (json_is_object(obj0)) {
				this->paralyze.load_json_t(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Poison");
		{
			if (json_is_object(obj0)) {
				this->poison.load_json_t(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Sleep");
		{
			if (json_is_object(obj0)) {
				this->sleep.load_json_t(obj0);
			}
		}
	}
	return true;
}

bool CreatureMoveInstance::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "CreatureMove");
		{
			if (json_is_integer(obj0)) {
				this->creatureMove = (int) json_integer_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "PP");
		{
			if (json_is_object(obj0)) {
				this->pP.load_json_t(obj0);
			}
		}
	}
	return true;
}

bool Creature::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "ID");
		{
			if (json_is_integer(obj0)) {
				this->iD = (int) json_integer_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Name");
		if (obj0 != NULL && json_typeof(obj0) == JSON_OBJECT) {
			const char *key;
			json_t *obj1;
			json_object_foreach(obj0, key, obj1) {
				string i;
				{
					std::stringstream s;
					s << key;
					s >> i;
				}
				string val;
				this->name.insert(make_pair(i, val));
				{
					if (json_is_string(obj1)) {
						this->name[i] = json_string_value(obj1);
					}
				}
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "CreatureClass");
		{
			if (json_is_string(obj0)) {
				this->creatureClass = json_string_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Male");
		{
			if (json_is_boolean(obj0)) {
				this->male = json_is_true(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Level");
		{
			if (json_is_integer(obj0)) {
				this->level = (int) json_integer_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Health");
		{
			if (json_is_object(obj0)) {
				this->health.load_json_t(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Attack");
		{
			if (json_is_integer(obj0)) {
				this->attack = (int) json_integer_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "SpecAttack");
		{
			if (json_is_integer(obj0)) {
				this->specAttack = (int) json_integer_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Defense");
		{
			if (json_is_integer(obj0)) {
				this->defense = (int) json_integer_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "SpecDefense");
		{
			if (json_is_integer(obj0)) {
				this->specDefense = (int) json_integer_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Burned");
		{
			if (json_is_boolean(obj0)) {
				this->burned = json_is_true(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Frozen");
		{
			if (json_is_boolean(obj0)) {
				this->frozen = json_is_true(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Poisoned");
		{
			if (json_is_boolean(obj0)) {
				this->poisoned = json_is_true(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Asleep");
		{
			if (json_is_boolean(obj0)) {
				this->asleep = json_is_true(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Moves");
		if (obj0 != NULL && json_typeof(obj0) == JSON_ARRAY) {
			unsigned int size = json_array_size(obj0);
			this->moves.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				json_t *obj1 = json_array_get(obj0, i);
				{
					if (json_is_object(obj1)) {
						this->moves[i].load_json_t(obj1);
					}
				}
			}
		}
	}
	return true;
}

bool User::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "PersonID");
		{
			if (json_is_integer(obj0)) {
				this->personID = (int) json_integer_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "World");
		{
			if (json_is_string(obj0)) {
				this->world = json_string_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Zone");
		{
			if (json_is_string(obj0)) {
				this->zone = json_string_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "XAddress");
		{
			if (json_is_integer(obj0)) {
				this->xAddress = (int) json_integer_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "YAddress");
		{
			if (json_is_integer(obj0)) {
				this->yAddress = (int) json_integer_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Layer");
		{
			if (json_is_integer(obj0)) {
				this->layer = (int) json_integer_value(obj0);
			}
		}
	}
	return true;
}

bool ZoneInstance::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "AccessorID");
		{
			if (json_is_string(obj0)) {
				this->accessorID = json_string_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Path");
		{
			if (json_is_string(obj0)) {
				this->path = json_string_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Location");
		{
			if (json_is_object(obj0)) {
				this->location.load_json_t(obj0);
			}
		}
	}
	return true;
}

bool Image::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "Path");
		{
			if (json_is_string(obj0)) {
				this->path = json_string_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "DefaultSize");
		{
			if (json_is_object(obj0)) {
				this->defaultSize.load_json_t(obj0);
			}
		}
	}
	return true;
}

bool ZoneHeader::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "Path");
		{
			if (json_is_string(obj0)) {
				this->path = json_string_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Size");
		{
			if (json_is_object(obj0)) {
				this->size.load_json_t(obj0);
			}
		}
	}
	return true;
}

bool Animation::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "Interval");
		{
			if (json_is_integer(obj0)) {
				this->interval = (int) json_integer_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Images");
		if (obj0 != NULL && json_typeof(obj0) == JSON_ARRAY) {
			unsigned int size = json_array_size(obj0);
			this->images.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				json_t *obj1 = json_array_get(obj0, i);
				{
					if (json_is_object(obj1)) {
						this->images[i].load_json_t(obj1);
					}
				}
			}
		}
	}
	return true;
}

bool AnimLayer::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "Point");
		{
			if (json_is_object(obj0)) {
				this->point.load_json_t(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Animation");
		{
			if (json_is_object(obj0)) {
				this->animation.load_json_t(obj0);
			}
		}
	}
	return true;
}

bool SaveFile::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "Vars");
		if (obj0 != NULL && json_typeof(obj0) == JSON_OBJECT) {
			const char *key;
			json_t *obj1;
			json_object_foreach(obj0, key, obj1) {
				string i;
				{
					std::stringstream s;
					s << key;
					s >> i;
				}
				modelmaker::unknown val;
				this->vars.insert(make_pair(i, val));
				{
					this->vars[i].load_json_t(obj1);
				}
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "User");
		{
			if (json_is_object(obj0)) {
				this->user.load_json_t(obj0);
			}
		}
	}
	return true;
}

bool CreatureClass::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "Name");
		if (obj0 != NULL && json_typeof(obj0) == JSON_OBJECT) {
			const char *key;
			json_t *obj1;
			json_object_foreach(obj0, key, obj1) {
				string i;
				{
					std::stringstream s;
					s << key;
					s >> i;
				}
				string val;
				this->name.insert(make_pair(i, val));
				{
					if (json_is_string(obj1)) {
						this->name[i] = json_string_value(obj1);
					}
				}
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Successor");
		{
			if (json_is_string(obj0)) {
				this->successor = json_string_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Predecessor");
		{
			if (json_is_string(obj0)) {
				this->predecessor = json_string_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Types");
		if (obj0 != NULL && json_typeof(obj0) == JSON_ARRAY) {
			unsigned int size = json_array_size(obj0);
			this->types.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				json_t *obj1 = json_array_get(obj0, i);
				{
					if (json_is_string(obj1)) {
						this->types[i] = json_string_value(obj1);
					}
				}
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "CanLearn");
		if (obj0 != NULL && json_typeof(obj0) == JSON_ARRAY) {
			unsigned int size = json_array_size(obj0);
			this->canLearn.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				json_t *obj1 = json_array_get(obj0, i);
				{
					if (json_is_string(obj1)) {
						this->canLearn[i] = json_string_value(obj1);
					}
				}
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "LearnsAtLevel");
		if (obj0 != NULL && json_typeof(obj0) == JSON_OBJECT) {
			const char *key;
			json_t *obj1;
			json_object_foreach(obj0, key, obj1) {
				int i;
				{
					std::stringstream s;
					s << key;
					s >> i;
				}
				string val;
				this->learnsAtLevel.insert(make_pair(i, val));
				{
					if (json_is_string(obj1)) {
						this->learnsAtLevel[i] = json_string_value(obj1);
					}
				}
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "FrontView");
		{
			if (json_is_object(obj0)) {
				this->frontView.load_json_t(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "BackView");
		{
			if (json_is_object(obj0)) {
				this->backView.load_json_t(obj0);
			}
		}
	}
	return true;
}

bool TileClass::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "TerrainFlags");
		{
			if (json_is_integer(obj0)) {
				this->terrainFlags = (int) json_integer_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Import");
		{
			if (json_is_string(obj0)) {
				this->import = json_string_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "LowerAnims");
		if (obj0 != NULL && json_typeof(obj0) == JSON_ARRAY) {
			unsigned int size = json_array_size(obj0);
			this->lowerAnims.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				json_t *obj1 = json_array_get(obj0, i);
				{
					if (json_is_object(obj1)) {
						this->lowerAnims[i].load_json_t(obj1);
					}
				}
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "UpperAnims");
		if (obj0 != NULL && json_typeof(obj0) == JSON_ARRAY) {
			unsigned int size = json_array_size(obj0);
			this->upperAnims.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				json_t *obj1 = json_array_get(obj0, i);
				{
					if (json_is_object(obj1)) {
						this->upperAnims[i].load_json_t(obj1);
					}
				}
			}
		}
	}
	return true;
}

bool PersonClass::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "ID");
		{
			if (json_is_integer(obj0)) {
				this->iD = (int) json_integer_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Name");
		if (obj0 != NULL && json_typeof(obj0) == JSON_OBJECT) {
			const char *key;
			json_t *obj1;
			json_object_foreach(obj0, key, obj1) {
				string i;
				{
					std::stringstream s;
					s << key;
					s >> i;
				}
				string val;
				this->name.insert(make_pair(i, val));
				{
					if (json_is_string(obj1)) {
						this->name[i] = json_string_value(obj1);
					}
				}
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Creatures");
		if (obj0 != NULL && json_typeof(obj0) == JSON_ARRAY) {
			unsigned int size = json_array_size(obj0);
			this->creatures.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				json_t *obj1 = json_array_get(obj0, i);
				{
					if (json_is_integer(obj1)) {
						this->creatures[i] = (int) json_integer_value(obj1);
					}
				}
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Overhead");
		if (obj0 != NULL && json_typeof(obj0) == JSON_ARRAY) {
			unsigned int size = json_array_size(obj0);
			this->overhead.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				json_t *obj1 = json_array_get(obj0, i);
				{
					if (json_is_object(obj1)) {
						this->overhead[i].load_json_t(obj1);
					}
				}
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "FrontView");
		{
			if (json_is_object(obj0)) {
				this->frontView.load_json_t(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "BackView");
		{
			if (json_is_object(obj0)) {
				this->backView.load_json_t(obj0);
			}
		}
	}
	return true;
}

bool Person::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "PersonClass");
		{
			if (json_is_object(obj0)) {
				this->personClass.load_json_t(obj0);
			}
		}
	}
	return true;
}

bool World::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "Zones");
		if (obj0 != NULL && json_typeof(obj0) == JSON_ARRAY) {
			unsigned int size = json_array_size(obj0);
			this->zones.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				json_t *obj1 = json_array_get(obj0, i);
				{
					if (json_is_object(obj1)) {
						this->zones[i].load_json_t(obj1);
					}
				}
			}
		}
	}
	return true;
}

bool Sprite::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "AnimLayers");
		if (obj0 != NULL && json_typeof(obj0) == JSON_ARRAY) {
			unsigned int size = json_array_size(obj0);
			this->animLayers.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				json_t *obj1 = json_array_get(obj0, i);
				if (obj1 != NULL && json_typeof(obj1) == JSON_ARRAY) {
					unsigned int size = json_array_size(obj1);
					this->animLayers[i].resize(size);
					for (unsigned int ii = 0; ii < size; ii++) {
						json_t *obj2 = json_array_get(obj1, ii);
						{
							if (json_is_object(obj2)) {
								this->animLayers[i][ii].load_json_t(obj2);
							}
						}
					}
				}
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "SpriteType");
		{
			if (json_is_integer(obj0)) {
				this->spriteType = (int) json_integer_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "PersonID");
		{
			if (json_is_integer(obj0)) {
				this->personID = (int) json_integer_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Speed");
		{
			if (json_is_integer(obj0)) {
				this->speed = (int) json_integer_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Name");
		{
			if (json_is_string(obj0)) {
				this->name = json_string_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Path");
		{
			if (json_is_string(obj0)) {
				this->path = json_string_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "ScriptPath");
		{
			if (json_is_string(obj0)) {
				this->scriptPath = json_string_value(obj0);
			}
		}
	}
	return true;
}

bool Tile::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "TileClass");
		{
			if (json_is_object(obj0)) {
				this->tileClass.load_json_t(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Occupant");
		{
			if (json_is_object(obj0)) {
				this->occupant.load_json_t(obj0);
			}
		}
	}
	return true;
}

bool Zone::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "Tiles");
		if (obj0 != NULL && json_typeof(obj0) == JSON_ARRAY) {
			unsigned int size = json_array_size(obj0);
			this->tiles.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				json_t *obj1 = json_array_get(obj0, i);
				if (obj1 != NULL && json_typeof(obj1) == JSON_ARRAY) {
					unsigned int size = json_array_size(obj1);
					this->tiles[i].resize(size);
					for (unsigned int ii = 0; ii < size; ii++) {
						json_t *obj2 = json_array_get(obj1, ii);
						if (obj2 != NULL && json_typeof(obj2) == JSON_ARRAY) {
							unsigned int size = json_array_size(obj2);
							this->tiles[i][ii].resize(size);
							for (unsigned int iii = 0; iii < size; iii++) {
								json_t *obj3 = json_array_get(obj2, iii);
								{
									if (json_is_object(obj3)) {
										this->tiles[i][ii][iii].load_json_t(obj3);
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
		json_t *obj0 = json_object_get(in, "InitScripts");
		if (obj0 != NULL && json_typeof(obj0) == JSON_ARRAY) {
			unsigned int size = json_array_size(obj0);
			this->initScripts.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				json_t *obj1 = json_array_get(obj0, i);
				{
					if (json_is_string(obj1)) {
						this->initScripts[i] = json_string_value(obj1);
					}
				}
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Location");
		{
			if (json_is_object(obj0)) {
				this->location.load_json_t(obj0);
			}
		}
	}
	return true;
}

json_t* CreatureType::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out1 = json_object();
		for (map< string, string >::iterator n = this->name.begin(); n != this->name.end(); ++n) {
			std::stringstream s;
			string key;
			s << n->first;
			s >> key;
			json_t *out0 = json_string(this->name[n->first].c_str());
			json_object_set(out1, key.c_str(), out0);
			json_decref(out0);
		}
		json_object_set(obj, "Name", out1);
		json_decref(out1);
	}
	{
		json_t *out0 = json_boolean(this->special);
		json_object_set(obj, "Special", out0);
		json_decref(out0);
	}
	{
		json_t *out1 = json_array();
		for (unsigned int i = 0; i < this->strongAgainst.size(); i++) {
			json_t *out0 = json_string(this->strongAgainst[i].c_str());
			json_array_append(out1, out0);
			json_decref(out0);
		}
		json_object_set(obj, "StrongAgainst", out1);
		json_decref(out1);
	}
	{
		json_t *out1 = json_array();
		for (unsigned int i = 0; i < this->weakAgainst.size(); i++) {
			json_t *out0 = json_string(this->weakAgainst[i].c_str());
			json_array_append(out1, out0);
			json_decref(out0);
		}
		json_object_set(obj, "WeakAgainst", out1);
		json_decref(out1);
	}
	return obj;
}

json_t* StatusEffect::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out0 = json_integer(this->attackerEffect);
		json_object_set(obj, "AttackerEffect", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_integer(this->enemyEffect);
		json_object_set(obj, "EnemyEffect", out0);
		json_decref(out0);
	}
	return obj;
}

json_t* Fraction::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out0 = json_integer(this->current);
		json_object_set(obj, "Current", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_integer(this->available);
		json_object_set(obj, "Available", out0);
		json_decref(out0);
	}
	return obj;
}

json_t* ModelFile::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out0 = json_string(this->type.c_str());
		json_object_set(obj, "Type", out0);
		json_decref(out0);
	}
	return obj;
}

json_t* Point::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out0 = json_integer(this->x);
		json_object_set(obj, "X", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_integer(this->y);
		json_object_set(obj, "Y", out0);
		json_decref(out0);
	}
	return obj;
}

json_t* Size::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out0 = json_integer(this->width);
		json_object_set(obj, "Width", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_integer(this->height);
		json_object_set(obj, "Height", out0);
		json_decref(out0);
	}
	return obj;
}

json_t* CreatureMove::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out1 = json_object();
		for (map< string, string >::iterator n = this->name.begin(); n != this->name.end(); ++n) {
			std::stringstream s;
			string key;
			s << n->first;
			s >> key;
			json_t *out0 = json_string(this->name[n->first].c_str());
			json_object_set(out1, key.c_str(), out0);
			json_decref(out0);
		}
		json_object_set(obj, "Name", out1);
		json_decref(out1);
	}
	{
		json_t *out0 = json_string(this->type.c_str());
		json_object_set(obj, "Type", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_integer(this->power);
		json_object_set(obj, "Power", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_boolean(this->requiresRegarge);
		json_object_set(obj, "RequiresRegarge", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_string(this->script.c_str());
		json_object_set(obj, "Script", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = this->burn.buildJsonObj();
		json_object_set(obj, "Burn", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = this->freeze.buildJsonObj();
		json_object_set(obj, "Freeze", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = this->paralyze.buildJsonObj();
		json_object_set(obj, "Paralyze", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = this->poison.buildJsonObj();
		json_object_set(obj, "Poison", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = this->sleep.buildJsonObj();
		json_object_set(obj, "Sleep", out0);
		json_decref(out0);
	}
	return obj;
}

json_t* CreatureMoveInstance::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out0 = json_integer(this->creatureMove);
		json_object_set(obj, "CreatureMove", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = this->pP.buildJsonObj();
		json_object_set(obj, "PP", out0);
		json_decref(out0);
	}
	return obj;
}

json_t* Creature::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out0 = json_integer(this->iD);
		json_object_set(obj, "ID", out0);
		json_decref(out0);
	}
	{
		json_t *out1 = json_object();
		for (map< string, string >::iterator n = this->name.begin(); n != this->name.end(); ++n) {
			std::stringstream s;
			string key;
			s << n->first;
			s >> key;
			json_t *out0 = json_string(this->name[n->first].c_str());
			json_object_set(out1, key.c_str(), out0);
			json_decref(out0);
		}
		json_object_set(obj, "Name", out1);
		json_decref(out1);
	}
	{
		json_t *out0 = json_string(this->creatureClass.c_str());
		json_object_set(obj, "CreatureClass", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_boolean(this->male);
		json_object_set(obj, "Male", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_integer(this->level);
		json_object_set(obj, "Level", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = this->health.buildJsonObj();
		json_object_set(obj, "Health", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_integer(this->attack);
		json_object_set(obj, "Attack", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_integer(this->specAttack);
		json_object_set(obj, "SpecAttack", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_integer(this->defense);
		json_object_set(obj, "Defense", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_integer(this->specDefense);
		json_object_set(obj, "SpecDefense", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_boolean(this->burned);
		json_object_set(obj, "Burned", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_boolean(this->frozen);
		json_object_set(obj, "Frozen", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_boolean(this->poisoned);
		json_object_set(obj, "Poisoned", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_boolean(this->asleep);
		json_object_set(obj, "Asleep", out0);
		json_decref(out0);
	}
	{
		json_t *out1 = json_array();
		for (unsigned int i = 0; i < this->moves.size(); i++) {
			json_t *out0 = this->moves[i].buildJsonObj();
			json_array_append(out1, out0);
			json_decref(out0);
		}
		json_object_set(obj, "Moves", out1);
		json_decref(out1);
	}
	return obj;
}

json_t* User::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out0 = json_integer(this->personID);
		json_object_set(obj, "PersonID", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_string(this->world.c_str());
		json_object_set(obj, "World", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_string(this->zone.c_str());
		json_object_set(obj, "Zone", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_integer(this->xAddress);
		json_object_set(obj, "XAddress", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_integer(this->yAddress);
		json_object_set(obj, "YAddress", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_integer(this->layer);
		json_object_set(obj, "Layer", out0);
		json_decref(out0);
	}
	return obj;
}

json_t* ZoneInstance::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out0 = json_string(this->accessorID.c_str());
		json_object_set(obj, "AccessorID", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_string(this->path.c_str());
		json_object_set(obj, "Path", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = this->location.buildJsonObj();
		json_object_set(obj, "Location", out0);
		json_decref(out0);
	}
	return obj;
}

json_t* Image::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out0 = json_string(this->path.c_str());
		json_object_set(obj, "Path", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = this->defaultSize.buildJsonObj();
		json_object_set(obj, "DefaultSize", out0);
		json_decref(out0);
	}
	return obj;
}

json_t* ZoneHeader::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out0 = json_string(this->path.c_str());
		json_object_set(obj, "Path", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = this->size.buildJsonObj();
		json_object_set(obj, "Size", out0);
		json_decref(out0);
	}
	return obj;
}

json_t* Animation::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out0 = json_integer(this->interval);
		json_object_set(obj, "Interval", out0);
		json_decref(out0);
	}
	{
		json_t *out1 = json_array();
		for (unsigned int i = 0; i < this->images.size(); i++) {
			json_t *out0 = this->images[i].buildJsonObj();
			json_array_append(out1, out0);
			json_decref(out0);
		}
		json_object_set(obj, "Images", out1);
		json_decref(out1);
	}
	return obj;
}

json_t* AnimLayer::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out0 = this->point.buildJsonObj();
		json_object_set(obj, "Point", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = this->animation.buildJsonObj();
		json_object_set(obj, "Animation", out0);
		json_decref(out0);
	}
	return obj;
}

json_t* SaveFile::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out1 = json_object();
		for (map< string, modelmaker::unknown >::iterator n = this->vars.begin(); n != this->vars.end(); ++n) {
			std::stringstream s;
			string key;
			s << n->first;
			s >> key;
			json_t *out0 = this->vars[n->first].buildJsonObj();
			json_object_set(out1, key.c_str(), out0);
			json_decref(out0);
		}
		json_object_set(obj, "Vars", out1);
		json_decref(out1);
	}
	{
		json_t *out0 = this->user.buildJsonObj();
		json_object_set(obj, "User", out0);
		json_decref(out0);
	}
	return obj;
}

json_t* CreatureClass::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out1 = json_object();
		for (map< string, string >::iterator n = this->name.begin(); n != this->name.end(); ++n) {
			std::stringstream s;
			string key;
			s << n->first;
			s >> key;
			json_t *out0 = json_string(this->name[n->first].c_str());
			json_object_set(out1, key.c_str(), out0);
			json_decref(out0);
		}
		json_object_set(obj, "Name", out1);
		json_decref(out1);
	}
	{
		json_t *out0 = json_string(this->successor.c_str());
		json_object_set(obj, "Successor", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_string(this->predecessor.c_str());
		json_object_set(obj, "Predecessor", out0);
		json_decref(out0);
	}
	{
		json_t *out1 = json_array();
		for (unsigned int i = 0; i < this->types.size(); i++) {
			json_t *out0 = json_string(this->types[i].c_str());
			json_array_append(out1, out0);
			json_decref(out0);
		}
		json_object_set(obj, "Types", out1);
		json_decref(out1);
	}
	{
		json_t *out1 = json_array();
		for (unsigned int i = 0; i < this->canLearn.size(); i++) {
			json_t *out0 = json_string(this->canLearn[i].c_str());
			json_array_append(out1, out0);
			json_decref(out0);
		}
		json_object_set(obj, "CanLearn", out1);
		json_decref(out1);
	}
	{
		json_t *out1 = json_object();
		for (map< int, string >::iterator n = this->learnsAtLevel.begin(); n != this->learnsAtLevel.end(); ++n) {
			std::stringstream s;
			string key;
			s << n->first;
			s >> key;
			json_t *out0 = json_string(this->learnsAtLevel[n->first].c_str());
			json_object_set(out1, key.c_str(), out0);
			json_decref(out0);
		}
		json_object_set(obj, "LearnsAtLevel", out1);
		json_decref(out1);
	}
	{
		json_t *out0 = this->frontView.buildJsonObj();
		json_object_set(obj, "FrontView", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = this->backView.buildJsonObj();
		json_object_set(obj, "BackView", out0);
		json_decref(out0);
	}
	return obj;
}

json_t* TileClass::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out0 = json_integer(this->terrainFlags);
		json_object_set(obj, "TerrainFlags", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_string(this->import.c_str());
		json_object_set(obj, "Import", out0);
		json_decref(out0);
	}
	{
		json_t *out1 = json_array();
		for (unsigned int i = 0; i < this->lowerAnims.size(); i++) {
			json_t *out0 = this->lowerAnims[i].buildJsonObj();
			json_array_append(out1, out0);
			json_decref(out0);
		}
		json_object_set(obj, "LowerAnims", out1);
		json_decref(out1);
	}
	{
		json_t *out1 = json_array();
		for (unsigned int i = 0; i < this->upperAnims.size(); i++) {
			json_t *out0 = this->upperAnims[i].buildJsonObj();
			json_array_append(out1, out0);
			json_decref(out0);
		}
		json_object_set(obj, "UpperAnims", out1);
		json_decref(out1);
	}
	return obj;
}

json_t* PersonClass::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out0 = json_integer(this->iD);
		json_object_set(obj, "ID", out0);
		json_decref(out0);
	}
	{
		json_t *out1 = json_object();
		for (map< string, string >::iterator n = this->name.begin(); n != this->name.end(); ++n) {
			std::stringstream s;
			string key;
			s << n->first;
			s >> key;
			json_t *out0 = json_string(this->name[n->first].c_str());
			json_object_set(out1, key.c_str(), out0);
			json_decref(out0);
		}
		json_object_set(obj, "Name", out1);
		json_decref(out1);
	}
	{
		json_t *out1 = json_array();
		for (unsigned int i = 0; i < this->creatures.size(); i++) {
			json_t *out0 = json_integer(this->creatures[i]);
			json_array_append(out1, out0);
			json_decref(out0);
		}
		json_object_set(obj, "Creatures", out1);
		json_decref(out1);
	}
	{
		json_t *out1 = json_array();
		for (unsigned int i = 0; i < this->overhead.size(); i++) {
			json_t *out0 = this->overhead[i].buildJsonObj();
			json_array_append(out1, out0);
			json_decref(out0);
		}
		json_object_set(obj, "Overhead", out1);
		json_decref(out1);
	}
	{
		json_t *out0 = this->frontView.buildJsonObj();
		json_object_set(obj, "FrontView", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = this->backView.buildJsonObj();
		json_object_set(obj, "BackView", out0);
		json_decref(out0);
	}
	return obj;
}

json_t* Person::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out0 = this->personClass.buildJsonObj();
		json_object_set(obj, "PersonClass", out0);
		json_decref(out0);
	}
	return obj;
}

json_t* World::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out1 = json_array();
		for (unsigned int i = 0; i < this->zones.size(); i++) {
			json_t *out0 = this->zones[i].buildJsonObj();
			json_array_append(out1, out0);
			json_decref(out0);
		}
		json_object_set(obj, "Zones", out1);
		json_decref(out1);
	}
	return obj;
}

json_t* Sprite::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out2 = json_array();
		for (unsigned int i = 0; i < this->animLayers.size(); i++) {
			json_t *out1 = json_array();
			for (unsigned int ii = 0; ii < this->animLayers[i].size(); ii++) {
				json_t *out0 = this->animLayers[i][ii].buildJsonObj();
				json_array_append(out1, out0);
				json_decref(out0);
			}
			json_array_append(out2, out1);
			json_decref(out1);
		}
		json_object_set(obj, "AnimLayers", out2);
		json_decref(out2);
	}
	{
		json_t *out0 = json_integer(this->spriteType);
		json_object_set(obj, "SpriteType", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_integer(this->personID);
		json_object_set(obj, "PersonID", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_integer(this->speed);
		json_object_set(obj, "Speed", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_string(this->name.c_str());
		json_object_set(obj, "Name", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_string(this->path.c_str());
		json_object_set(obj, "Path", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_string(this->scriptPath.c_str());
		json_object_set(obj, "ScriptPath", out0);
		json_decref(out0);
	}
	return obj;
}

json_t* Tile::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out0 = this->tileClass.buildJsonObj();
		json_object_set(obj, "TileClass", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = this->occupant.buildJsonObj();
		json_object_set(obj, "Occupant", out0);
		json_decref(out0);
	}
	return obj;
}

json_t* Zone::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out3 = json_array();
		for (unsigned int i = 0; i < this->tiles.size(); i++) {
			json_t *out2 = json_array();
			for (unsigned int ii = 0; ii < this->tiles[i].size(); ii++) {
				json_t *out1 = json_array();
				for (unsigned int iii = 0; iii < this->tiles[i][ii].size(); iii++) {
					json_t *out0 = this->tiles[i][ii][iii].buildJsonObj();
					json_array_append(out1, out0);
					json_decref(out0);
				}
				json_array_append(out2, out1);
				json_decref(out1);
			}
			json_array_append(out3, out2);
			json_decref(out2);
		}
		json_object_set(obj, "Tiles", out3);
		json_decref(out3);
	}
	{
		json_t *out1 = json_array();
		for (unsigned int i = 0; i < this->initScripts.size(); i++) {
			json_t *out0 = json_string(this->initScripts[i].c_str());
			json_array_append(out1, out0);
			json_decref(out0);
		}
		json_object_set(obj, "InitScripts", out1);
		json_decref(out1);
	}
	{
		json_t *out0 = this->location.buildJsonObj();
		json_object_set(obj, "Location", out0);
		json_decref(out0);
	}
	return obj;
}
