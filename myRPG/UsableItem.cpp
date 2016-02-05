#include "UsableItem.h"
#include "Player.h"

UsableItem::UsableItem(){
	maxDurability = 0;
	durability = maxDurability;
	armorValue = 0;
	attackValue = 0;
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
	//TODO this is temporary healing potion -> it should be triggered as ability which is not implemented here yet
	if (itemSlot == ItemSlot::POTIONS){
		player.setHitPoints(player.getHitPoints() + 10);
		if (player.getHitPoints() > player.getMaxHitPoints()){
			player.setHitPoints(player.getMaxHitPoints());
		}
		quantity--;
		if (quantity < 1){
			player.getBackpack()->removeFromBackpack(thisObj);
		}
		return;
	}

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
	else if (itemSlot == ItemSlot::BOTH_HANDS){
		player.BodySlots[ItemSlot::MAIN_HAND] = thisObj;
		player.BodySlots[ItemSlot::OFFHAND] = thisObj;
	}
	else if (itemSlot == ItemSlot::OFFHAND) {
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

	player.setRealArmor(player.getRealArmor() + armorValue);
	player.setRealDamage(player.getRealDamage() + attackValue);
	player.getBackpack()->removeFromBackpack(thisObj);
}

void UsableItem::unuse(Player& player){
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
	else if (itemSlot == ItemSlot::BOTH_HANDS){
		player.BodySlots[ItemSlot::MAIN_HAND] = nullptr;
		player.BodySlots[ItemSlot::OFFHAND] = nullptr;
	}
	else if (itemSlot == ItemSlot::OFFHAND){
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

	player.setRealArmor(player.getRealArmor() - armorValue);

	player.setRealDamage(player.getRealDamage() - attackValue);
}

std::shared_ptr<Resistance> UsableItem::getResistance(){
	return resistance;
}

std::shared_ptr<Abilities> UsableItem::getAbilities(){
	return abilities;
}

int UsableItem::getAttackValue(){
	return attackValue;
}

int UsableItem::getArmorValue(){
	return armorValue;
}

std::shared_ptr<Requirements> UsableItem::getRequirements(){
	return requirements;
}

int UsableItem::getDurability(){
	return durability;
}

int UsableItem::getMaxDurability(){
	return maxDurability;
}

void UsableItem::setAttackValue(int value){
	attackValue = value;
}

void UsableItem::setArmorValue(int value){
	armorValue = value;
}

void UsableItem::setItemSlot(ItemSlot slot){
	itemSlot = slot;
}

void UsableItem::setDurability(int value){
	durability = value;
}

void UsableItem::setMaxDurability(int value){
	maxDurability = value;
}

void UsableItem::setRequirements(std::shared_ptr<Requirements> obj){
	requirements = obj;
}

void UsableItem::setResistance(std::shared_ptr<Resistance> obj){
	resistance = obj;
}

void UsableItem::setAbilities(std::shared_ptr<Abilities> obj){
	abilities = obj;
}

void UsableItem::setThisObj(std::shared_ptr<UsableItem> me){
	thisObj = me;
}
