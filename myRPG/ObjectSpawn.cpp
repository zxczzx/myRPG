#include "ObjectSpawn.h"
#include "Character.h"
#include "Abilities.h"
#include "UsableItem.h"

ObjectSpawn::ObjectSpawn(){
}

ObjectSpawn::~ObjectSpawn(){
}

std::shared_ptr<Character> ObjectSpawn::spawnCharacter(std::string filename){
	std::shared_ptr<Character> character = std::make_shared<Character>();
	statsMap map = filesystem->readCharacterData(filename);
	//change attributes

	character->setName(map.find("name")->second[0]);
	character->setLevel(std::stoi(map.find("level")->second[0]));
	character->setHitPoints(std::stoi(map.find("hp")->second[0]));
	character->setMana(std::stoi(map.find("mp")->second[0]));
	//character->setExperience(std::stoi(map.find("exp")->second[0]));

	return character;
}

std::shared_ptr<Abilities> ObjectSpawn::spawnAbility(std::string filename){
	filename = filename + ".lua";
	std::shared_ptr<Abilities> ability = std::make_shared<Abilities>();
	statsMap map = filesystem->readAbilityData(filename);
	//change attributes
	return ability;
}

std::shared_ptr<UsableItem> ObjectSpawn::spawnItem(std::string filename){
	filename = filename + ".lua";
	std::shared_ptr<UsableItem> item = std::make_shared<UsableItem>();
	statsMap map = filesystem->readItemData(filename);
	//change attributes
	auto getIntegerValue = [=](std::string key)->int{
		return std::stoi(map.find(key)->second[0]);
	};
	auto getStringValue = [=](std::string key) {
		return map.find(key)->second[0];
	};

	item->setName(getStringValue("name"));
	item->setDescription(getStringValue("description"));
	item->setQuantity(getIntegerValue("quantity"));
	item->setAttackValue(getIntegerValue("attackValue"));
	item->setArmorValue(getIntegerValue("armorValue"));
	item->setUsable(getIntegerValue("usable"));
	item->setMaxDurability(getIntegerValue("maxDurability"));
	item->setDurability(getIntegerValue("durability"));
	
	item->setItemSlot(getSlotFromString(getStringValue("itemSlot")));

	//item->setAbilities(getIntegerValue("Abilities"));
	//item->setResistance(getIntegerValue("Resistance"));
	//item->setRequirements(getIntegerValue("Requirements"));
	item->setThisObj(item);
	return item;
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