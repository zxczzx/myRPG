#pragma once
#include "Character.h"
#include "libraries.h"
#include "Loot.h"

class Enemy : public Character
{
protected:
	std::shared_ptr<Loot> loot;

public:
	Enemy();
	~Enemy();

	//getter
	std::shared_ptr<Loot> getLoot();
	//setter
	void setLoot(std::shared_ptr<Loot> myLoot);
};

