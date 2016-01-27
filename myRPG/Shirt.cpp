#include "Shirt.h"

Shirt::Shirt(){
	name = "Shirt";
	description = "Dirty peasant shirt";
	quantity = 1;
	armorValue = 1;
	maxDurability = 10;
	durability = 10;
	itemSlot = ItemSlot::BODY;
	requirements = std::make_shared<Requirements>();
	requirements->level = 1;
}

Shirt::~Shirt(){
}
