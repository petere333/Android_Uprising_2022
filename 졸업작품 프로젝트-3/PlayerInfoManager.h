#pragma once



#include "PlayerData.h"
#include "Item.h"
#include "ItemManager.h"


class Item;




struct EquipSlot
{
	EquipItem* meleeWeapon;
	EquipItem* rangedWeapon;
	EquipItem* armor;
};

class PlayerInfoManager
{
public:
	PlayerInfoManager();
	~PlayerInfoManager();

public:
	char name[13];
	Growth growth;
	Stats stats;
	Item inventory[18];
	EquipSlot slot;
	ItemManager* manager;
	int extraPoint;

public:
	void initGrowth();
	void initStats();

	float getAttackSpeed();
	float getDamageReduction();

	int getMeleeDamage();
	int getRangedDamage();
};