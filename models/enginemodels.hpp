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
#include <vector>
#include <map>
#include <jansson.h>
#include "modelmakerdefs.hpp"


using std::string;
using std::vector;
using std::map;

namespace models {

class CreatureType: public modelmaker::Model {

	public:

		CreatureType();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		map< string, string > name;
		bool special;
		vector< string > strongAgainst;
		vector< string > weakAgainst;
};

}


namespace models {

class StatusEffect: public modelmaker::Model {

	public:

		StatusEffect();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		int attackerEffect;
		int enemyEffect;
};

}


namespace models {

class Fraction: public modelmaker::Model {

	public:

		Fraction();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		int current;
		int available;
};

}


namespace models {

class ModelFile: public modelmaker::Model {

	public:

		ModelFile();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		string type;
};

}


namespace models {

class Point: public modelmaker::Model {

	public:

		Point();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		int x;
		int y;
};

}


namespace models {

class Size: public modelmaker::Model {

	public:

		Size();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		int width;
		int height;
};

}


namespace models {

class CreatureMove: public modelmaker::Model {

	public:

		CreatureMove();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		map< string, string > name;
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

class CreatureMoveInstance: public modelmaker::Model {

	public:

		CreatureMoveInstance();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		int creatureMove;
		Fraction pP;
};

}


namespace models {

class Creature: public modelmaker::Model {

	public:

		Creature();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		int iD;
		map< string, string > name;
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
		vector< CreatureMoveInstance > moves;
};

}


namespace models {

class User: public modelmaker::Model {

	public:

		User();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		int personID;
		string world;
		string zone;
		int xAddress;
		int yAddress;
		int layer;
};

}


namespace models {

class ZoneInstance: public modelmaker::Model {

	public:

		ZoneInstance();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		string accessorID;
		string path;
		Point location;
};

}


namespace models {

class Image: public modelmaker::Model {

	public:

		Image();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		string path;
		Size defaultSize;
};

}


namespace models {

class ZoneHeader: public modelmaker::Model {

	public:

		ZoneHeader();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		string path;
		Size size;
};

}


namespace models {

class Animation: public modelmaker::Model {

	public:

		Animation();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		int interval;
		vector< Image > images;
};

}


namespace models {

class AnimLayer: public modelmaker::Model {

	public:

		AnimLayer();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		Point point;
		Animation animation;
};

}


namespace models {

class SaveFile: public modelmaker::Model {

	public:

		SaveFile();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		map< string, modelmaker::unknown > vars;
		User user;
};

}


namespace models {

class CreatureClass: public modelmaker::Model {

	public:

		CreatureClass();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		map< string, string > name;
		string successor;
		string predecessor;
		vector< string > types;
		vector< string > canLearn;
		map< int, string > learnsAtLevel;
		Animation frontView;
		Animation backView;
};

}


namespace models {

class TileClass: public modelmaker::Model {

	public:

		TileClass();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		int terrainFlags;
		string import;
		vector< AnimLayer > lowerAnims;
		vector< AnimLayer > upperAnims;
};

}


namespace models {

class PersonClass: public modelmaker::Model {

	public:

		PersonClass();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		int iD;
		map< string, string > name;
		vector< int > creatures;
		vector< Animation > overhead;
		Animation frontView;
		Animation backView;
};

}


namespace models {

class Person: public modelmaker::Model {

	public:

		Person();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		PersonClass personClass;
};

}


namespace models {

class World: public modelmaker::Model {

	public:

		World();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		vector< ZoneInstance > zones;
};

}


namespace models {

class Sprite: public modelmaker::Model {

	public:

		Sprite();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		vector< vector< AnimLayer > > animLayers;
		int spriteType;
		int personID;
		int speed;
		string name;
		string path;
		string scriptPath;
};

}


namespace models {

class Tile: public modelmaker::Model {

	public:

		Tile();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		TileClass tileClass;
		Sprite occupant;
};

}


namespace models {

class Zone: public modelmaker::Model {

	public:

		Zone();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		vector< vector< vector< Tile > > > tiles;
		vector< string > initScripts;
		Point location;
};

}


#endif