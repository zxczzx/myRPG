#pragma once
#include "libraries.h"

class Character;

class Abilities
{
	std::string name;
	std::string description;
	int quantity;
	std::shared_ptr<Abilities> thisObj;
	bool usable;	// so I can use it with Backpack container

public:
	Abilities();
	~Abilities();

	virtual void execute(std::shared_ptr<Character> target);

	template<class T>
	std::shared_ptr<Abilities> createAbility();

	std::string getName();
	int getQuantity();
	bool isUsable();

	void setQuantity(int count);
};


template<class T>
std::shared_ptr<Abilities> Abilities::createAbility(){
	std::shared_ptr<Abilities> ability = std::make_shared<T>();
	ability->thisObj = ability;
	return ability;
}