#include "UsableItem.h"

UsableItem::UsableItem() : Inventory() {
	maxDurability = 0;
	durability = maxDurability;
	used = 0;
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

bool UsableItem::getUsed(){
	return used;
}

void UsableItem::setUsed(bool isused){
	used = isused;
}

void UsableItem::use(Player& player){

}

void UsableItem::unuse(Player& player){

}