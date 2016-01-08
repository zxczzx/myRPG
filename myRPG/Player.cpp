#include "Player.h"

Player::Player() : Character() {
	hitPoints = 14;
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

	//check if character lvl'ed up
	if (isLvlUp()){
		setLevel(this->level + 1);
		std::cout << "You leveled up to level " << this->level << "!" << std::endl;
	}
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

bool Player::isLvlUp(){
	//pair { level, experience }
	std::map<int, int> lvlMap{
		{ 1, 5 }, { 2, 50 }, { 3, 100 }, { 4, 200 }, { 5, 400 }, { 6, 800 }, {7, 1600}, {8, 3200}, {9, 6400}, {10, 12800},
	};
	if (this->experience >= lvlMap.find(this->level)->second){
		return true;
	}
	else{
		return false;
	}
}