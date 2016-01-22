#pragma once
#include "UsableItem.h"

class HealthPotion : public UsableItem
{
public:
	HealthPotion(int count);
	~HealthPotion();

	void use(Player& player) override;
};

