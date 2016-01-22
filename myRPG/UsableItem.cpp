#include "UsableItem.h"

UsableItem::UsableItem() : Inventory() {
	maxDurability = 0;
	durability = maxDurability;
	usable = true;
	itemSlot = ItemSlot::POTIONS;

	requirements = std::make_shared<Requirements>();
	abilities = std::make_shared<Abilities>();
	resistance = std::make_shared<Resistance>();
	resistance->setColdImmunity(0);
	resistance->setFireImmunity(0);
	resistance->setElectricityImmunity(0);
	resistance->setWaterImmunity(0);
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

std::shared_ptr<Resistance> UsableItem::getResistance(){
	return resistance;
}

std::shared_ptr<Abilities> UsableItem::getAbilities(){
	return abilities;
}