#include "Axe.h"

Axe::Axe(){
	name = "Axe";
	description = "Regular poor quality axe";
	quantity = 1;
	attackValue = 1;
	maxDurability = 10;
	durability = 10;
	itemSlot = ItemSlot::MAIN_HAND;
	requirements = std::make_shared<Requirements>();
	requirements->level = 1;
}

Axe::~Axe(){
}
