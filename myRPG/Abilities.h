#pragma once
#include "libraries.h"
#include "Requirements.h"

class Character;

class Abilities
{
protected:
	std::string name;
	std::string description;
	std::string useString;
	int damage;
	int manaConsumprion;
	int quantity;
	std::shared_ptr<Requirements> requirements;
	std::shared_ptr<Abilities> thisObj;
	bool usable;	// needed so I can use it with Backpack container

public:
	Abilities();
	~Abilities();

	bool execute(std::shared_ptr<Character> self, std::shared_ptr<Character> target);

	template<class T>
	static std::shared_ptr<Abilities> createAbility();

	//getters
	std::string getName();
	int getQuantity();
	bool isUsable();
	std::string getDescription();
	int getDamage();
	int getManaConsumption();
	std::shared_ptr<Requirements> getRequireents();
	//setters
	void setQuantity(int count);
	void setDescription(std::string value);
	void setName(std::string value);
	void setUseString(std::string value);
	void setDamage(int value);
	void setManaConsumption(int value);
	void setRequirements(std::shared_ptr<Requirements> obj);
	void setThisObj(std::shared_ptr<Abilities> me);
};


template<class T>
std::shared_ptr<Abilities> Abilities::createAbility(){
	std::shared_ptr<Abilities> ability = std::make_shared<T>();
	ability->thisObj = ability;
	return ability;
}