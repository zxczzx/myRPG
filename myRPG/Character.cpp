#include "Character.h"

Character::Character(){
	hitPoints = 0;
	mana = 0;
	level = 0;
	initiative = 0;
	damage = 0;
	armor = 0;
	name = "default";
	friendly = true;
	inventory = nullptr;
	abilities = nullptr;
}

Character::~Character(){
}

void Character::operator=(const Character &c){
	hitPoints = c.hitPoints;
	level = c.level;
	damage = c.damage;
	name = c.name;
	friendly = c.friendly;
	inventory = c.inventory;
	abilities = c.abilities;
	resistance = c.resistance;
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

short int Character::getInitiative(){
	return initiative;
}

int Character::getDamage() {
	return damage;
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

void Character::setInitiative(short int init){
	initiative = init;
}

void Character::setDamage(int dmg) {
	damage = dmg;
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