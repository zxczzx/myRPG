#include "ObjectSpawn.h"
#include "Player.h"
#include "Abilities.h"
#include "Inventory.h"
#include "Requirements.h"
#include "Resistance.h"

ObjectSpawn::ObjectSpawn(){
}

ObjectSpawn::~ObjectSpawn(){
}

std::shared_ptr<Character> ObjectSpawn::spawnCharacter(std::string filename){
	std::shared_ptr<Character> character = Player::createPlayer<Player>();
	statsMap map = filesystem->readCharacterData(filename);
	//change attributes
	character->setName(map.find("name")->second[0]);
	character->setLevel(std::stoi(map.find("level")->second[0]));
	character->setHitPoints(std::stoi(map.find("hp")->second[0]));
	character->setMana(std::stoi(map.find("mp")->second[0]));
	//character->setExperience(std::stoi(map.find("exp")->second[0]));

	return character;
}

std::shared_ptr<Inventory> ObjectSpawn::spawnItem(std::string filename, int count) {
	filename = filename + ".lua";
	std::shared_ptr<Inventory> item = std::make_shared<Inventory>();
	statsMap map = filesystem->readItemData(filename);

	//change attributes
	if (getIntegerValue(map, "usable") == 1) {
		item->setAttackValue(getIntegerValue(map, "attackValue"));
		item->setArmorValue(getIntegerValue(map, "armorValue"));
		item->setMaxDurability(getIntegerValue(map, "maxDurability"));
		item->setDurability(getIntegerValue(map, "durability"));
		//ItemSlot
		item->setItemSlot(getSlotFromString(getStringValue(map, "itemSlot")));
		//Abilities
		for (auto& ability : map.find("Abilities")->second) {
			item->setAbilities(spawnAbility(ability, 1));
		}
		//Resistance
		item->setResistance(createResistance(map));
		//Requirements
		item->setRequirements(createRequirements(map));

		item->setThisObj(item);
	}
	item->setName(getStringValue(map, "name"));
	item->setDescription(getStringValue(map, "description"));
	item->setUsable(getIntegerValue(map, "usable"));

	item->setQuantity(count);

	return item;
}

std::shared_ptr<Abilities> ObjectSpawn::spawnAbility(std::string filename, int count){
	filename = filename + ".lua";
	std::shared_ptr<Abilities> ability = std::make_shared<Abilities>();
	statsMap map = filesystem->readAbilityData(filename);
	//change attributes
	ability->setName(getStringValue(map, "name"));
	ability->setDescription(getStringValue(map, "description"));
	ability->setQuantity(getIntegerValue(map, "quantity"));
	ability->setUseString(getStringValue(map, "useString"));
	ability->setDamage(getIntegerValue(map, "damage"));
	ability->setManaConsumption(getIntegerValue(map, "manaConsumprion"));
	//Requirements
	ability->setRequirements(createRequirements(map));

	ability->setQuantity(count);
	ability->setThisObj(ability);
	return ability;
}

ItemSlot ObjectSpawn::getSlotFromString(std::string slot){
	if (slot == "HEAD"){
		return ItemSlot::HEAD;
	}
	else if (slot == "BODY"){
		return ItemSlot::BODY;
	}
	else if (slot == "LEGS"){
		return ItemSlot::LEGS;
	}
	else if (slot == "FEET"){
		return ItemSlot::FEET;
	}
	else if (slot == "SHOULDERS"){
		return ItemSlot::SHOULDERS;
	}
	else if (slot == "GLOVES"){
		return ItemSlot::GLOVES;
	}
	else if (slot == "POTIONS"){
		return ItemSlot::POTIONS;
	}
	else if (slot == "MAIN_HAND"){
		return ItemSlot::MAIN_HAND;
	}
	else if (slot == "OFFHAND"){
		return ItemSlot::OFFHAND;
	}
	else if (slot == "BOTH_HANDS"){
		return ItemSlot::BOTH_HANDS;
	}
}

int ObjectSpawn::getIntegerValue(statsMap map, std::string key){
	return std::stoi(map.find(key)->second[0]);
}

std::string ObjectSpawn::getStringValue(statsMap map, std::string key){
	return map.find(key)->second[0];
}

std::shared_ptr<Requirements> ObjectSpawn::createRequirements(statsMap map){
	std::shared_ptr<Requirements> req = std::make_shared<Requirements>();
	req->classType = map.find("class")->second;
	req->level = getIntegerValue(map, "level");
	return req;
}

std::shared_ptr<Resistance> ObjectSpawn::createResistance(statsMap map){
	std::shared_ptr<Resistance> resis = std::make_shared<Resistance>();
	resis->setColdImmunity(getIntegerValue(map, "cold"));
	resis->setElectricityImmunity(getIntegerValue(map, "electricity"));
	resis->setFireImmunity(getIntegerValue(map, "fire"));
	resis->setWaterImmunity(getIntegerValue(map, "water"));
	return resis;
}
