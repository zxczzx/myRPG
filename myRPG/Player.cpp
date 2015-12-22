#include "Player.h"

Player::Player(){
	std::cout << "Player created " << std::endl;
	experience = 0;
}


Player::~Player(){
}

//GETTERS

int Player::getExperience(){
	return experience;
}

//SETTERS

void Player::setExperience(int exp){
	experience = exp;
}

//METHODS

void Player::useAbility(std::shared_ptr<Abilities> ability){
	std::cout << "Player used ability " << ability << std::endl;
}

void Player::useItem(std::shared_ptr<Inventory> item){
	std::cout << "Player used item " << item << std::endl;
}