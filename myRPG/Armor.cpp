#include "Armor.h"
#include "Player.h"

Armor::Armor(){
}

Armor::~Armor(){
}

void Armor::use(Player& player){
	if (itemSlot == ItemSlot::HEAD){
		player.BodySlots[ItemSlot::HEAD] = thisObj;
	}
	else if (itemSlot == ItemSlot::BODY){
		player.BodySlots[ItemSlot::BODY] = thisObj;
	}
	else if (itemSlot == ItemSlot::LEGS){
		player.BodySlots[ItemSlot::LEGS] = thisObj;
	}
	else if (itemSlot == ItemSlot::FEET){
		player.BodySlots[ItemSlot::FEET] = thisObj;
	}
	else if (itemSlot == ItemSlot::SHOULDERS){
		player.BodySlots[ItemSlot::SHOULDERS] = thisObj;
	}
	else if (itemSlot == ItemSlot::GLOVES){
		player.BodySlots[ItemSlot::GLOVES] = thisObj;
	}
	//player.getAbilities().push_back(thisObj->getAbilities());	// add vector of abilities to vector if two abilities are the same, make it BetterAbility

	player.getResistance()->setColdImmunity(player.getResistance()->getColdImmunity() + thisObj->getResistance()->getColdImmunity());
	player.getResistance()->setFireImmunity(player.getResistance()->getFireImmunity() + thisObj->getResistance()->getFireImmunity());
	player.getResistance()->setElectricityImmunity(player.getResistance()->getElectricityImmunity() + thisObj->getResistance()->getElectricityImmunity());
	player.getResistance()->setWaterImmunity(player.getResistance()->getWaterImmunity() + thisObj->getResistance()->getWaterImmunity());

	player.setRealArmor(player.getRealArmor() + armorValue);
	player.getBackpack()->removeFromBackpack(thisObj);
}

void Armor::unuse(Player& player){
	if (itemSlot == ItemSlot::HEAD){
		player.BodySlots[ItemSlot::HEAD] = nullptr;
	}
	else if (itemSlot == ItemSlot::BODY){
		player.BodySlots[ItemSlot::BODY] = nullptr;
	}
	else if (itemSlot == ItemSlot::LEGS){
		player.BodySlots[ItemSlot::LEGS] = nullptr;
	}
	else if (itemSlot == ItemSlot::FEET){
		player.BodySlots[ItemSlot::FEET] = nullptr;
	}
	else if (itemSlot == ItemSlot::SHOULDERS){
		player.BodySlots[ItemSlot::SHOULDERS] = nullptr;
	}
	else if (itemSlot == ItemSlot::GLOVES){
		player.BodySlots[ItemSlot::GLOVES] = nullptr;
	}
	//player.getAbilities().push_back(thisObj->getAbilities());	//remove abilities from vector -> if ability is BetterAbility, make it normal

	player.getResistance()->setColdImmunity(player.getResistance()->getColdImmunity() - thisObj->getResistance()->getColdImmunity());
	player.getResistance()->setFireImmunity(player.getResistance()->getFireImmunity() - thisObj->getResistance()->getFireImmunity());
	player.getResistance()->setElectricityImmunity(player.getResistance()->getElectricityImmunity() - thisObj->getResistance()->getElectricityImmunity());
	player.getResistance()->setWaterImmunity(player.getResistance()->getWaterImmunity() - thisObj->getResistance()->getWaterImmunity());

	player.setRealArmor(player.getRealArmor() - armorValue);
}
