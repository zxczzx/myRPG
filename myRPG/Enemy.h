#pragma once
#include "Character.h"
#include "libraries.h"

class Enemy :
	public Character
{
	int rewardExperience;
public:
	Enemy();
	~Enemy();

	//getter
	int getRewardExperience;
	//setter
	void setRewardExperience(int exp);
};

