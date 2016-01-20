#include "Player.h"
#include "Axe.h"

Player::Player() : Character() {
	maxHitPoints = 14;
	hitPoints = 14;
	level = 1;
	experience = 0;
	damage = 1;
	name = "default";
	classType = "default";
	friendly = true;

	//temporary
	std::shared_ptr<UsableItem> item = std::make_shared<UsableItem>();
	inventory.push_back(item->createItem<Axe>());
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

void Player::operator=(const Player &c){
	hitPoints = c.hitPoints;
	level = c.level;
	damage = c.damage;
	name = c.name;
	classType = c.classType;
	friendly = c.friendly;
	inventory = c.inventory;
	abilities = c.abilities;
	resistance = c.resistance;
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
		item->use(*this);
	}
	else{
		item->unuse(*this);
		item->use(*this);
	}
}

void Player::takeOffItem(std::shared_ptr<UsableItem> item){
	item->unuse(*this);
}

void Player::removeItem(std::shared_ptr<Inventory> item){
	for (unsigned i = 0; inventory.size(); i++){
		if (inventory[i]->getName() == item->getName()){
			inventory.erase(inventory.begin() + i);
		}
	}
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
