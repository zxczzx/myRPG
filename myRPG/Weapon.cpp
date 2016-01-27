#include "Weapon.h"
#include "Player.h"

Weapon::Weapon(){
}

Weapon::~Weapon(){
}

void Weapon::use(Player& player){
	if (itemSlot == ItemSlot::BOTH_HANDS){
		player.BodySlots[ItemSlot::MAIN_HAND] = thisObj;
		player.BodySlots[ItemSlot::OFFHAND] = thisObj;
	}
	else{
		player.BodySlots[ItemSlot::MAIN_HAND] = thisObj;
	}
	//player.getAbilities().push_back(thisObj->getAbilities());	// add vector of abilities to vector if two abilities are the same, make it BetterAbility

	player.getResistance()->setColdImmunity(player.getResistance()->getColdImmunity() + thisObj->getResistance()->getColdImmunity());
	player.getResistance()->setFireImmunity(player.getResistance()->getFireImmunity() + thisObj->getResistance()->getFireImmunity());
	player.getResistance()->setElectricityImmunity(player.getResistance()->getElectricityImmunity() + thisObj->getResistance()->getElectricityImmunity());
	player.getResistance()->setWaterImmunity(player.getResistance()->getWaterImmunity() + thisObj->getResistance()->getWaterImmunity());

	player.setRealDamage(player.getRealDamage() + attackValue);
	player.getBackpack()->removeFromBackpack(thisObj);
}

void Weapon::unuse(Player& player){
	if (itemSlot == ItemSlot::BOTH_HANDS){
		player.BodySlots[ItemSlot::MAIN_HAND] = nullptr;
		player.BodySlots[ItemSlot::OFFHAND] = nullptr;
	}
	else{
		player.BodySlots[ItemSlot::MAIN_HAND] = nullptr;
	}
	//player.getAbilities().push_back(thisObj->getAbilities());	//remove abilities from vector -> if ability is BetterAbility, make it normal

	player.getResistance()->setColdImmunity(player.getResistance()->getColdImmunity() - thisObj->getResistance()->getColdImmunity());
	player.getResistance()->setFireImmunity(player.getResistance()->getFireImmunity() - thisObj->getResistance()->getFireImmunity());
	player.getResistance()->setElectricityImmunity(player.getResistance()->getElectricityImmunity() - thisObj->getResistance()->getElectricityImmunity());
	player.getResistance()->setWaterImmunity(player.getResistance()->getWaterImmunity() - thisObj->getResistance()->getWaterImmunity());

	player.setRealDamage(player.getRealDamage() - attackValue);
}