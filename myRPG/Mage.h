#pragma once
#include "Player.h"
class Mage : public Player
{
private:
	void statsGrowth() override;

public:
	Mage();
	~Mage();
};

