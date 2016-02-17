#include "Actor.h"
#include "ObjectSpawn.h"

Actor::Actor() : Character() {
	maxHitPoints = 14;
	hitPoints = 14;
	level = 1;
	experience = 0;
	damage = 1;
	name = "default";
	classType = "default";
	friendly = true;
	backpack = std::make_shared<Backpack<Inventory> >();
	resistance = std::make_shared<Resistance>();
	thisObj = nullptr;
	hpGrowth = 0;
	mpGrowth = 0;
	dmgGrowth = 0;

	//temporary starting pack
	//std::shared_ptr<ObjectSpawn> spawner = std::make_shared<ObjectSpawn>();
	//backpack->appendToBackpack(spawner->spawnItem("Axe", 1));
	//backpack->appendToBackpack(spawner->spawnItem("Shirt", 1));
	//backpack->appendToBackpack(spawner->spawnItem("Health potion", 2));
	//end temp

	std::map<ItemSlot, std::shared_ptr<Inventory> > BodySlots = {
		{ ItemSlot::HEAD, nullptr }, { ItemSlot::BODY, nullptr }, { ItemSlot::LEGS, nullptr }, { ItemSlot::FEET, nullptr }, { ItemSlot::SHOULDERS, nullptr }, { ItemSlot::GLOVES, nullptr }, { ItemSlot::POTIONS, nullptr }, { ItemSlot::MAIN_HAND, nullptr }, { ItemSlot::OFFHAND, nullptr }
	};

	setRealValues();
}

std::map<int, int> Actor::lvlMap = { 
	{ 1, 5 }, { 2, 50 }, { 3, 100 }, { 4, 200 }, { 5, 400 }, { 6, 800 }, { 7, 1600 }, { 8, 3200 }, { 9, 6400 }, { 10, 12800 } 
};

Actor::~Actor(){
}

//GETTERS

int Actor::getExperience(){
	return experience;
}

std::string Actor::getClassType(){
	return classType;
}

std::map<int, int> Actor::getLvLMap(){
	return lvlMap;
}

std::shared_ptr<Backpack<Inventory> > Actor::getBackpack(){
	return backpack;
}

//SETTERS

void Actor::setExperience(int exp){
	experience = exp;

	//check if character lvl'ed up
	if (isLvlUp()){
		setLevel(this->level + 1);
		statsGrowth();
		hitPoints = maxHitPoints;
		mana = maxMana;
		std::cout << "You leveled up to level " << this->level << "!" << std::endl;
	}
}

void Actor::setClassType(std::string myClassType){
	classType = myClassType;
}

void Actor::setThisObj(std::shared_ptr<Actor> me){
	thisObj = me;
}

//METHODS

void Actor::useAbility(std::shared_ptr<Abilities> ability){
	std::cout << "Actor used ability " << ability << std::endl;
}

void Actor::useItem(std::shared_ptr<Inventory> item){
	auto getSlot = [=](ItemSlot slot) {
		return BodySlots[slot] == nullptr ? "empty" : BodySlots[slot]->getName();
	};
	if (item->getItemSlot() == ItemSlot::POTIONS ||
		getSlot(item->getItemSlot()) == "empty"){
		item->use(thisObj);
	}
	else{
		item->unuse(thisObj);
		item->use(thisObj);
	}
}

void Actor::takeOffItem(std::shared_ptr<Inventory> item){
	item->unuse(thisObj);
	backpack->appendToBackpack(item);
}

bool Actor::isLvlUp(){
	if (this->experience >= lvlMap.find(this->level)->second){
		return true;
	}
	else{
		return false;
	}
}

void Actor::statsGrowth(){
	maxHitPoints += hpGrowth * level;
	maxMana += mpGrowth * level;
	damage += dmgGrowth * level;
	setRealValues();
}