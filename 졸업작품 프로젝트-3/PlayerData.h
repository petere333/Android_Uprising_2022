#pragma once

typedef struct GrowthMelee
{
	int exp;
	int level;
}GrowthMelee;

typedef struct GrowthRanged
{
	int exp;
	int level;
}GrowthRanged;

typedef struct GrowthRadio
{
	int exp;
	int level;
}GrowthRadio;

typedef struct Growth
{
	GrowthMelee melee;
	GrowthRanged ranged;
	GrowthRadio radio;
}Growth;

typedef struct Stat
{
	int attack;
	int capacity;
	int hardness;
	int power;
	int precision;
	int entrophy;
}Stats;

