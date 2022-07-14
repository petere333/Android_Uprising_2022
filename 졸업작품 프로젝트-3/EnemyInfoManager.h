#pragma once

#include "EnemyData.h"

class EnemyInfoManager
{
public:
	EnemyInfoManager(int attack, int hard, float r);
	~EnemyInfoManager();

public:
	EStats stats;

public:
	float getDamageReduction();
	int getDamage();
	float getRange();
};