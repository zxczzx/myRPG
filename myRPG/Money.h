#pragma once
#include "Inventory.h"

class Money : public Inventory
{
public:
	Money(int count);
	~Money();
};

