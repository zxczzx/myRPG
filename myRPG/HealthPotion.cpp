#include "HealthPotion.h"

HealthPotion::HealthPotion(int count){
	name = "Health potion";
	description = "Red mixture that makes you fly. Heals for 10 hp";
	quantity = count;
	maxDurability = 1;
	durability = 1;
	itemSlot = ItemSlot::POTIONS;
	requirements = std::make_shared<Requirements>();
	requirements->level = 2;
}

HealthPotion::~HealthPotion(){
}