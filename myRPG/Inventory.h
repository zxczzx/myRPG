#pragma once
#include "libraries.h"
//#include "UsableItem.h"

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

	//std::shared_ptr<UsableItem> usableItem;

	//getters
	void showDescription();
	std::string getName();
	int getQuantity();
	bool isUsable();
	//setters
	void setQuantity(int count);
	void setName(std::string value);
	void setDescription(std::string value);
	void setUsable(bool flag);
};

