#pragma once
#include "GUI.h"

class BackpackGUI : public GUI
{
public:
	BackpackGUI();
	~BackpackGUI();

	std::shared_ptr<GUI> handleInput(World& world, int input) override;
	void enter(World& world) override;
	
	void itemAction(World& world, std::shared_ptr<Inventory> item, int input);
};

