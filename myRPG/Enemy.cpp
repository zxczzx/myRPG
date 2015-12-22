#include "Enemy.h"

Enemy::Enemy(){
	rewardExperience = 0;
}

Enemy::~Enemy(){
}

//GETTERS

int Enemy::getRewardExperience(){
	return rewardExperience;
}

//SETTERS

void Enemy::setRewardExperience(int exp){
	rewardExperience = exp;
}

//METHODS