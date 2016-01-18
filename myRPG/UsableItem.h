#pragma once
#include "Inventory.h"
#include "Requirements.h"
#include "ItemSlot.h"
#include "Player.h"

class UsableItem : public Inventory
{
protected:
	int maxDurability;
	int durability;
	ItemSlot itemSlot;
	std::shared_ptr<Requirements> requirements;

public:
	UsableItem();
	~UsableItem();

	virtual void use(std::shared_ptr<Player> player) = 0;

	ItemSlot getItemSlot();
};

