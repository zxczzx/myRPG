#pragma once
#include "Character.h"
#include "libraries.h"

class Player : public Character
{
protected:
	//pair { level, experience }
	static std::map<int, int> lvlMap;

	int experience;
	std::string classType;

	virtual void statsGrowth();
	bool isLvlUp();
	void evaluate();

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
	std::map<int, int> getLvLMap();
	//setter
	void setExperience(int exp);
	void setClassType(std::string myClassType);
};

