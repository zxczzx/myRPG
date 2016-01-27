#include "HealthPotion.h"
#include "Player.h"

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

void HealthPotion::use(Player& player){
	player.setHitPoints(player.getHitPoints() + 10);
	if (player.getHitPoints() > player.getMaxHitPoints()){
		player.setHitPoints(player.getMaxHitPoints());
	}
	quantity--;
	if (quantity < 1){
		player.getBackpack()->removeFromBackpack(thisObj);
	}
}
