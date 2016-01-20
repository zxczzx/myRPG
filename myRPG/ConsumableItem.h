#pragma once
#include "UsableItem.h"

class ConsumableItem : public UsableItem
{
public:
	ConsumableItem();
	~ConsumableItem();

	void use(Player& player) override;
	void unuse(Player& player) override;
};

