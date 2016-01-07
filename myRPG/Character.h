#pragma once
#include "libraries.h"
#include "Inventory.h"
#include "Abilities.h"
#include "Resistance.h"

class Character
{
protected:
	int hitPoints;
	int mana;
	int level;
	short int initiative;
	int damage;
	int armor;
	std::string name;
	bool friendly;
	std::shared_ptr<Inventory> inventory;
	std::shared_ptr<Abilities> abilities;
	std::shared_ptr<Resistance> resistance;

public:
	Character();
	~Character();

	void operator=(const Character &c);

	//methods
	void attack();
	void death();

	//getter
	int getHitPoints();
	int getMana();
	int getLevel();
	short int getInitiative();
	int getDamage();
	std::string getName();
	bool getFriendly();
	std::shared_ptr<Inventory> getInventory();
	std::shared_ptr<Abilities> getAbilities();
	
	//setter
	void setHitPoints(int hp);
	void setMana(int mp);
	void setLevel(int level);
	void setInitiative(short int init);
	void setDamage(int dmg);
	void setName(std::string myName);
	void setFriedly(bool ff);
	void setInventory(std::shared_ptr<Inventory> inv);
	void setAbilities(std::shared_ptr<Abilities> myAbilities);
};

