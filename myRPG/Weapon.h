#pragma once
#include "UsableItem.h"

class Weapon : public UsableItem
{
public:
	Weapon();
	~Weapon();

	void use(Player& player) override;
	void unuse(Player& player) override;
	
};

