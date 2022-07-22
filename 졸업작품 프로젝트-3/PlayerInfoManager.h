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
	std::vector<EquipItem> inventory;
	EquipSlot slot;
	ItemManager* manager;
	int extraPoint;
	int gold;

	int co_melee=0;
	int co_ranged=0;
	int co_radio=0;

public:
	void initGrowth();
	void initStats();

	float getAttackSpeed();
	float getDamageReduction();

	int getMeleeDamage();
	int getRangedDamage();

	int getCapacity()
	{
		return slot.armor->stats.maxhp + slot.meleeWeapon->stats.maxhp + slot.rangedWeapon->stats.maxhp + stats.maxhp;
	}
	int getHardness()
	{
		return slot.armor->stats.hardness + slot.meleeWeapon->stats.hardness + slot.rangedWeapon->stats.hardness + stats.hardness;
	}
	int getPower()
	{
		return slot.armor->stats.power + slot.meleeWeapon->stats.power + slot.rangedWeapon->stats.power + stats.power;
	}
	int getPrecision()
	{
		return slot.armor->stats.precision + slot.meleeWeapon->stats.precision + slot.rangedWeapon->stats.precision + stats.precision;
	}
	int getEntrophy()
	{
		return slot.armor->stats.entrophy + slot.meleeWeapon->stats.entrophy + slot.rangedWeapon->stats.entrophy + stats.entrophy;
	}
};