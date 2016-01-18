#pragma once
#include "UsableItem.h"

class Weapon : public UsableItem
{
protected:
	int attackValue;

public:
	Weapon();
	~Weapon();

	void use(std::shared_ptr<Player> player) override;
	int getAttackValue();
};

