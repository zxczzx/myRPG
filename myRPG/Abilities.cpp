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
		target->setHitPoints(target->getHitPoints() - this->damage);
		std::cout << this->name << " " << useString << " " << target->getName() << " for " << this->damage << " dmg" << std::endl;
		Sleep(2000);
		return true;
	}
	else{
		std::cout << "You have not enough mana!" << std::endl;
		return false;
	}
}

void Abilities::setQuantity(int count){
	quantity = count;
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