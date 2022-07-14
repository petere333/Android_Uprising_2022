#include "EnemyInfoManager.h"

EnemyInfoManager::EnemyInfoManager(int att, int hard, float r)
{
	stats.attack = att;
	stats.hardness = hard;
	stats.range = r;
}

EnemyInfoManager::~EnemyInfoManager(){}

int EnemyInfoManager::getDamage()
{
	return stats.attack;
}
float EnemyInfoManager::getDamageReduction()
{
	return 100.0f / (100.0f + (float)stats.hardness);
}
float EnemyInfoManager::getRange()
{
	return stats.range;
}