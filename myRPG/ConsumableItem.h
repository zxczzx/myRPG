#pragma once
#include "UsableItem.h"

class ConsumableItem : public UsableItem
{
public:
	ConsumableItem();
	~ConsumableItem();

	void use(std::shared_ptr<Player> player) override;
};

