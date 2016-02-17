#pragma once
#include "Character.h"

class Actor : public Character
{
	friend class LoadGameGUI;
protected:
	//pair { level, experience }
	static std::map<int, int> lvlMap;
	int experience;
	std::string classType;
	std::shared_ptr<Backpack<Inventory> > backpack;
	std::shared_ptr<Actor> thisObj;

	virtual void statsGrowth();
	bool isLvlUp();

public:
	Actor();
	~Actor();
	std::map<ItemSlot, std::shared_ptr<Inventory> > BodySlots;

	//methods
	void useItem(std::shared_ptr<Inventory> item);
	void takeOffItem(std::shared_ptr<Inventory> item);
	void useAbility(std::shared_ptr<Abilities> ability);

	//getter
	int getExperience();
	std::string getClassType();
	std::map<int, int> getLvLMap();
	std::shared_ptr<Backpack<Inventory> > getBackpack();
	//setter
	void setExperience(int exp);
	void setClassType(std::string myClassType);
	void setThisObj(std::shared_ptr<Actor> me);

	template<class T>
	static std::shared_ptr<Actor> createActor();
};

template<class T>
std::shared_ptr<Actor> Actor::createActor(){
	std::shared_ptr<Actor> actor = std::make_shared<T>();
	actor->thisObj = actor;
	return actor;
}