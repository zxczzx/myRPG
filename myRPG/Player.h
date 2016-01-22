#pragma once
#include "Character.h"
#include "Backpack.h"

class Player : public Character
{
	friend class LoadGameGUI;
protected:
	//pair { level, experience }
	static std::map<int, int> lvlMap;
	int experience;
	std::string classType;
	std::shared_ptr<Backpack> backpack;

	virtual void statsGrowth();
	bool isLvlUp();

public:
	Player();
	~Player();
	std::map<ItemSlot, std::shared_ptr<UsableItem> > BodySlots;

	//methods
	void useItem(std::shared_ptr<UsableItem> item);
	void takeOffItem(std::shared_ptr<UsableItem> item);
	void useAbility(std::shared_ptr<Abilities> ability);

	//getter
	int getExperience();
	std::string getClassType();
	std::map<int, int> getLvLMap();
	std::shared_ptr<Backpack> getBackpack();
	//setter
	void setExperience(int exp);
	void setClassType(std::string myClassType);
};

