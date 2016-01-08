#include "Warrior.h"


Warrior::Warrior() : Player(){
	classType = "Warrior";
	hitPoints *= 2 * level;
	damage = 2+2*level;
	mana = 3+2*level;
}


Warrior::~Warrior(){
}
