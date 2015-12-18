#pragma once
#include "Character.h"
#include <memory>

class Player :
	public Character
{
protected:
	int experience;

public:
	Player();
	~Player();

	//methods
	void useItem(std::shared_ptr<Inventory> item);
	void useAbility(std::shared_ptr<Abilities> ability);

	//getter
	int getExperience();
	//setter
	void setExperience(int exp);
};

