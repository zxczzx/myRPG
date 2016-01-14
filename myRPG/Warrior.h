#pragma once
#include "Player.h"
class Warrior : public Player
{
private:
	void statsGrowth() override;

public:
	Warrior();
	~Warrior();
};

