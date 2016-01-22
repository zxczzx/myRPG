#include "Inventory.h"

Inventory::Inventory(){
	name = "default";
	description = "Some item";
	quantity = 1;
	usable = false;
}

Inventory::~Inventory(){
}

void Inventory::showDescription(){
	std::cout << description << std::endl;
}

std::string Inventory::getName(){
	return name;
}

bool Inventory::isUsable(){
	return usable;
}

int Inventory::getQuantity(){
	return quantity;
}

void Inventory::setQuantity(int count){
	quantity = count;
}