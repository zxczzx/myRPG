#include "Enemy.h"

Enemy::Enemy(){
	loot = nullptr;
	friendly = false;
}

Enemy::~Enemy(){
}

//GETTERS

std::shared_ptr<Loot> Enemy::getLoot(){
	return loot;
}

//SETTERS

void Enemy::setLoot(std::shared_ptr<Loot> myLoot){
	loot = myLoot;
}

//METHODS