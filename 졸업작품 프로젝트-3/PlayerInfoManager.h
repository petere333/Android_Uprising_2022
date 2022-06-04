#pragma once


#include "Item.h"

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
	EquipmentSlot slot;
	

public:
	void initGrowth();
	void initStats();

	float getAttackSpeed();
	float getDamageReduction();

	int getMeleeDamage();
	int getRangedDamage();
};