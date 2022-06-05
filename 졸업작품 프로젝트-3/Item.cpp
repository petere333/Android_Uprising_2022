#include "Item.h"
#include "Object.h"
Item::Item(){}
Item::~Item(){}

EquipItem::EquipItem() : Item(){}
EquipItem::~EquipItem(){}

UsableItem::UsableItem():Item(){}
UsableItem::~UsableItem(){}