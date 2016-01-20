#include "Mage.h"

Mage::Mage(){
	classType = "Mage";
	maxHitPoints = 20;
	hitPoints = maxHitPoints;
	damage = 2;
	maxMana = 20;
	mana = maxMana;

	setRealValues();
}

Mage::~Mage(){
}

void Mage::statsGrowth(){
	maxHitPoints += 2 * level;
	maxMana += 4 * level;
	damage += level;
	setRealValues();
}