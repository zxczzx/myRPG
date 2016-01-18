#pragma once
#include "UsableItem.h"

class Armor : public UsableItem
{
protected:
	int armorValue;
	int durability;

public:
	Armor();
	~Armor();

	void use(std::shared_ptr<Player> player) override;
};

