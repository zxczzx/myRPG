#pragma once
#include "PlayerWindows.h"

class EquipmentWindow : public PlayerWindows
{
public:
	EquipmentWindow(World* world);
	~EquipmentWindow();

	void handleInput(sf::Event event) override;

private:
	void removeItem(World* world);
	void update(World* world);
};

