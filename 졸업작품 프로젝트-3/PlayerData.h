#pragma once

static int expNeed[9] =
{
	100,200,300,400,500,600,700,800,900
};
static int totalExpNeed[9] =
{
	500,1000,1500,2000,2500,3000,3500,4000,4500
};

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

typedef struct GrowthTotal
{
	int exp;
	int level;
}GrowthTotal;

typedef struct Growth
{
	GrowthMelee melee;
	GrowthRanged ranged;
	GrowthRadio radio;
	GrowthTotal total;
}Growth;

typedef struct Stat
{
	int maxhp;
	int attack;
	int capacity;
	int hardness;
	int power;
	int precision;
	int entrophy;
}Stats;

