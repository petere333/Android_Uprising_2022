#include "ItemManager.h"

ItemManager::ItemManager()
{
	init();
}

ItemManager::~ItemManager(){}

void ItemManager::init()
{
	EquipItem* basicGun = new EquipItem();
	EquipItem* basicHammer = new EquipItem();
	EquipItem* basicArmor = new EquipItem();

	basicGun->stats.attack = 30;
	basicGun->stats.capacity = 0;
	basicGun->stats.entrophy = 0;
	basicGun->stats.hardness = 0;
	basicGun->stats.power = 0;
	basicGun->stats.precision = 0;
	basicGun->type = RIFLE;


	basicHammer->stats.attack = 10;
	basicHammer->stats.capacity = 0;
	basicHammer->stats.entrophy = 0;
	basicHammer->stats.hardness = 0;
	basicHammer->stats.power = 0;
	basicHammer->stats.precision = 0;
	basicHammer->type = BLUNT;


	basicArmor->stats.attack = 0;
	basicArmor->stats.capacity = 5;
	basicArmor->stats.entrophy = 0;
	basicArmor->stats.hardness = 10;
	basicArmor->stats.power = 5;
	basicArmor->stats.precision = 5;
	basicArmor->type = ARMOR;

	items.push_back(basicHammer);
	items.push_back(basicGun);
	items.push_back(basicArmor);
	

}