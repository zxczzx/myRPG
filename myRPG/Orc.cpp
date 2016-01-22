#include "Orc.h"
#include "Money.h"

Orc::Orc()
{
	name = "Orc";
	level = 1;
	hitPoints = 5;
	mana = 0;
	damage = 1;

	//set up loot
	loot = std::make_shared<Loot>();
	loot->expReward = 5;
	std::shared_ptr<Inventory> gold = std::make_shared<Money>(2);
	loot->items.push_back(gold);

	setRealValues();
}

Orc::~Orc()
{
}
