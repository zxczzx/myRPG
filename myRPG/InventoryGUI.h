#pragma once
#include "GUI.h"
class InventoryGUI : public GUI
{
private:
	bool interaction(int action, std::shared_ptr<GUI>& nextGUI) override;
	void printScreen() override;

public:
	InventoryGUI();
	~InventoryGUI();
};

