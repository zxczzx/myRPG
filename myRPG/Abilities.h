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

	std::string getName();
	int getQuantity();
	bool isUsable();
	std::string getDescription();
	int getDamage();
	int getManaConsumption();
	std::shared_ptr<Requirements> getRequireents();

	void setQuantity(int count);
};


template<class T>
std::shared_ptr<Abilities> Abilities::createAbility(){
	std::shared_ptr<Abilities> ability = std::make_shared<T>();
	ability->thisObj = ability;
	return ability;
}