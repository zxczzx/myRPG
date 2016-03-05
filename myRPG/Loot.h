#pragma once
#include "libraries.h"
#include "Inventory.h"

class Loot
{
public:
	Loot();
	~Loot();

	int expReward;
	std::vector<std::shared_ptr<Inventory> > items;
};

