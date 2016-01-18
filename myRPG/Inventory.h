#pragma once
#include "libraries.h"

class Inventory
{
protected:
	std::string name;
	std::string description;
	unsigned quantity;

public:
	Inventory();
	~Inventory();

	void showDescription();
};

