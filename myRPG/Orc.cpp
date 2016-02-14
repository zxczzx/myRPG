#include "Orc.h"
#include "Inventory.h"
#include "ObjectSpawn.h"

Orc::Orc()
{
	name = "Orc";
	level = 1;
	hitPoints = 5;
	mana = 0;
	damage = 1;

	//set up loot
	loot = std::make_shared<Loot>();
	std::shared_ptr<ObjectSpawn> spawner = std::make_shared<ObjectSpawn>();
	loot->expReward = 5;
	std::shared_ptr<Inventory> gold = spawner->spawnItem("Money", 2);
	loot->items.push_back(gold);

	setRealValues();
}

Orc::~Orc()
{
}
