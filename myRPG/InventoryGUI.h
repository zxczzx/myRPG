#pragma once
#include "GUI.h"
class InventoryGUI : public GUI
{
public:
	InventoryGUI();
	~InventoryGUI();

	std::shared_ptr<GUI> handleInput(Game& game, int input) override;
	void enter(Game& game) override;
};

