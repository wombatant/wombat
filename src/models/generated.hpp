/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
//Generated Code

#ifndef GENERATED_HPP
#define GENERATED_HPP

#include "ptr.hpp"
#include "unknown.hpp"
#include "json_read.hpp"
#include "json_write.hpp"



namespace wombat {
namespace models {

class Point: public Model {

	public:

		Point();

		bool operator==(const Point&) const;

		bool operator!=(const Point&) const;

		string toJson();

		Error fromJson(string);
		int X;
		int Y;
};


class Size: public Model {

	public:

		Size();

		bool operator==(const Size&) const;

		bool operator!=(const Size&) const;

		string toJson();

		Error fromJson(string);
		int Width;
		int Height;
};


class Bounds: public Model {

	public:

		Bounds();

		bool operator==(const Bounds&) const;

		bool operator!=(const Bounds&) const;

		string toJson();

		Error fromJson(string);
		int X;
		int Y;
		int Width;
		int Height;
};


class SaveVariables: public Model {

	public:

		SaveVariables();

		bool operator==(const SaveVariables&) const;

		bool operator!=(const SaveVariables&) const;

		string toJson();

		Error fromJson(string);
		std::map< string, unknown > Vars;
};


class SpriteSheetImage: public Model {

	public:

		SpriteSheetImage();

		bool operator==(const SpriteSheetImage&) const;

		bool operator!=(const SpriteSheetImage&) const;

		string toJson();

		Error fromJson(string);
		Bounds SrcBounds;
};


class SpriteSheet: public Model {

	public:

		SpriteSheet();

		bool operator==(const SpriteSheet&) const;

		bool operator!=(const SpriteSheet&) const;

		string toJson();

		Error fromJson(string);
		int TilesWide;
		int TilesHigh;
		int TileWidth;
		int TileHeight;
		string SrcFile;
		std::map< int, SpriteSheetImage > Images;
		int ImageIdIterator;
		std::vector< int > RecycledImageIds;
};


class Image: public Model {

	public:

		Image();

		bool operator==(const Image&) const;

		bool operator!=(const Image&) const;

		string toJson();

		Error fromJson(string);
		string SpriteSheet;
		int ImgId;
		Size DefaultSize;
};


class Interaction: public Model {

	public:

		Interaction();

		bool operator==(const Interaction&) const;

		bool operator!=(const Interaction&) const;

		string toJson();

		Error fromJson(string);
		int Type;
		unknown Next;
};


class Sprite: public Model {

	public:

		Sprite();

		bool operator==(const Sprite&) const;

		bool operator!=(const Sprite&) const;

		string toJson();

		Error fromJson(string);
		string Id;
		string SpriteClass;
		int Motion;
		int Facing;
		int SpriteType;
		Interaction Interaction;
		string Data;
};


class CreatureAttributeMod: public Model {

	public:

		CreatureAttributeMod();

		bool operator==(const CreatureAttributeMod&) const;

		bool operator!=(const CreatureAttributeMod&) const;

		string toJson();

		Error fromJson(string);
		string Name;
		int ModHP;
		int ModBurn;
		int ModFreeze;
		int ModParalyze;
		int ModPoison;
		int ModSleep;
		bool HealBurned;
		bool HealFrozen;
		bool HealPoisoned;
		bool HealAsleep;
};


class Item: public Model {

	public:

		Item();

		bool operator==(const Item&) const;

		bool operator!=(const Item&) const;

		string toJson();

		Error fromJson(string);
		int ItemType;
};


class ZoneHeader: public Model {

	public:

		ZoneHeader();

		bool operator==(const ZoneHeader&) const;

		bool operator!=(const ZoneHeader&) const;

		string toJson();

		Error fromJson(string);
		string Zone;
		int TilesWide;
		int TilesHigh;
		int Layers;
};


class ZoneInstance: public Model {

	public:

		ZoneInstance();

		bool operator==(const ZoneInstance&) const;

		bool operator!=(const ZoneInstance&) const;

		string toJson();

		Error fromJson(string);
		string AccessorID;
		string ZoneHeader;
		Point Address;
};


class AnimationSlide: public Model {

	public:

		AnimationSlide();

		bool operator==(const AnimationSlide&) const;

		bool operator!=(const AnimationSlide&) const;

		string toJson();

		Error fromJson(string);
		int Interval;
		Image Image;
};


class AnimLayer: public Model {

	public:

		AnimLayer();

		bool operator==(const AnimLayer&) const;

		bool operator!=(const AnimLayer&) const;

		string toJson();

		Error fromJson(string);
		Point Point;
		string Animation;
};


class User: public Model {

	public:

		User();

		bool operator==(const User&) const;

		bool operator!=(const User&) const;

		string toJson();

		Error fromJson(string);
		string Person;
};


class Settings: public Model {

	public:

		Settings();

		bool operator==(const Settings&) const;

		bool operator!=(const Settings&) const;

		string toJson();

		Error fromJson(string);
		bool Fullscreen;
		int Width;
		int Height;
};


class InitFile: public Model {

	public:

		InitFile();

		bool operator==(const InitFile&) const;

		bool operator!=(const InitFile&) const;

		string toJson();

		Error fromJson(string);
		string User;
		string World;
		string ZoneId;
		string SpriteId;
};


class Font: public Model {

	public:

		Font();

		bool operator==(const Font&) const;

		bool operator!=(const Font&) const;

		string toJson();

		Error fromJson(string);
		int Size;
		string TtfPath;
};


class StatusEffect: public Model {

	public:

		StatusEffect();

		bool operator==(const StatusEffect&) const;

		bool operator!=(const StatusEffect&) const;

		string toJson();

		Error fromJson(string);
		int AttackerEffect;
		int EnemyEffect;
};


class Fraction: public Model {

	public:

		Fraction();

		bool operator==(const Fraction&) const;

		bool operator!=(const Fraction&) const;

		string toJson();

		Error fromJson(string);
		int Current;
		int Available;
};


class SpriteClass: public Model {

	public:

		SpriteClass();

		bool operator==(const SpriteClass&) const;

		bool operator!=(const SpriteClass&) const;

		string toJson();

		Error fromJson(string);
		std::vector< std::vector< AnimLayer > > AnimLayers;
		string Attributes;
};


class Animation: public Model {

	public:

		Animation();

		bool operator==(const Animation&) const;

		bool operator!=(const Animation&) const;

		string toJson();

		Error fromJson(string);
		string Import;
		std::vector< AnimationSlide > Images;
};


class CreatureMove: public Model {

	public:

		CreatureMove();

		bool operator==(const CreatureMove&) const;

		bool operator!=(const CreatureMove&) const;

		string toJson();

		Error fromJson(string);
		std::map< string, string > Name;
		string Type;
		int Power;
		bool RequiresRegarge;
		string Script;
		StatusEffect Burn;
		StatusEffect Freeze;
		StatusEffect Paralyze;
		StatusEffect Poison;
		StatusEffect Sleep;
		int WorldAbilityFlags;
};


class CreatureType: public Model {

	public:

		CreatureType();

		bool operator==(const CreatureType&) const;

		bool operator!=(const CreatureType&) const;

		string toJson();

		Error fromJson(string);
		std::map< string, string > Name;
		bool Special;
		std::vector< string > StrongAgainst;
		std::vector< string > WeakAgainst;
};


class World: public Model {

	public:

		World();

		bool operator==(const World&) const;

		bool operator!=(const World&) const;

		string toJson();

		Error fromJson(string);
		std::vector< ZoneInstance > Zones;
};


class TileClass: public Model {

	public:

		TileClass();

		bool operator==(const TileClass&) const;

		bool operator!=(const TileClass&) const;

		string toJson();

		Error fromJson(string);
		string Import;
		int TerrainType;
		AnimLayer LowerAnim;
		AnimLayer UpperAnim;
};


class CreatureMoveInstance: public Model {

	public:

		CreatureMoveInstance();

		bool operator==(const CreatureMoveInstance&) const;

		bool operator!=(const CreatureMoveInstance&) const;

		string toJson();

		Error fromJson(string);
		string CreatureMove;
		Fraction PP;
};


class CreatureClass: public Model {

	public:

		CreatureClass();

		bool operator==(const CreatureClass&) const;

		bool operator!=(const CreatureClass&) const;

		string toJson();

		Error fromJson(string);
		std::map< string, string > Name;
		string Successor;
		string Predecessor;
		std::vector< string > Types;
		std::vector< string > CanLearn;
		std::map< int, string > LearnsAtLevel;
		Animation FrontView;
		Animation BackView;
};


class PersonClass: public Model {

	public:

		PersonClass();

		bool operator==(const PersonClass&) const;

		bool operator!=(const PersonClass&) const;

		string toJson();

		Error fromJson(string);
		string Import;
		std::map< string, string > Title;
		std::vector< std::vector< std::vector< AnimLayer > > > Overhead;
		Animation FrontView;
		Animation BackView;
};


class Creature: public Model {

	public:

		Creature();

		bool operator==(const Creature&) const;

		bool operator!=(const Creature&) const;

		string toJson();

		Error fromJson(string);
		int ID;
		std::map< string, string > Name;
		string CreatureClass;
		bool Male;
		int Level;
		Fraction Health;
		int Attack;
		int SpecAttack;
		int Defense;
		int SpecDefense;
		bool Burned;
		bool Frozen;
		bool Poisoned;
		bool Asleep;
		std::vector< CreatureMoveInstance > Moves;
};


class Person: public Model {

	public:

		Person();

		bool operator==(const Person&) const;

		bool operator!=(const Person&) const;

		string toJson();

		Error fromJson(string);
		PersonClass PersonClass;
		std::map< string, string > Name;
		std::vector< string > Creatures;
};


class Tile: public Model {

	public:

		Tile();

		bool operator==(const Tile&) const;

		bool operator!=(const Tile&) const;

		string toJson();

		Error fromJson(string);
		TileClass TileClass;
		Sprite Occupant;
};


class Zone: public Model {

	public:

		Zone();

		bool operator==(const Zone&) const;

		bool operator!=(const Zone&) const;

		string toJson();

		Error fromJson(string);
		std::vector< std::vector< std::vector< Tile > > > Tiles;
};

inline Error toJson(Point model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "X", model.X);
	err |= writeVal(jo, "Y", model.Y);
	return err;
}

inline Error toJson(Size model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "Width", model.Width);
	err |= writeVal(jo, "Height", model.Height);
	return err;
}

inline Error toJson(Bounds model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "X", model.X);
	err |= writeVal(jo, "Y", model.Y);
	err |= writeVal(jo, "Width", model.Width);
	err |= writeVal(jo, "Height", model.Height);
	return err;
}

inline Error toJson(SaveVariables model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "Vars", model.Vars);
	return err;
}

inline Error toJson(SpriteSheetImage model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "SrcBounds", model.SrcBounds);
	return err;
}

inline Error toJson(SpriteSheet model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "TilesWide", model.TilesWide);
	err |= writeVal(jo, "TilesHigh", model.TilesHigh);
	err |= writeVal(jo, "TileWidth", model.TileWidth);
	err |= writeVal(jo, "TileHeight", model.TileHeight);
	err |= writeVal(jo, "SrcFile", model.SrcFile);
	err |= writeVal(jo, "Images", model.Images);
	err |= writeVal(jo, "ImageIdIterator", model.ImageIdIterator);
	err |= writeVal(jo, "RecycledImageIds", model.RecycledImageIds);
	return err;
}

inline Error toJson(Image model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "SpriteSheet", model.SpriteSheet);
	err |= writeVal(jo, "ImgId", model.ImgId);
	err |= writeVal(jo, "DefaultSize", model.DefaultSize);
	return err;
}

inline Error toJson(Interaction model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "Type", model.Type);
	err |= writeVal(jo, "Next", model.Next);
	return err;
}

inline Error toJson(Sprite model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "Id", model.Id);
	err |= writeVal(jo, "SpriteClass", model.SpriteClass);
	err |= writeVal(jo, "Motion", model.Motion);
	err |= writeVal(jo, "Facing", model.Facing);
	err |= writeVal(jo, "SpriteType", model.SpriteType);
	err |= writeVal(jo, "Interaction", model.Interaction);
	err |= writeVal(jo, "Data", model.Data);
	return err;
}

inline Error toJson(CreatureAttributeMod model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "Name", model.Name);
	err |= writeVal(jo, "ModHP", model.ModHP);
	err |= writeVal(jo, "ModBurn", model.ModBurn);
	err |= writeVal(jo, "ModFreeze", model.ModFreeze);
	err |= writeVal(jo, "ModParalyze", model.ModParalyze);
	err |= writeVal(jo, "ModPoison", model.ModPoison);
	err |= writeVal(jo, "ModSleep", model.ModSleep);
	err |= writeVal(jo, "HealBurned", model.HealBurned);
	err |= writeVal(jo, "HealFrozen", model.HealFrozen);
	err |= writeVal(jo, "HealPoisoned", model.HealPoisoned);
	err |= writeVal(jo, "HealAsleep", model.HealAsleep);
	return err;
}

inline Error toJson(Item model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "ItemType", model.ItemType);
	return err;
}

inline Error toJson(ZoneHeader model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "Zone", model.Zone);
	err |= writeVal(jo, "TilesWide", model.TilesWide);
	err |= writeVal(jo, "TilesHigh", model.TilesHigh);
	err |= writeVal(jo, "Layers", model.Layers);
	return err;
}

inline Error toJson(ZoneInstance model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "AccessorID", model.AccessorID);
	err |= writeVal(jo, "ZoneHeader", model.ZoneHeader);
	err |= writeVal(jo, "Address", model.Address);
	return err;
}

inline Error toJson(AnimationSlide model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "Interval", model.Interval);
	err |= writeVal(jo, "Image", model.Image);
	return err;
}

inline Error toJson(AnimLayer model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "Point", model.Point);
	err |= writeVal(jo, "Animation", model.Animation);
	return err;
}

inline Error toJson(User model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "Person", model.Person);
	return err;
}

inline Error toJson(Settings model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "Fullscreen", model.Fullscreen);
	err |= writeVal(jo, "Width", model.Width);
	err |= writeVal(jo, "Height", model.Height);
	return err;
}

inline Error toJson(InitFile model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "User", model.User);
	err |= writeVal(jo, "World", model.World);
	err |= writeVal(jo, "ZoneId", model.ZoneId);
	err |= writeVal(jo, "SpriteId", model.SpriteId);
	return err;
}

inline Error toJson(Font model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "Size", model.Size);
	err |= writeVal(jo, "TtfPath", model.TtfPath);
	return err;
}

inline Error toJson(StatusEffect model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "AttackerEffect", model.AttackerEffect);
	err |= writeVal(jo, "EnemyEffect", model.EnemyEffect);
	return err;
}

inline Error toJson(Fraction model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "Current", model.Current);
	err |= writeVal(jo, "Available", model.Available);
	return err;
}

inline Error toJson(SpriteClass model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "AnimLayers", model.AnimLayers);
	err |= writeVal(jo, "Attributes", model.Attributes);
	return err;
}

inline Error toJson(Animation model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "Import", model.Import);
	err |= writeVal(jo, "Images", model.Images);
	return err;
}

inline Error toJson(CreatureMove model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "Name", model.Name);
	err |= writeVal(jo, "Type", model.Type);
	err |= writeVal(jo, "Power", model.Power);
	err |= writeVal(jo, "RequiresRegarge", model.RequiresRegarge);
	err |= writeVal(jo, "Script", model.Script);
	err |= writeVal(jo, "Burn", model.Burn);
	err |= writeVal(jo, "Freeze", model.Freeze);
	err |= writeVal(jo, "Paralyze", model.Paralyze);
	err |= writeVal(jo, "Poison", model.Poison);
	err |= writeVal(jo, "Sleep", model.Sleep);
	err |= writeVal(jo, "WorldAbilityFlags", model.WorldAbilityFlags);
	return err;
}

inline Error toJson(CreatureType model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "Name", model.Name);
	err |= writeVal(jo, "Special", model.Special);
	err |= writeVal(jo, "StrongAgainst", model.StrongAgainst);
	err |= writeVal(jo, "WeakAgainst", model.WeakAgainst);
	return err;
}

inline Error toJson(World model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "Zones", model.Zones);
	return err;
}

inline Error toJson(TileClass model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "Import", model.Import);
	err |= writeVal(jo, "TerrainType", model.TerrainType);
	err |= writeVal(jo, "LowerAnim", model.LowerAnim);
	err |= writeVal(jo, "UpperAnim", model.UpperAnim);
	return err;
}

inline Error toJson(CreatureMoveInstance model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "CreatureMove", model.CreatureMove);
	err |= writeVal(jo, "PP", model.PP);
	return err;
}

inline Error toJson(CreatureClass model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "Name", model.Name);
	err |= writeVal(jo, "Successor", model.Successor);
	err |= writeVal(jo, "Predecessor", model.Predecessor);
	err |= writeVal(jo, "Types", model.Types);
	err |= writeVal(jo, "CanLearn", model.CanLearn);
	err |= writeVal(jo, "LearnsAtLevel", model.LearnsAtLevel);
	err |= writeVal(jo, "FrontView", model.FrontView);
	err |= writeVal(jo, "BackView", model.BackView);
	return err;
}

inline Error toJson(PersonClass model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "Import", model.Import);
	err |= writeVal(jo, "Title", model.Title);
	err |= writeVal(jo, "Overhead", model.Overhead);
	err |= writeVal(jo, "FrontView", model.FrontView);
	err |= writeVal(jo, "BackView", model.BackView);
	return err;
}

inline Error toJson(Creature model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "ID", model.ID);
	err |= writeVal(jo, "Name", model.Name);
	err |= writeVal(jo, "CreatureClass", model.CreatureClass);
	err |= writeVal(jo, "Male", model.Male);
	err |= writeVal(jo, "Level", model.Level);
	err |= writeVal(jo, "Health", model.Health);
	err |= writeVal(jo, "Attack", model.Attack);
	err |= writeVal(jo, "SpecAttack", model.SpecAttack);
	err |= writeVal(jo, "Defense", model.Defense);
	err |= writeVal(jo, "SpecDefense", model.SpecDefense);
	err |= writeVal(jo, "Burned", model.Burned);
	err |= writeVal(jo, "Frozen", model.Frozen);
	err |= writeVal(jo, "Poisoned", model.Poisoned);
	err |= writeVal(jo, "Asleep", model.Asleep);
	err |= writeVal(jo, "Moves", model.Moves);
	return err;
}

inline Error toJson(Person model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "PersonClass", model.PersonClass);
	err |= writeVal(jo, "Name", model.Name);
	err |= writeVal(jo, "Creatures", model.Creatures);
	return err;
}

inline Error toJson(Tile model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "TileClass", model.TileClass);
	err |= writeVal(jo, "Occupant", model.Occupant);
	return err;
}

inline Error toJson(Zone model, json_t *jo) {
	Error err = Error::Ok;
	err |= writeVal(jo, "Tiles", model.Tiles);
	return err;
}

inline Error fromJson(Point *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "X", &model->X);
	err |= readVal(jo, "Y", &model->Y);
	return err;
}

inline Error fromJson(Size *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "Width", &model->Width);
	err |= readVal(jo, "Height", &model->Height);
	return err;
}

inline Error fromJson(Bounds *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "X", &model->X);
	err |= readVal(jo, "Y", &model->Y);
	err |= readVal(jo, "Width", &model->Width);
	err |= readVal(jo, "Height", &model->Height);
	return err;
}

inline Error fromJson(SaveVariables *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "Vars", &model->Vars);
	return err;
}

inline Error fromJson(SpriteSheetImage *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "SrcBounds", &model->SrcBounds);
	return err;
}

inline Error fromJson(SpriteSheet *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "TilesWide", &model->TilesWide);
	err |= readVal(jo, "TilesHigh", &model->TilesHigh);
	err |= readVal(jo, "TileWidth", &model->TileWidth);
	err |= readVal(jo, "TileHeight", &model->TileHeight);
	err |= readVal(jo, "SrcFile", &model->SrcFile);
	err |= readVal(jo, "Images", &model->Images);
	err |= readVal(jo, "ImageIdIterator", &model->ImageIdIterator);
	err |= readVal(jo, "RecycledImageIds", &model->RecycledImageIds);
	return err;
}

inline Error fromJson(Image *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "SpriteSheet", &model->SpriteSheet);
	err |= readVal(jo, "ImgId", &model->ImgId);
	err |= readVal(jo, "DefaultSize", &model->DefaultSize);
	return err;
}

inline Error fromJson(Interaction *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "Type", &model->Type);
	err |= readVal(jo, "Next", &model->Next);
	return err;
}

inline Error fromJson(Sprite *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "Id", &model->Id);
	err |= readVal(jo, "SpriteClass", &model->SpriteClass);
	err |= readVal(jo, "Motion", &model->Motion);
	err |= readVal(jo, "Facing", &model->Facing);
	err |= readVal(jo, "SpriteType", &model->SpriteType);
	err |= readVal(jo, "Interaction", &model->Interaction);
	err |= readVal(jo, "Data", &model->Data);
	return err;
}

inline Error fromJson(CreatureAttributeMod *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "Name", &model->Name);
	err |= readVal(jo, "ModHP", &model->ModHP);
	err |= readVal(jo, "ModBurn", &model->ModBurn);
	err |= readVal(jo, "ModFreeze", &model->ModFreeze);
	err |= readVal(jo, "ModParalyze", &model->ModParalyze);
	err |= readVal(jo, "ModPoison", &model->ModPoison);
	err |= readVal(jo, "ModSleep", &model->ModSleep);
	err |= readVal(jo, "HealBurned", &model->HealBurned);
	err |= readVal(jo, "HealFrozen", &model->HealFrozen);
	err |= readVal(jo, "HealPoisoned", &model->HealPoisoned);
	err |= readVal(jo, "HealAsleep", &model->HealAsleep);
	return err;
}

inline Error fromJson(Item *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "ItemType", &model->ItemType);
	return err;
}

inline Error fromJson(ZoneHeader *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "Zone", &model->Zone);
	err |= readVal(jo, "TilesWide", &model->TilesWide);
	err |= readVal(jo, "TilesHigh", &model->TilesHigh);
	err |= readVal(jo, "Layers", &model->Layers);
	return err;
}

inline Error fromJson(ZoneInstance *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "AccessorID", &model->AccessorID);
	err |= readVal(jo, "ZoneHeader", &model->ZoneHeader);
	err |= readVal(jo, "Address", &model->Address);
	return err;
}

inline Error fromJson(AnimationSlide *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "Interval", &model->Interval);
	err |= readVal(jo, "Image", &model->Image);
	return err;
}

inline Error fromJson(AnimLayer *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "Point", &model->Point);
	err |= readVal(jo, "Animation", &model->Animation);
	return err;
}

inline Error fromJson(User *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "Person", &model->Person);
	return err;
}

inline Error fromJson(Settings *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "Fullscreen", &model->Fullscreen);
	err |= readVal(jo, "Width", &model->Width);
	err |= readVal(jo, "Height", &model->Height);
	return err;
}

inline Error fromJson(InitFile *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "User", &model->User);
	err |= readVal(jo, "World", &model->World);
	err |= readVal(jo, "ZoneId", &model->ZoneId);
	err |= readVal(jo, "SpriteId", &model->SpriteId);
	return err;
}

inline Error fromJson(Font *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "Size", &model->Size);
	err |= readVal(jo, "TtfPath", &model->TtfPath);
	return err;
}

inline Error fromJson(StatusEffect *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "AttackerEffect", &model->AttackerEffect);
	err |= readVal(jo, "EnemyEffect", &model->EnemyEffect);
	return err;
}

inline Error fromJson(Fraction *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "Current", &model->Current);
	err |= readVal(jo, "Available", &model->Available);
	return err;
}

inline Error fromJson(SpriteClass *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "AnimLayers", &model->AnimLayers);
	err |= readVal(jo, "Attributes", &model->Attributes);
	return err;
}

inline Error fromJson(Animation *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "Import", &model->Import);
	err |= readVal(jo, "Images", &model->Images);
	return err;
}

inline Error fromJson(CreatureMove *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "Name", &model->Name);
	err |= readVal(jo, "Type", &model->Type);
	err |= readVal(jo, "Power", &model->Power);
	err |= readVal(jo, "RequiresRegarge", &model->RequiresRegarge);
	err |= readVal(jo, "Script", &model->Script);
	err |= readVal(jo, "Burn", &model->Burn);
	err |= readVal(jo, "Freeze", &model->Freeze);
	err |= readVal(jo, "Paralyze", &model->Paralyze);
	err |= readVal(jo, "Poison", &model->Poison);
	err |= readVal(jo, "Sleep", &model->Sleep);
	err |= readVal(jo, "WorldAbilityFlags", &model->WorldAbilityFlags);
	return err;
}

inline Error fromJson(CreatureType *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "Name", &model->Name);
	err |= readVal(jo, "Special", &model->Special);
	err |= readVal(jo, "StrongAgainst", &model->StrongAgainst);
	err |= readVal(jo, "WeakAgainst", &model->WeakAgainst);
	return err;
}

inline Error fromJson(World *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "Zones", &model->Zones);
	return err;
}

inline Error fromJson(TileClass *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "Import", &model->Import);
	err |= readVal(jo, "TerrainType", &model->TerrainType);
	err |= readVal(jo, "LowerAnim", &model->LowerAnim);
	err |= readVal(jo, "UpperAnim", &model->UpperAnim);
	return err;
}

inline Error fromJson(CreatureMoveInstance *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "CreatureMove", &model->CreatureMove);
	err |= readVal(jo, "PP", &model->PP);
	return err;
}

inline Error fromJson(CreatureClass *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "Name", &model->Name);
	err |= readVal(jo, "Successor", &model->Successor);
	err |= readVal(jo, "Predecessor", &model->Predecessor);
	err |= readVal(jo, "Types", &model->Types);
	err |= readVal(jo, "CanLearn", &model->CanLearn);
	err |= readVal(jo, "LearnsAtLevel", &model->LearnsAtLevel);
	err |= readVal(jo, "FrontView", &model->FrontView);
	err |= readVal(jo, "BackView", &model->BackView);
	return err;
}

inline Error fromJson(PersonClass *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "Import", &model->Import);
	err |= readVal(jo, "Title", &model->Title);
	err |= readVal(jo, "Overhead", &model->Overhead);
	err |= readVal(jo, "FrontView", &model->FrontView);
	err |= readVal(jo, "BackView", &model->BackView);
	return err;
}

inline Error fromJson(Creature *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "ID", &model->ID);
	err |= readVal(jo, "Name", &model->Name);
	err |= readVal(jo, "CreatureClass", &model->CreatureClass);
	err |= readVal(jo, "Male", &model->Male);
	err |= readVal(jo, "Level", &model->Level);
	err |= readVal(jo, "Health", &model->Health);
	err |= readVal(jo, "Attack", &model->Attack);
	err |= readVal(jo, "SpecAttack", &model->SpecAttack);
	err |= readVal(jo, "Defense", &model->Defense);
	err |= readVal(jo, "SpecDefense", &model->SpecDefense);
	err |= readVal(jo, "Burned", &model->Burned);
	err |= readVal(jo, "Frozen", &model->Frozen);
	err |= readVal(jo, "Poisoned", &model->Poisoned);
	err |= readVal(jo, "Asleep", &model->Asleep);
	err |= readVal(jo, "Moves", &model->Moves);
	return err;
}

inline Error fromJson(Person *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "PersonClass", &model->PersonClass);
	err |= readVal(jo, "Name", &model->Name);
	err |= readVal(jo, "Creatures", &model->Creatures);
	return err;
}

inline Error fromJson(Tile *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "TileClass", &model->TileClass);
	err |= readVal(jo, "Occupant", &model->Occupant);
	return err;
}

inline Error fromJson(Zone *model, json_t *jo) {
	Error err = Error::Ok;
	err |= readVal(jo, "Tiles", &model->Tiles);
	return err;
}

}
}


#endif