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

std::shared_ptr<Player> ObjectSpawn::spawnActor(std::string filename){
	if (filename.find(".save") == std::string::npos) {
		filename = filename + ".lua";
	}

	std::shared_ptr<Player> character = Player::createActor<Player>();
	statsMap map = filesystem->readCharacterData(filename);
	//change attributes
	character->setName(getStringValue(map, "name"));
	character->setClassType(getStringValue(map, "class"));
	character->setLevel(getIntegerValue(map, "level"));
	character->setExperience(getIntegerValue(map, "exp"));
	character->setInitiative(getIntegerValue(map, "init"));
	character->setHitPoints(getIntegerValue(map, "hp"));
	character->setMaxHitPoints(getIntegerValue(map, "maxHP"));
	character->setMana(getIntegerValue(map, "mp"));
	character->setMaxMana(getIntegerValue(map, "maxMP"));
	character->setDamage(getIntegerValue(map, "damage"));
	character->setArmor(getIntegerValue(map, "armor"));
	character->setFriedly(getIntegerValue(map, "friendly"));
	character->setHpGrowth(getIntegerValue(map, "hpGrowth"));
	character->setMpGrowth(getIntegerValue(map, "mpGrowth"));
	character->setDmgGrowth(getIntegerValue(map, "dmgGrowth"));
	//Resistance
	character->setResistance(createResistance(map));
	//Abilities
	for (auto& ability : map.find("Abilities")->second) {
		character->setAbilities(spawnAbility(ability, 1));
	}
	//Backpack
	for (int i = 0; i < map.find("backpack")->second.size(); i += 2) {
		auto item = spawnItem(map.find("backpack")->second[i], std::stoi(map.find("backpack")->second[i + 1]));
		character->getBackpack()->appendToBackpack(item);
	}
	//using items
	if (getStringValue(map, "head") != "0") {
		auto item = spawnItem(getStringValue(map, "head"), 1);
		character->BodySlots[ItemSlot::HEAD] = item;
	}
	else if (getStringValue(map, "body") != "0") {
		auto item = spawnItem(getStringValue(map, "body"), 1);
		character->BodySlots[ItemSlot::BODY] = item;
	}
	else if (getStringValue(map, "legs") != "0") {
		auto item = spawnItem(getStringValue(map, "legs"), 1);
		character->BodySlots[ItemSlot::LEGS] = item;
	}
	else if (getStringValue(map, "feet") != "0") {
		auto item = spawnItem(getStringValue(map, "feet"), 1);
		character->BodySlots[ItemSlot::FEET] = item;
	}
	else if (getStringValue(map, "shoulders") != "0") {
		auto item = spawnItem(getStringValue(map, "shoulders"), 1);
		character->BodySlots[ItemSlot::SHOULDERS] = item;
	}
	else if (getStringValue(map, "gloves") != "0") {
		auto item = spawnItem(getStringValue(map, "gloves"), 1);
		character->BodySlots[ItemSlot::GLOVES] = item;
	}
	else if (getStringValue(map, "mainhand") != "0") {
		auto item = spawnItem(getStringValue(map, "mainhand"), 1);
		character->BodySlots[ItemSlot::MAIN_HAND] = item;
	}
	else if (getStringValue(map, "offhand") != "0") {
		auto item = spawnItem(getStringValue(map, "offhand"), 1);
		character->BodySlots[ItemSlot::OFFHAND] = item;
	}

	character->setRealValues();
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
