#pragma once

#include "Item.h"

#include <vector>

class ItemManager
{
public: 
	ItemManager();
	~ItemManager();

	void init();

public:
	std::vector<EquipItem*> items;
};