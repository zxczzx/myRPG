#pragma once
#include "libraries.h"

class Inventory
{
protected:
	std::string name;
	std::string description;
	unsigned quantity;
	bool usable;

public:
	Inventory();
	~Inventory();

	void showDescription();
	std::string getName();
	bool isUsable();
};

