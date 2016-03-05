#pragma once
#include "libraries.h"
#include "Inventory.h"
#include "Abilities.h"
#include "Resistance.h"
#include "Backpack.h"

class Character
{
protected:
	int maxHitPoints;
	int hitPoints;
	int maxMana;
	int mana;
	int level;
	short int initiative;
	int damage;
	int armor;
	std::string name;
	bool friendly;
	std::shared_ptr<Backpack<Abilities> > abilities;
	std::shared_ptr<Resistance> resistance;

	int hpGrowth;
	int mpGrowth;
	int dmgGrowth;

	int realArmor;
	int realDamage;
	int realMana;
	int realHitPoints;
	int realInitiative;

public:
	Character();
	~Character();

	//methods
	void attack(std::shared_ptr<Character> enemy);
	void death();
	bool isDead();
	void setRealValues();

	//getter
	int getHitPoints();
	int getMaxHitPoints();
	int getMana();
	int getMaxMana();
	int getLevel();
	short int getInitiative();
	int getDamage();
	std::string getName();
	bool getFriendly();
	std::shared_ptr<Resistance> getResistance();
	std::shared_ptr<Backpack<Abilities> > getAbilitiesBackpack();

	int getHpGrowth();
	int getMpGrowth();
	int getDmgGrowth();

	int getRealArmor();
	int getRealDamage();
	int getRealMana();
	int getRealHitPoints();
	int getRealInitiative();
	
	//setter
	void setHitPoints(int hp);
	void setMaxHitPoints(int hp);
	void setMana(int mp);
	void setMaxMana(int mp);
	void setLevel(int level);
	void setInitiative(short int init);
	void setDamage(int dmg);
	void setName(std::string myName);
	void setFriedly(bool ff);
	void setResistance(std::shared_ptr<Resistance> res);
	void setAbilities(std::shared_ptr<Abilities> myAbilities);
	void setArmor(int value);

	void setHpGrowth(int value);
	void setMpGrowth(int value);
	void setDmgGrowth(int value);

	void setRealArmor(int realarmor);
	void setRealDamage(int realdamage);
	void setRealMana(int realmana);
	void setRealHitPoints(int realhp);
	void setRealInitiative(int realinitiative);
};

