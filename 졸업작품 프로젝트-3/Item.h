#pragma once


//아이템 유형

#define DUALBLADE 1
#define BLUNT 2
#define RIFLE 3
#define BAZUKA 4
#define RADIO 5
#define ARMOR 6

#include "PlayerData.h"


class CMaterial;



class Item
{
public:
	Item() {};
	~Item() {};
public:
	CMaterial* name = 0;
	CMaterial* image= 0;
	CMaterial* desc = 0;
	
};
class EquipItem : Item
{
public:
	EquipItem() {};
	~EquipItem() {};

public:
	Stats stats;
	int type;

};
class UsableItem :Item
{
public:
	UsableItem();
	~UsableItem();
public:
	Stats stats;
};