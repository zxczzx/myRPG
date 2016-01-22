#pragma once
#include "libraries.h"
#include "Inventory.h"

class Backpack
{
	std::vector < std::shared_ptr<Inventory> > items;

public:
	Backpack();
	~Backpack();

	void appendToBackpack(std::shared_ptr<Inventory> item);
	void removeFromBackpack(std::shared_ptr<Inventory> item);
	std::vector<std::shared_ptr<Inventory> > getItems();
};

