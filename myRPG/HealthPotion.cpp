#include "HealthPotion.h"

HealthPotion::HealthPotion(){
	name = "Health potion";
	description = "Red mixture that makes you fly";
	quantity = 1;
	maxDurability = 1;
	durability = 1;
	itemSlot = ItemSlot::POTIONS;
	requirements = std::make_shared<Requirements>(2);
}

HealthPotion::~HealthPotion(){
}
