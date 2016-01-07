#pragma once
#include "Character.h"
#include "libraries.h"
#include "Inventory.h"

class Enemy : public Character
{
protected:
	int rewardExperience;
	int rewardGold;
	std::vector<Inventory> loot;

public:
	Enemy();
	~Enemy();

	//getter
	int getRewardExperience();
	//setter
	void setRewardExperience(int exp);
};

