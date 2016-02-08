#include "FireBolt.h"

FireBolt::FireBolt(){
	name = "Fire bolt";
	description = "Small but deadly fire missle";
	useString = "burned";
	damage = 4;
	manaConsumprion = 4;
	quantity = 1;
	requirements->classType = {"Mage"};
	requirements->level = 1;
}

FireBolt::~FireBolt(){
}
