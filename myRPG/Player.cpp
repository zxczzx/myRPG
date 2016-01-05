#include "Player.h"

Player::Player() : Character() {
	std::cout << "Player created " << std::endl;
	hitPoints = 20;
	level = 1;
	damage = 1;
	name = "default";
	classType = "default";
	friendly = true;
	inventory = std::make_shared<Inventory>();
	abilities = std::make_shared<Abilities>();
	resistance = std::make_shared<Resistance>();
}


Player::~Player(){
}

void Player::operator=(const Player &c){
	hitPoints = c.hitPoints;
	level = c.level;
	damage = c.damage;
	name = c.name;
	classType = c.classType;
	friendly = c.friendly;
	inventory = c.inventory;
	abilities = c.abilities;
	resistance = c.resistance;
}

//GETTERS

int Player::getExperience(){
	return experience;
}

std::string Player::getClassType(){
	return classType;
}

//SETTERS

void Player::setExperience(int exp){
	experience = exp;
}

void Player::setClassType(std::string myClassType){
	classType = myClassType;
}

//METHODS

void Player::useAbility(std::shared_ptr<Abilities> ability){
	std::cout << "Player used ability " << ability << std::endl;
}

void Player::useItem(std::shared_ptr<Inventory> item){
	std::cout << "Player used item " << item << std::endl;
}