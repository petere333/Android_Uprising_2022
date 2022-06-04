#include "PlayerInfoManager.h"

PlayerInfoManager::PlayerInfoManager()
{
	initGrowth();
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
}

void PlayerInfoManager::initStats()
{
	stats.capacity = 50;
	stats.hardness = 4;
	stats.power = 4;
	stats.precision = 4;
	stats.entrophy = 4;
	stats.attack = 0;
}

float PlayerInfoManager::getAttackSpeed()
{
	float ent = (float)stats.entrophy;
	return 100.0f / (100.0f + ent);
}
float PlayerInfoManager::getDamageReduction()
{
	
	float hard = (float)(stats.hardness + slot.weapon->stats.hardness + slot.armor->stats.hardness);
	return 100.0f / (100.0f + hard);
}
int PlayerInfoManager::getMeleeDamage()
{
	
	float attack = (float)slot.weapon->stats.attack;
	float pw = (float)(stats.power + slot.weapon->stats.power + slot.armor->stats.power);
	return (int) (attack / 100.0f * 4.0f * pw * 1.5f);
}
int PlayerInfoManager::getRangedDamage()
{
	float attack = (float)slot.weapon->stats.attack;
	float prec = (float)(stats.precision + slot.weapon->stats.precision + slot.armor->stats.precision);
	return (int)(attack / 100.0f * 4.0f * prec * 0.3f);
}