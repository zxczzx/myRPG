#include "Abilities.h"
#include "Character.h"

Abilities::Abilities(){
	usable = false;
	requirements = std::make_shared<Requirements>();
}

Abilities::~Abilities(){
}

void Abilities::execute(std::shared_ptr<Character> target){
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