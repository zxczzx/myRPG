#pragma once
#include "PlayerWindows.h"

class InventoryWindow : public PlayerWindows
{
public:
	InventoryWindow(World* world);
	~InventoryWindow();

	void handleInput(sf::Event event) override;

private:
	std::vector<std::shared_ptr<Inventory>> items;

	void removeItem(World* world);
	void update(World* world);
};

