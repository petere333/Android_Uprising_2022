#pragma once


#include "PlayerData.h"

class CMaterial;



class Item
{
public:
	Item();
	~Item();
public:
	CMaterial* name = 0;
	CMaterial* image= 0;
	CMaterial* desc = 0;
	
};
class EquipItem : Item
{
public:
	EquipItem();
	~EquipItem();

public:
	Stats stats;

};
class UsableItem :Item
{
public:
	UsableItem();
	~UsableItem();
public:
	Stats stats;
};