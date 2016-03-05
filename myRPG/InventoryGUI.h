#pragma once
#include "GUI.h"
class InventoryGUI : public GUI
{
public:
	InventoryGUI();
	~InventoryGUI();

	std::shared_ptr<GUI> handleInput(World& world, int input) override;
	void enter(World& world) override;
};

