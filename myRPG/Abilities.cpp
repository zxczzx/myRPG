#include "Abilities.h"
#include "Character.h"
#include <windows.h>

Abilities::Abilities(){
	name = "default";
	usable = false;
	requirements = std::make_shared<Requirements>();
}

Abilities::~Abilities(){
}

bool Abilities::execute(std::shared_ptr<Character> self, std::shared_ptr<Character> target){
	if (self->getMana() > manaConsumprion){
		self->setMana(self->getMana() - manaConsumprion);
		if (target->getHitPoints() - this->damage > target->getMaxHitPoints())
			target->setHitPoints(target->getMaxHitPoints());
		else
			target->setHitPoints(target->getHitPoints() - this->damage);
		std::cout << this->name << " " << useString << " " << target->getName() << " for " << std::abs(this->damage) << " dmg" << std::endl;
		Sleep(2000);
		return true;
	}
	else{
		std::cout << "You have not enough mana!" << std::endl;
		return false;
	}
}

bool Abilities::isUsable(){
	return usable;
}

int Abilities::getQuantity(){
	return quantity;
}

std::string Abilities::getName(){
	return name;
}

std::string Abilities::getDescription(){
	return description;
}

int Abilities::getDamage(){
	return damage;
}

int Abilities::getManaConsumption(){
	return manaConsumprion;
}

std::shared_ptr<Requirements> Abilities::getRequireents(){
	return requirements;
}

void Abilities::setQuantity(int count){
	quantity = count;
}

void Abilities::setDescription(std::string value){
	description = value;
}

void Abilities::setName(std::string value){
	name = value;
}

void Abilities::setUseString(std::string value){
	useString = value;
}

void Abilities::setDamage(int value){
	damage = value;
}

void Abilities::setManaConsumption(int value){
	manaConsumprion = value;
}

void Abilities::setRequirements(std::shared_ptr<Requirements> obj){
	requirements = obj;
}

void Abilities::setThisObj(std::shared_ptr<Abilities> me){
	thisObj = me;
}