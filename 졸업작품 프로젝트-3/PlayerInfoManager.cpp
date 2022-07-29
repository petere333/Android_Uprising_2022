#include "PlayerInfoManager.h"

PlayerInfoManager::PlayerInfoManager()
{
	manager = new ItemManager();
	initGrowth();
	initStats();
	gold = 0;
	extraPoint = 2;
	
	inventory.push_back(*manager->items[1]);
	inventory.push_back(*manager->items[3]);
}

PlayerInfoManager::~PlayerInfoManager()
{
}



void PlayerInfoManager::initGrowth()
{
	growth.melee.level = 1;
	growth.melee.exp = 0;

	growth.ranged.level = 1;
	growth.ranged.exp = 0;

	growth.radio.level = 1;
	growth.radio.exp = 0;

	growth.total.level = 1;
	growth.total.exp = 0;
}

void PlayerInfoManager::initStats()
{
	stats.maxhp = 50;
	stats.capacity = 50;
	stats.hardness = 4;
	stats.power = 4;
	stats.precision = 4;
	stats.entrophy = 4;
	stats.attack = 0;

	slot.meleeWeapon = manager->items[0];
	slot.rangedWeapon = manager->items[2];
	slot.armor = manager->items[4];
}

float PlayerInfoManager::getAttackSpeed()
{
	float ent = (float)stats.entrophy;
	return 100.0f / (100.0f + ent);
}
float PlayerInfoManager::getDamageReduction()
{
	
	float hard = (float)(stats.hardness +  slot.armor->stats.hardness);
	return 100.0f / (100.0f + hard);
}
int PlayerInfoManager::getMeleeDamage()
{
	
	float attack = (float)slot.meleeWeapon->stats.attack;
	float pw = (float)(stats.power + slot.meleeWeapon->stats.power + slot.armor->stats.power);
	int result = (int)(attack / 100.0f * 4.0f * pw * 1.5f);
	return result;
}
int PlayerInfoManager::getRangedDamage()
{
	float attack = (float)slot.rangedWeapon->stats.attack;
	float prec = (float)(stats.precision + slot.rangedWeapon->stats.precision + slot.armor->stats.precision);
	int result = (int)(attack / 100.0f * 4.0f * prec * 0.3f);
	return result;
}