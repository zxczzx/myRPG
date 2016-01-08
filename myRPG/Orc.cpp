#include "Orc.h"


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
	loot->goldReward = 1;
	loot->items = {};
}

Orc::~Orc()
{
}
