#include "Mage.h"
#include "FireBolt.h"
#include "ObjectSpawn.h"

Mage::Mage(){
	classType = "Mage";
	maxHitPoints = 20;
	hitPoints = maxHitPoints;
	damage = 2;
	maxMana = 20;
	mana = maxMana;

	std::shared_ptr<ObjectSpawn> spawner = std::make_shared<ObjectSpawn>();
	abilities->appendToBackpack(spawner->spawnAbility("Fire bolt", 1));

	setRealValues();
}

Mage::~Mage(){
}

void Mage::statsGrowth(){
	maxHitPoints += 2 * level;
	maxMana += 4 * level;
	damage += level;
	setRealValues();
}