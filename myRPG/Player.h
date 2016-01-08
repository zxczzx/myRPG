#pragma once
#include "Character.h"
#include "libraries.h"

class Player : public Character
{
protected:
	int experience;
	std::string classType;

	bool isLvlUp();

public:
	Player();
	~Player();

	void Player::operator=(const Player &c);

	//methods
	void useItem(std::shared_ptr<Inventory> item);
	void useAbility(std::shared_ptr<Abilities> ability);

	//getter
	int getExperience();
	std::string getClassType();
	//setter
	void setExperience(int exp);
	void setClassType(std::string myClassType);
};

