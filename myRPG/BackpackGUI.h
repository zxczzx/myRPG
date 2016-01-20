#pragma once
#include "GUI.h"

class BackpackGUI : public GUI
{
public:
	BackpackGUI();
	~BackpackGUI();

	std::shared_ptr<GUI> handleInput(Game& game, int input) override;
	void enter(Game& game) override;
	
	void itemAction(Game& game, std::shared_ptr<Inventory> item, int input);
};

