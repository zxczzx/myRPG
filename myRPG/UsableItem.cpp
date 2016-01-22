#include "UsableItem.h"

UsableItem::UsableItem() : Inventory() {
	maxDurability = 0;
	durability = maxDurability;
	usable = true;
	itemSlot = ItemSlot::POTIONS;

	requirements = std::make_shared<Requirements>();
	thisObj = nullptr;
}

UsableItem::~UsableItem(){
}

ItemSlot UsableItem::getItemSlot(){
	return itemSlot;
}

void UsableItem::use(Player& player){
}

void UsableItem::unuse(Player& player){
}