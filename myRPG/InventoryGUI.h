#pragma once
#include "GUI.h"
class InventoryGUI : public GUI
{
private:
	void interaction(int action) override;
	void printScreen() override;

public:
	InventoryGUI();
	~InventoryGUI();
};

