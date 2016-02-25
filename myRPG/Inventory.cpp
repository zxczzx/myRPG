#include "Inventory.h"
#include "Requirements.h"
#include "ItemSlot.h"
#include "Abilities.h"
#include "Resistance.h"
#include "Player.h"


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

void Inventory::use(std::shared_ptr<Player> player) {
	//TODO this is temporary healing potion -> it should be triggered as ability which is not implemented here yet
	if (itemSlot == ItemSlot::POTIONS) {
		thisObj->getAbilities()->execute(player, player);
		quantity--;
		if (quantity < 1) {
			player->getBackpack()->removeFromBackpack(thisObj);
		}
		return;
	}

	if (itemSlot == ItemSlot::HEAD) {
		player->BodySlots[ItemSlot::HEAD] = thisObj;
	}
	else if (itemSlot == ItemSlot::BODY) {
		player->BodySlots[ItemSlot::BODY] = thisObj;
	}
	else if (itemSlot == ItemSlot::LEGS) {
		player->BodySlots[ItemSlot::LEGS] = thisObj;
	}
	else if (itemSlot == ItemSlot::FEET) {
		player->BodySlots[ItemSlot::FEET] = thisObj;
	}
	else if (itemSlot == ItemSlot::SHOULDERS) {
		player->BodySlots[ItemSlot::SHOULDERS] = thisObj;
	}
	else if (itemSlot == ItemSlot::GLOVES) {
		player->BodySlots[ItemSlot::GLOVES] = thisObj;
	}
	else if (itemSlot == ItemSlot::BOTH_HANDS) {
		player->BodySlots[ItemSlot::MAIN_HAND] = thisObj;
		player->BodySlots[ItemSlot::OFFHAND] = thisObj;
	}
	else if (itemSlot == ItemSlot::OFFHAND) {
		player->BodySlots[ItemSlot::OFFHAND] = thisObj;
	}
	else {
		player->BodySlots[ItemSlot::MAIN_HAND] = thisObj;
	}
	//Player->getAbilities().push_back(thisObj->getAbilities());	// add vector of abilities to vector if two abilities are the same, make it BetterAbility

	player->getResistance()->setColdImmunity(player->getResistance()->getColdImmunity() + thisObj->getResistance()->getColdImmunity());
	player->getResistance()->setFireImmunity(player->getResistance()->getFireImmunity() + thisObj->getResistance()->getFireImmunity());
	player->getResistance()->setElectricityImmunity(player->getResistance()->getElectricityImmunity() + thisObj->getResistance()->getElectricityImmunity());
	player->getResistance()->setWaterImmunity(player->getResistance()->getWaterImmunity() + thisObj->getResistance()->getWaterImmunity());

	player->setRealArmor(player->getRealArmor() + armorValue);
	player->setRealDamage(player->getRealDamage() + attackValue);
	player->getBackpack()->removeFromBackpack(thisObj);
}

void Inventory::unuse(std::shared_ptr<Player> player) {
	if (itemSlot == ItemSlot::HEAD) {
		player->BodySlots[ItemSlot::HEAD] = nullptr;
	}
	else if (itemSlot == ItemSlot::BODY) {
		player->BodySlots[ItemSlot::BODY] = nullptr;
	}
	else if (itemSlot == ItemSlot::LEGS) {
		player->BodySlots[ItemSlot::LEGS] = nullptr;
	}
	else if (itemSlot == ItemSlot::FEET) {
		player->BodySlots[ItemSlot::FEET] = nullptr;
	}
	else if (itemSlot == ItemSlot::SHOULDERS) {
		player->BodySlots[ItemSlot::SHOULDERS] = nullptr;
	}
	else if (itemSlot == ItemSlot::GLOVES) {
		player->BodySlots[ItemSlot::GLOVES] = nullptr;
	}
	else if (itemSlot == ItemSlot::BOTH_HANDS) {
		player->BodySlots[ItemSlot::MAIN_HAND] = nullptr;
		player->BodySlots[ItemSlot::OFFHAND] = nullptr;
	}
	else if (itemSlot == ItemSlot::OFFHAND) {
		player->BodySlots[ItemSlot::OFFHAND] = nullptr;
	}
	else {
		player->BodySlots[ItemSlot::MAIN_HAND] = nullptr;
	}
	//Player->getAbilities().push_back(thisObj->getAbilities());	//remove abilities from vector -> if ability is BetterAbility, make it normal

	player->getResistance()->setColdImmunity(player->getResistance()->getColdImmunity() - thisObj->getResistance()->getColdImmunity());
	player->getResistance()->setFireImmunity(player->getResistance()->getFireImmunity() - thisObj->getResistance()->getFireImmunity());
	player->getResistance()->setElectricityImmunity(player->getResistance()->getElectricityImmunity() - thisObj->getResistance()->getElectricityImmunity());
	player->getResistance()->setWaterImmunity(player->getResistance()->getWaterImmunity() - thisObj->getResistance()->getWaterImmunity());

	player->setRealArmor(player->getRealArmor() - armorValue);

	player->setRealDamage(player->getRealDamage() - attackValue);
}