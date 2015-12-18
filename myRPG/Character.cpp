#include "Character.h"

Character::Character(){
	std::cout << "Created character" << std::endl;
}

Character::~Character(){
}

//GETTERS

int Character::getHitPoints(){
	return hitPoints;
}

int Character::getMana(){
	return mana;
}

int Character::getLevel(){
	return level;
}

std::string Character::getName(){
	return name;
}
bool Character::getFriendly(){
	return friendly;
}

std::shared_ptr<Inventory> Character::getInventory(){
	return inventory;
}

std::shared_ptr<Abilities> Character::getAbilities(){
	return abilities;
}

//SETTERS

void Character::setFriedly(bool ff){
	friendly = ff;
}

void Character::setHitPoints(int hp){
	hitPoints = hp;
}

void Character::setLevel(int lvl){
	level = lvl;
}

void Character::setMana(int mp){
	mana = mp;
}

void Character::setName(std::string myName){
	name = myName;
}

void Character::setInventory(std::shared_ptr<Inventory> inv){
	inventory = inv;
}

void Character::setAbilities(std::shared_ptr<Abilities> myAbilities){
	abilities = myAbilities;
}

//METHODS

void Character::attack(){
	std::cout << "Character attack!" << std::endl;
}

void Character::death(){
	std::cout << "Character is dead" << std::endl;
}