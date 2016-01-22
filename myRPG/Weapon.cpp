#include "Weapon.h"
#include "Player.h"

Weapon::Weapon(){
}

Weapon::~Weapon(){
}

int Weapon::getAttackValue(){
	return attackValue;
}

void Weapon::use(Player& player){
	if (itemSlot == ItemSlot::BOTH_HANDS){
		player.BodySlots[ItemSlot::MAIN_HAND] = thisObj;
		player.BodySlots[ItemSlot::OFFHAND] = thisObj;
	}
	else{
		player.BodySlots[ItemSlot::MAIN_HAND] = thisObj;
	}
	player.setRealDamage(player.getRealDamage() + attackValue);
	player.getBackpack()->removeFromBackpack(thisObj);
}

void Weapon::unuse(Player& player){
	if (itemSlot == ItemSlot::BOTH_HANDS){
		player.BodySlots[ItemSlot::MAIN_HAND] = nullptr;
		player.BodySlots[ItemSlot::OFFHAND] = nullptr;
	}
	else{
		player.BodySlots[ItemSlot::MAIN_HAND] = nullptr;
	}
	player.setRealDamage(player.getRealDamage() - attackValue);
}