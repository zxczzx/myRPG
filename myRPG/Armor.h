#pragma once
#include "UsableItem.h"

class Armor : public UsableItem
{
public:
	Armor();
	~Armor();

	void use(Player& player) override;
	void unuse(Player& player) override;
};

