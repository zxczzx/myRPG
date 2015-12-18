#pragma once
#include "libraries.h"
#include "Inventory.h"
#include "Abilities.h"

class Character
{
protected:
	int hitPoints;
	int mana;
	int level;
	std::string name;
	bool friendly;
	std::shared_ptr<Inventory> inventory;
	std::shared_ptr<Abilities> abilities;

public:
	Character();
	~Character();
	//methods
	void attack();
	void death();

	//getter
	int getHitPoints();
	int getMana();
	int getLevel();
	std::string getName();
	bool getFriendly();
	std::shared_ptr<Inventory> getInventory();
	std::shared_ptr<Abilities> getAbilities();
	
	//setter
	void setHitPoints(int hp);
	void setMana(int mp);
	void setLevel(int level);
	void setName(std::string myName);
	void setFriedly(bool ff);
	void setInventory(std::shared_ptr<Inventory> inv);
	void setAbilities(std::shared_ptr<Abilities> myAbilities);
};

