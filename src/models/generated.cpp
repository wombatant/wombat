/*
 * Copyright 2013-2015 gtalent2@gmail.com
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
//Generated Code
#include "generated.hpp"

namespace wombat {
namespace models {
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

Interaction::Interaction() {
	this->Type = 0;
}

Sprite::Sprite() {
	this->Id = "";
	this->SpriteClass = "";
	this->Motion = 0;
	this->Facing = 0;
	this->SpriteType = 0;
	this->Data = "";
}

CreatureAttributeMod::CreatureAttributeMod() {
	this->Name = "";
	this->ModHP = 0;
	this->ModBurn = 0;
	this->ModFreeze = 0;
	this->ModParalyze = 0;
	this->ModPoison = 0;
	this->ModSleep = 0;
	this->HealBurned = 0;
	this->HealFrozen = 0;
	this->HealPoisoned = 0;
	this->HealAsleep = 0;
}

Item::Item() {
	this->ItemType = 0;
}

ZoneHeader::ZoneHeader() {
	this->Zone = "";
	this->TilesWide = 0;
	this->TilesHigh = 0;
	this->Layers = 0;
}

ZoneInstance::ZoneInstance() {
	this->AccessorID = "";
	this->ZoneHeader = "";
}

AnimationSlide::AnimationSlide() {
	this->Interval = 0;
}

AnimLayer::AnimLayer() {
	this->Animation = "";
}

User::User() {
	this->Person = "";
}

Settings::Settings() {
	this->Fullscreen = 0;
	this->Width = 0;
	this->Height = 0;
}

InitFile::InitFile() {
	this->User = "";
	this->World = "";
	this->ZoneId = "";
	this->SpriteId = "";
}

Font::Font() {
	this->Size = 0;
	this->TtfPath = "";
}

StatusEffect::StatusEffect() {
	this->AttackerEffect = 0;
	this->EnemyEffect = 0;
}

Fraction::Fraction() {
	this->Current = 0;
	this->Available = 0;
}

SpriteClass::SpriteClass() {
	this->Attributes = "";
}

Animation::Animation() {
	this->Import = "";
}

CreatureMove::CreatureMove() {
	this->Type = "";
	this->Power = 0;
	this->RequiresRegarge = 0;
	this->Script = "";
	this->WorldAbilityFlags = 0;
}

CreatureType::CreatureType() {
	this->Special = 0;
}

World::World() {
}

TileClass::TileClass() {
	this->Import = "";
	this->TerrainType = 0;
}

CreatureMoveInstance::CreatureMoveInstance() {
	this->CreatureMove = "";
}

CreatureClass::CreatureClass() {
	this->Successor = "";
	this->Predecessor = "";
}

PersonClass::PersonClass() {
	this->Import = "";
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

Person::Person() {
}

Tile::Tile() {
}

Zone::Zone() {
}

bool Point::operator==(const Point &o) const {
	if (X != o.X) return false;
	if (Y != o.Y) return false;

	return true;
}

bool Size::operator==(const Size &o) const {
	if (Width != o.Width) return false;
	if (Height != o.Height) return false;

	return true;
}

bool Bounds::operator==(const Bounds &o) const {
	if (X != o.X) return false;
	if (Y != o.Y) return false;
	if (Width != o.Width) return false;
	if (Height != o.Height) return false;

	return true;
}

bool SaveVariables::operator==(const SaveVariables &o) const {
	if (Vars != o.Vars) return false;

	return true;
}

bool SpriteSheetImage::operator==(const SpriteSheetImage &o) const {
	if (SrcBounds != o.SrcBounds) return false;

	return true;
}

bool SpriteSheet::operator==(const SpriteSheet &o) const {
	if (TilesWide != o.TilesWide) return false;
	if (TilesHigh != o.TilesHigh) return false;
	if (TileWidth != o.TileWidth) return false;
	if (TileHeight != o.TileHeight) return false;
	if (SrcFile != o.SrcFile) return false;
	if (Images != o.Images) return false;
	if (ImageIdIterator != o.ImageIdIterator) return false;
	if (RecycledImageIds != o.RecycledImageIds) return false;

	return true;
}

bool Image::operator==(const Image &o) const {
	if (SpriteSheet != o.SpriteSheet) return false;
	if (ImgId != o.ImgId) return false;
	if (DefaultSize != o.DefaultSize) return false;

	return true;
}

bool Interaction::operator==(const Interaction &o) const {
	if (Type != o.Type) return false;
	if (Next != o.Next) return false;

	return true;
}

bool Sprite::operator==(const Sprite &o) const {
	if (Id != o.Id) return false;
	if (SpriteClass != o.SpriteClass) return false;
	if (Motion != o.Motion) return false;
	if (Facing != o.Facing) return false;
	if (SpriteType != o.SpriteType) return false;
	if (Interaction != o.Interaction) return false;
	if (Data != o.Data) return false;

	return true;
}

bool CreatureAttributeMod::operator==(const CreatureAttributeMod &o) const {
	if (Name != o.Name) return false;
	if (ModHP != o.ModHP) return false;
	if (ModBurn != o.ModBurn) return false;
	if (ModFreeze != o.ModFreeze) return false;
	if (ModParalyze != o.ModParalyze) return false;
	if (ModPoison != o.ModPoison) return false;
	if (ModSleep != o.ModSleep) return false;
	if (HealBurned != o.HealBurned) return false;
	if (HealFrozen != o.HealFrozen) return false;
	if (HealPoisoned != o.HealPoisoned) return false;
	if (HealAsleep != o.HealAsleep) return false;

	return true;
}

bool Item::operator==(const Item &o) const {
	if (ItemType != o.ItemType) return false;

	return true;
}

bool ZoneHeader::operator==(const ZoneHeader &o) const {
	if (Zone != o.Zone) return false;
	if (TilesWide != o.TilesWide) return false;
	if (TilesHigh != o.TilesHigh) return false;
	if (Layers != o.Layers) return false;

	return true;
}

bool ZoneInstance::operator==(const ZoneInstance &o) const {
	if (AccessorID != o.AccessorID) return false;
	if (ZoneHeader != o.ZoneHeader) return false;
	if (Address != o.Address) return false;

	return true;
}

bool AnimationSlide::operator==(const AnimationSlide &o) const {
	if (Interval != o.Interval) return false;
	if (Image != o.Image) return false;

	return true;
}

bool AnimLayer::operator==(const AnimLayer &o) const {
	if (Point != o.Point) return false;
	if (Animation != o.Animation) return false;

	return true;
}

bool User::operator==(const User &o) const {
	if (Person != o.Person) return false;

	return true;
}

bool Settings::operator==(const Settings &o) const {
	if (Fullscreen != o.Fullscreen) return false;
	if (Width != o.Width) return false;
	if (Height != o.Height) return false;

	return true;
}

bool InitFile::operator==(const InitFile &o) const {
	if (User != o.User) return false;
	if (World != o.World) return false;
	if (ZoneId != o.ZoneId) return false;
	if (SpriteId != o.SpriteId) return false;

	return true;
}

bool Font::operator==(const Font &o) const {
	if (Size != o.Size) return false;
	if (TtfPath != o.TtfPath) return false;

	return true;
}

bool StatusEffect::operator==(const StatusEffect &o) const {
	if (AttackerEffect != o.AttackerEffect) return false;
	if (EnemyEffect != o.EnemyEffect) return false;

	return true;
}

bool Fraction::operator==(const Fraction &o) const {
	if (Current != o.Current) return false;
	if (Available != o.Available) return false;

	return true;
}

bool SpriteClass::operator==(const SpriteClass &o) const {
	if (AnimLayers != o.AnimLayers) return false;
	if (Attributes != o.Attributes) return false;

	return true;
}

bool Animation::operator==(const Animation &o) const {
	if (Import != o.Import) return false;
	if (Images != o.Images) return false;

	return true;
}

bool CreatureMove::operator==(const CreatureMove &o) const {
	if (Name != o.Name) return false;
	if (Type != o.Type) return false;
	if (Power != o.Power) return false;
	if (RequiresRegarge != o.RequiresRegarge) return false;
	if (Script != o.Script) return false;
	if (Burn != o.Burn) return false;
	if (Freeze != o.Freeze) return false;
	if (Paralyze != o.Paralyze) return false;
	if (Poison != o.Poison) return false;
	if (Sleep != o.Sleep) return false;
	if (WorldAbilityFlags != o.WorldAbilityFlags) return false;

	return true;
}

bool CreatureType::operator==(const CreatureType &o) const {
	if (Name != o.Name) return false;
	if (Special != o.Special) return false;
	if (StrongAgainst != o.StrongAgainst) return false;
	if (WeakAgainst != o.WeakAgainst) return false;

	return true;
}

bool World::operator==(const World &o) const {
	if (Zones != o.Zones) return false;

	return true;
}

bool TileClass::operator==(const TileClass &o) const {
	if (Import != o.Import) return false;
	if (TerrainType != o.TerrainType) return false;
	if (LowerAnim != o.LowerAnim) return false;
	if (UpperAnim != o.UpperAnim) return false;

	return true;
}

bool CreatureMoveInstance::operator==(const CreatureMoveInstance &o) const {
	if (CreatureMove != o.CreatureMove) return false;
	if (PP != o.PP) return false;

	return true;
}

bool CreatureClass::operator==(const CreatureClass &o) const {
	if (Name != o.Name) return false;
	if (Successor != o.Successor) return false;
	if (Predecessor != o.Predecessor) return false;
	if (Types != o.Types) return false;
	if (CanLearn != o.CanLearn) return false;
	if (LearnsAtLevel != o.LearnsAtLevel) return false;
	if (FrontView != o.FrontView) return false;
	if (BackView != o.BackView) return false;

	return true;
}

bool PersonClass::operator==(const PersonClass &o) const {
	if (Import != o.Import) return false;
	if (Title != o.Title) return false;
	if (Overhead != o.Overhead) return false;
	if (FrontView != o.FrontView) return false;
	if (BackView != o.BackView) return false;

	return true;
}

bool Creature::operator==(const Creature &o) const {
	if (ID != o.ID) return false;
	if (Name != o.Name) return false;
	if (CreatureClass != o.CreatureClass) return false;
	if (Male != o.Male) return false;
	if (Level != o.Level) return false;
	if (Health != o.Health) return false;
	if (Attack != o.Attack) return false;
	if (SpecAttack != o.SpecAttack) return false;
	if (Defense != o.Defense) return false;
	if (SpecDefense != o.SpecDefense) return false;
	if (Burned != o.Burned) return false;
	if (Frozen != o.Frozen) return false;
	if (Poisoned != o.Poisoned) return false;
	if (Asleep != o.Asleep) return false;
	if (Moves != o.Moves) return false;

	return true;
}

bool Person::operator==(const Person &o) const {
	if (PersonClass != o.PersonClass) return false;
	if (Name != o.Name) return false;
	if (Creatures != o.Creatures) return false;

	return true;
}

bool Tile::operator==(const Tile &o) const {
	if (TileClass != o.TileClass) return false;
	if (Occupant != o.Occupant) return false;

	return true;
}

bool Zone::operator==(const Zone &o) const {
	if (Tiles != o.Tiles) return false;

	return true;
}

bool Point::operator!=(const Point &o) const {
	if (X != o.X) return true;
	if (Y != o.Y) return true;

	return false;
}

bool Size::operator!=(const Size &o) const {
	if (Width != o.Width) return true;
	if (Height != o.Height) return true;

	return false;
}

bool Bounds::operator!=(const Bounds &o) const {
	if (X != o.X) return true;
	if (Y != o.Y) return true;
	if (Width != o.Width) return true;
	if (Height != o.Height) return true;

	return false;
}

bool SaveVariables::operator!=(const SaveVariables &o) const {
	if (Vars != o.Vars) return true;

	return false;
}

bool SpriteSheetImage::operator!=(const SpriteSheetImage &o) const {
	if (SrcBounds != o.SrcBounds) return true;

	return false;
}

bool SpriteSheet::operator!=(const SpriteSheet &o) const {
	if (TilesWide != o.TilesWide) return true;
	if (TilesHigh != o.TilesHigh) return true;
	if (TileWidth != o.TileWidth) return true;
	if (TileHeight != o.TileHeight) return true;
	if (SrcFile != o.SrcFile) return true;
	if (Images != o.Images) return true;
	if (ImageIdIterator != o.ImageIdIterator) return true;
	if (RecycledImageIds != o.RecycledImageIds) return true;

	return false;
}

bool Image::operator!=(const Image &o) const {
	if (SpriteSheet != o.SpriteSheet) return true;
	if (ImgId != o.ImgId) return true;
	if (DefaultSize != o.DefaultSize) return true;

	return false;
}

bool Interaction::operator!=(const Interaction &o) const {
	if (Type != o.Type) return true;
	if (Next != o.Next) return true;

	return false;
}

bool Sprite::operator!=(const Sprite &o) const {
	if (Id != o.Id) return true;
	if (SpriteClass != o.SpriteClass) return true;
	if (Motion != o.Motion) return true;
	if (Facing != o.Facing) return true;
	if (SpriteType != o.SpriteType) return true;
	if (Interaction != o.Interaction) return true;
	if (Data != o.Data) return true;

	return false;
}

bool CreatureAttributeMod::operator!=(const CreatureAttributeMod &o) const {
	if (Name != o.Name) return true;
	if (ModHP != o.ModHP) return true;
	if (ModBurn != o.ModBurn) return true;
	if (ModFreeze != o.ModFreeze) return true;
	if (ModParalyze != o.ModParalyze) return true;
	if (ModPoison != o.ModPoison) return true;
	if (ModSleep != o.ModSleep) return true;
	if (HealBurned != o.HealBurned) return true;
	if (HealFrozen != o.HealFrozen) return true;
	if (HealPoisoned != o.HealPoisoned) return true;
	if (HealAsleep != o.HealAsleep) return true;

	return false;
}

bool Item::operator!=(const Item &o) const {
	if (ItemType != o.ItemType) return true;

	return false;
}

bool ZoneHeader::operator!=(const ZoneHeader &o) const {
	if (Zone != o.Zone) return true;
	if (TilesWide != o.TilesWide) return true;
	if (TilesHigh != o.TilesHigh) return true;
	if (Layers != o.Layers) return true;

	return false;
}

bool ZoneInstance::operator!=(const ZoneInstance &o) const {
	if (AccessorID != o.AccessorID) return true;
	if (ZoneHeader != o.ZoneHeader) return true;
	if (Address != o.Address) return true;

	return false;
}

bool AnimationSlide::operator!=(const AnimationSlide &o) const {
	if (Interval != o.Interval) return true;
	if (Image != o.Image) return true;

	return false;
}

bool AnimLayer::operator!=(const AnimLayer &o) const {
	if (Point != o.Point) return true;
	if (Animation != o.Animation) return true;

	return false;
}

bool User::operator!=(const User &o) const {
	if (Person != o.Person) return true;

	return false;
}

bool Settings::operator!=(const Settings &o) const {
	if (Fullscreen != o.Fullscreen) return true;
	if (Width != o.Width) return true;
	if (Height != o.Height) return true;

	return false;
}

bool InitFile::operator!=(const InitFile &o) const {
	if (User != o.User) return true;
	if (World != o.World) return true;
	if (ZoneId != o.ZoneId) return true;
	if (SpriteId != o.SpriteId) return true;

	return false;
}

bool Font::operator!=(const Font &o) const {
	if (Size != o.Size) return true;
	if (TtfPath != o.TtfPath) return true;

	return false;
}

bool StatusEffect::operator!=(const StatusEffect &o) const {
	if (AttackerEffect != o.AttackerEffect) return true;
	if (EnemyEffect != o.EnemyEffect) return true;

	return false;
}

bool Fraction::operator!=(const Fraction &o) const {
	if (Current != o.Current) return true;
	if (Available != o.Available) return true;

	return false;
}

bool SpriteClass::operator!=(const SpriteClass &o) const {
	if (AnimLayers != o.AnimLayers) return true;
	if (Attributes != o.Attributes) return true;

	return false;
}

bool Animation::operator!=(const Animation &o) const {
	if (Import != o.Import) return true;
	if (Images != o.Images) return true;

	return false;
}

bool CreatureMove::operator!=(const CreatureMove &o) const {
	if (Name != o.Name) return true;
	if (Type != o.Type) return true;
	if (Power != o.Power) return true;
	if (RequiresRegarge != o.RequiresRegarge) return true;
	if (Script != o.Script) return true;
	if (Burn != o.Burn) return true;
	if (Freeze != o.Freeze) return true;
	if (Paralyze != o.Paralyze) return true;
	if (Poison != o.Poison) return true;
	if (Sleep != o.Sleep) return true;
	if (WorldAbilityFlags != o.WorldAbilityFlags) return true;

	return false;
}

bool CreatureType::operator!=(const CreatureType &o) const {
	if (Name != o.Name) return true;
	if (Special != o.Special) return true;
	if (StrongAgainst != o.StrongAgainst) return true;
	if (WeakAgainst != o.WeakAgainst) return true;

	return false;
}

bool World::operator!=(const World &o) const {
	if (Zones != o.Zones) return true;

	return false;
}

bool TileClass::operator!=(const TileClass &o) const {
	if (Import != o.Import) return true;
	if (TerrainType != o.TerrainType) return true;
	if (LowerAnim != o.LowerAnim) return true;
	if (UpperAnim != o.UpperAnim) return true;

	return false;
}

bool CreatureMoveInstance::operator!=(const CreatureMoveInstance &o) const {
	if (CreatureMove != o.CreatureMove) return true;
	if (PP != o.PP) return true;

	return false;
}

bool CreatureClass::operator!=(const CreatureClass &o) const {
	if (Name != o.Name) return true;
	if (Successor != o.Successor) return true;
	if (Predecessor != o.Predecessor) return true;
	if (Types != o.Types) return true;
	if (CanLearn != o.CanLearn) return true;
	if (LearnsAtLevel != o.LearnsAtLevel) return true;
	if (FrontView != o.FrontView) return true;
	if (BackView != o.BackView) return true;

	return false;
}

bool PersonClass::operator!=(const PersonClass &o) const {
	if (Import != o.Import) return true;
	if (Title != o.Title) return true;
	if (Overhead != o.Overhead) return true;
	if (FrontView != o.FrontView) return true;
	if (BackView != o.BackView) return true;

	return false;
}

bool Creature::operator!=(const Creature &o) const {
	if (ID != o.ID) return true;
	if (Name != o.Name) return true;
	if (CreatureClass != o.CreatureClass) return true;
	if (Male != o.Male) return true;
	if (Level != o.Level) return true;
	if (Health != o.Health) return true;
	if (Attack != o.Attack) return true;
	if (SpecAttack != o.SpecAttack) return true;
	if (Defense != o.Defense) return true;
	if (SpecDefense != o.SpecDefense) return true;
	if (Burned != o.Burned) return true;
	if (Frozen != o.Frozen) return true;
	if (Poisoned != o.Poisoned) return true;
	if (Asleep != o.Asleep) return true;
	if (Moves != o.Moves) return true;

	return false;
}

bool Person::operator!=(const Person &o) const {
	if (PersonClass != o.PersonClass) return true;
	if (Name != o.Name) return true;
	if (Creatures != o.Creatures) return true;

	return false;
}

bool Tile::operator!=(const Tile &o) const {
	if (TileClass != o.TileClass) return true;
	if (Occupant != o.Occupant) return true;

	return false;
}

bool Zone::operator!=(const Zone &o) const {
	if (Tiles != o.Tiles) return true;

	return false;
}

}
}

