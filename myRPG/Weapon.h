#pragma once
#include "UsableItem.h"

class Weapon : public UsableItem
{
protected:
	int attackValue;

public:
	Weapon();
	~Weapon();

	void use(Player& player) override;
	void unuse(Player& player) override;
	int getAttackValue();
};

