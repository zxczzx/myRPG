#include "Weapon.h"

Weapon::Weapon(){
}

Weapon::~Weapon(){
}

int Weapon::getAttackValue(){
	return attackValue;
}

void Weapon::use(std::shared_ptr<Player> player){

}