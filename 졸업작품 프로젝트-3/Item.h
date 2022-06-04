#pragma once

#include "Object.h"
#include "PlayerData.h"

typedef struct EquipSlot
{
	EquipItem* weapon = NULL;
	EquipItem* armor = NULL;
}EquipmentSlot;

class Item
{
public:
	Item();
	~Item();
public:
	CMaterial* name;
	CMaterial* image;
	CMaterial* desc;

};
class EquipItem : Item
{
public:
	EquipItem();
	~EquipItem();

public:
	Stats stats;

};
class UsableItem :Item
{
public:
	UsableItem();
	~UsableItem();
public:
	Stats stats;
};