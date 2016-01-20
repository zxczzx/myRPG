#pragma once
#include "Character.h"

class Player : public Character
{
	friend class LoadGameGUI;
protected:
	//pair { level, experience }
	static std::map<int, int> lvlMap;
	int experience;
	std::string classType;

	virtual void statsGrowth();
	bool isLvlUp();

public:
	Player();
	~Player();
	std::map<ItemSlot, std::shared_ptr<UsableItem> > BodySlots;
	void Player::operator=(const Player& c);

	//methods
	void useItem(std::shared_ptr<UsableItem> item);
	void removeItem(std::shared_ptr<Inventory> item);
	void takeOffItem(std::shared_ptr<UsableItem> item);
	void useAbility(std::shared_ptr<Abilities> ability);

	//getter
	int getExperience();
	std::string getClassType();
	std::map<int, int> getLvLMap();
	//setter
	void setExperience(int exp);
	void setClassType(std::string myClassType);
};

