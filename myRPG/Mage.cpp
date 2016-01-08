#include "Mage.h"

Mage::Mage(){
	classType = "Mage";
	hitPoints += 4 * level;
	damage = 2 + level;
	mana = 20*level;
}

Mage::~Mage(){
}
