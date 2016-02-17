#include "Inventory.h"
#include "Requirements.h"
#include "ItemSlot.h"
#include "Abilities.h"
#include "Resistance.h"
#include "Actor.h"


Inventory::Inventory(){
	//Inventory = std::make_shared<Inventory>();
	name = "default";
	description = "Some item";
	quantity = 1;
	//usable = false;

	maxDurability = 0;
	durability = maxDurability;
	armorValue = 0;
	attackValue = 0;
	usable = true;
	itemSlot = ItemSlot::POTIONS;

	requirements = std::make_shared<Requirements>();
	abilities = std::make_shared<Abilities>();
	resistance = std::make_shared<Resistance>();
	thisObj = nullptr;
}

Inventory::~Inventory(){
}

void Inventory::showDescription(){
	std::cout << description << std::endl;
}

//GETTERS

std::string Inventory::getName(){
	return name;
}

bool Inventory::isUsable(){
	return usable;
}

int Inventory::getQuantity(){
	return quantity;
}

ItemSlot Inventory::getItemSlot() {
	return itemSlot;
}

std::shared_ptr<Resistance> Inventory::getResistance() {
	return resistance;
}

std::shared_ptr<Abilities> Inventory::getAbilities() {
	return abilities;
}

int Inventory::getAttackValue() {
	return attackValue;
}

int Inventory::getArmorValue() {
	return armorValue;
}

std::shared_ptr<Requirements> Inventory::getRequirements() {
	return requirements;
}

int Inventory::getDurability() {
	return durability;
}

int Inventory::getMaxDurability() {
	return maxDurability;
}

//SETTERS

void Inventory::setQuantity(int count) {
	quantity = count;
}

void Inventory::setName(std::string value) {
	name = value;
}

void Inventory::setDescription(std::string value) {
	description = value;
}

void Inventory::setUsable(bool flag) {
	usable = flag;
}

void Inventory::setAttackValue(int value) {
	attackValue = value;
}

void Inventory::setArmorValue(int value) {
	armorValue = value;
}

void Inventory::setItemSlot(ItemSlot slot) {
	itemSlot = slot;
}

void Inventory::setDurability(int value) {
	durability = value;
}

void Inventory::setMaxDurability(int value) {
	maxDurability = value;
}

void Inventory::setRequirements(std::shared_ptr<Requirements> obj) {
	requirements = obj;
}

void Inventory::setResistance(std::shared_ptr<Resistance> obj) {
	resistance = obj;
}

void Inventory::setAbilities(std::shared_ptr<Abilities> obj) {
	abilities = obj;
}

void Inventory::setThisObj(std::shared_ptr<Inventory> me) {
	thisObj = me;
}

//METHODS

void Inventory::use(std::shared_ptr<Actor> actor) {
	//TODO this is temporary healing potion -> it should be triggered as ability which is not implemented here yet
	if (itemSlot == ItemSlot::POTIONS) {
		thisObj->getAbilities()->execute(actor, actor);
		quantity--;
		if (quantity < 1) {
			actor->getBackpack()->removeFromBackpack(thisObj);
		}
		return;
	}

	if (itemSlot == ItemSlot::HEAD) {
		actor->BodySlots[ItemSlot::HEAD] = thisObj;
	}
	else if (itemSlot == ItemSlot::BODY) {
		actor->BodySlots[ItemSlot::BODY] = thisObj;
	}
	else if (itemSlot == ItemSlot::LEGS) {
		actor->BodySlots[ItemSlot::LEGS] = thisObj;
	}
	else if (itemSlot == ItemSlot::FEET) {
		actor->BodySlots[ItemSlot::FEET] = thisObj;
	}
	else if (itemSlot == ItemSlot::SHOULDERS) {
		actor->BodySlots[ItemSlot::SHOULDERS] = thisObj;
	}
	else if (itemSlot == ItemSlot::GLOVES) {
		actor->BodySlots[ItemSlot::GLOVES] = thisObj;
	}
	else if (itemSlot == ItemSlot::BOTH_HANDS) {
		actor->BodySlots[ItemSlot::MAIN_HAND] = thisObj;
		actor->BodySlots[ItemSlot::OFFHAND] = thisObj;
	}
	else if (itemSlot == ItemSlot::OFFHAND) {
		actor->BodySlots[ItemSlot::OFFHAND] = thisObj;
	}
	else {
		actor->BodySlots[ItemSlot::MAIN_HAND] = thisObj;
	}
	//Actor->getAbilities().push_back(thisObj->getAbilities());	// add vector of abilities to vector if two abilities are the same, make it BetterAbility

	actor->getResistance()->setColdImmunity(actor->getResistance()->getColdImmunity() + thisObj->getResistance()->getColdImmunity());
	actor->getResistance()->setFireImmunity(actor->getResistance()->getFireImmunity() + thisObj->getResistance()->getFireImmunity());
	actor->getResistance()->setElectricityImmunity(actor->getResistance()->getElectricityImmunity() + thisObj->getResistance()->getElectricityImmunity());
	actor->getResistance()->setWaterImmunity(actor->getResistance()->getWaterImmunity() + thisObj->getResistance()->getWaterImmunity());

	actor->setRealArmor(actor->getRealArmor() + armorValue);
	actor->setRealDamage(actor->getRealDamage() + attackValue);
	actor->getBackpack()->removeFromBackpack(thisObj);
}

void Inventory::unuse(std::shared_ptr<Actor> actor) {
	if (itemSlot == ItemSlot::HEAD) {
		actor->BodySlots[ItemSlot::HEAD] = nullptr;
	}
	else if (itemSlot == ItemSlot::BODY) {
		actor->BodySlots[ItemSlot::BODY] = nullptr;
	}
	else if (itemSlot == ItemSlot::LEGS) {
		actor->BodySlots[ItemSlot::LEGS] = nullptr;
	}
	else if (itemSlot == ItemSlot::FEET) {
		actor->BodySlots[ItemSlot::FEET] = nullptr;
	}
	else if (itemSlot == ItemSlot::SHOULDERS) {
		actor->BodySlots[ItemSlot::SHOULDERS] = nullptr;
	}
	else if (itemSlot == ItemSlot::GLOVES) {
		actor->BodySlots[ItemSlot::GLOVES] = nullptr;
	}
	else if (itemSlot == ItemSlot::BOTH_HANDS) {
		actor->BodySlots[ItemSlot::MAIN_HAND] = nullptr;
		actor->BodySlots[ItemSlot::OFFHAND] = nullptr;
	}
	else if (itemSlot == ItemSlot::OFFHAND) {
		actor->BodySlots[ItemSlot::OFFHAND] = nullptr;
	}
	else {
		actor->BodySlots[ItemSlot::MAIN_HAND] = nullptr;
	}
	//Actor->getAbilities().push_back(thisObj->getAbilities());	//remove abilities from vector -> if ability is BetterAbility, make it normal

	actor->getResistance()->setColdImmunity(actor->getResistance()->getColdImmunity() - thisObj->getResistance()->getColdImmunity());
	actor->getResistance()->setFireImmunity(actor->getResistance()->getFireImmunity() - thisObj->getResistance()->getFireImmunity());
	actor->getResistance()->setElectricityImmunity(actor->getResistance()->getElectricityImmunity() - thisObj->getResistance()->getElectricityImmunity());
	actor->getResistance()->setWaterImmunity(actor->getResistance()->getWaterImmunity() - thisObj->getResistance()->getWaterImmunity());

	actor->setRealArmor(actor->getRealArmor() - armorValue);

	actor->setRealDamage(actor->getRealDamage() - attackValue);
}