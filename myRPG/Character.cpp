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
	abilities = std::make_shared<Backpack<Abilities> >();
	setRealValues();
}

Character::~Character(){
}

//METHODS

void Character::attack(std::shared_ptr<Character> enemy){
	enemy->setHitPoints(enemy->getHitPoints() - this->realDamage);
	std::cout << this->name << " attacked " << enemy->getName() << " for " << this->realDamage << " dmg" << std::endl;
	Sleep(2000);
}

void Character::death(){
	std::cout << "Character is dead" << std::endl;
}

bool Character::isDead(){
	return hitPoints > 0 ? false : true;
}

void Character::setRealValues(){
	realArmor = armor;
	realDamage = damage;
	realMana = maxMana;
	realHitPoints = maxHitPoints;
	realInitiative = initiative;
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

std::shared_ptr<Resistance> Character::getResistance(){
	return resistance;
}

std::shared_ptr<Backpack<Abilities> > Character::getAbilitiesBackpack(){
	return abilities;
}

int Character::getHpGrowth(){
	return hpGrowth;
}

int Character::getMpGrowth(){
	return mpGrowth;
}

int Character::getDmgGrowth(){
	return dmgGrowth;
}

int Character::getRealArmor(){
	return realArmor;
}

int Character::getRealDamage(){
	return realDamage;
}

int Character::getRealMana(){
	return realMana;
}

int Character::getRealHitPoints(){
	return realHitPoints;
}

int Character::getRealInitiative(){
	return realInitiative;
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

void Character::setResistance(std::shared_ptr<Resistance> res){
	resistance = res;
}

void Character::setAbilities(std::shared_ptr<Abilities> myAbilities){
	abilities->appendToBackpack(myAbilities);
}

void Character::setArmor(int value){
	armor = value;
}

void Character::setHpGrowth(int value){
	hpGrowth = value;
}

void Character::setMpGrowth(int value){
	mpGrowth = value;
}

void Character::setDmgGrowth(int value){
	dmgGrowth = value;
}

void Character::setRealArmor(int realarmor){
	realArmor = realarmor;
}

void Character::setRealDamage(int realdamage){
	realDamage = realdamage;
}

void Character::setRealMana(int realmana){
	realMana = realmana;
}

void Character::setRealHitPoints(int realhp){
	realHitPoints = realhp;
}

void Character::setRealInitiative(int realinitiative){
	realInitiative = realinitiative;
}