#include "Warrior.h"

Warrior::Warrior() : Player(){
	classType = "Warrior";
	maxHitPoints = 20;
	hitPoints = maxHitPoints;
	damage = 4;
	maxMana = 5;
	mana = maxMana;

	setRealValues();
}

Warrior::~Warrior(){
}

void Warrior::statsGrowth(){
	maxHitPoints += 4 * level;
	maxMana += 2 * level;
	damage += 2 * level;
	setRealValues();
}
