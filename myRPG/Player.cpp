#include "Player.h"
#include "HealthPotion.h"
#include "ObjectSpawn.h"

Player::Player() : Character() {
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
	resistance->setColdImmunity(0);
	resistance->setFireImmunity(0);
	resistance->setElectricityImmunity(0);
	resistance->setWaterImmunity(0);
	thisObj = nullptr;

	//temporary starting pack
	std::shared_ptr<ObjectSpawn> spawner = std::make_shared<ObjectSpawn>();
	backpack->appendToBackpack(spawner->spawnItem("Axe", 1));
	backpack->appendToBackpack(spawner->spawnItem("Shirt", 1));
	backpack->appendToBackpack(spawner->spawnItem("Health potion", 2));
	//end temp

	std::map<ItemSlot, std::shared_ptr<UsableItem> > BodySlots = {
		{ ItemSlot::HEAD, nullptr }, { ItemSlot::BODY, nullptr }, { ItemSlot::LEGS, nullptr }, { ItemSlot::FEET, nullptr }, { ItemSlot::SHOULDERS, nullptr }, { ItemSlot::GLOVES, nullptr }, { ItemSlot::POTIONS, nullptr }, { ItemSlot::MAIN_HAND, nullptr }, { ItemSlot::OFFHAND, nullptr }
	};

	setRealValues();
}

std::map<int, int> Player::lvlMap = { 
	{ 1, 5 }, { 2, 50 }, { 3, 100 }, { 4, 200 }, { 5, 400 }, { 6, 800 }, { 7, 1600 }, { 8, 3200 }, { 9, 6400 }, { 10, 12800 } 
};

Player::~Player(){
}

//GETTERS

int Player::getExperience(){
	return experience;
}

std::string Player::getClassType(){
	return classType;
}

std::map<int, int> Player::getLvLMap(){
	return lvlMap;
}

std::shared_ptr<Backpack<Inventory> > Player::getBackpack(){
	return backpack;
}

//SETTERS

void Player::setExperience(int exp){
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

void Player::setClassType(std::string myClassType){
	classType = myClassType;
}

void Player::setThisObj(std::shared_ptr<Player> me){
	thisObj = me;
}

//METHODS

void Player::useAbility(std::shared_ptr<Abilities> ability){
	std::cout << "Player used ability " << ability << std::endl;
}

void Player::useItem(std::shared_ptr<UsableItem> item){
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

void Player::takeOffItem(std::shared_ptr<UsableItem> item){
	item->unuse(thisObj);
	backpack->appendToBackpack(item);
}

bool Player::isLvlUp(){
	if (this->experience >= lvlMap.find(this->level)->second){
		return true;
	}
	else{
		return false;
	}
}

void Player::statsGrowth(){
	maxHitPoints += level;
	maxMana += level;
	setRealValues();
}