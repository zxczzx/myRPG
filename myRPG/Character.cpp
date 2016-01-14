#include <windows.h>
#include "Character.h"

Character::Character(){
	maxHitPoints = 0;
	hitPoints = 0;
	maxMana = 0;
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

//METHODS

void Character::attack(std::shared_ptr<Character> enemy){
	enemy->setHitPoints(enemy->getHitPoints() - this->damage);
	std::cout << this->name << " attacked " << enemy->getName() << " for " << this->damage << " dmg" << std::endl;
	Sleep(2000);
}

void Character::death(){
	std::cout << "Character is dead" << std::endl;
}

bool Character::isDead(){
	return hitPoints > 0 ? false : true;
}

//GETTERS

int Character::getHitPoints(){
	return hitPoints;
}

int Character::getMaxHitPoints(){
	return maxHitPoints;
}

int Character::getMana(){
	return mana;
}

int Character::getMaxMana(){
	return maxMana;
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

void Character::setMaxHitPoints(int hp){
	maxHitPoints = hp;
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

void Character::setMaxMana(int mp){
	maxMana = mp;
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