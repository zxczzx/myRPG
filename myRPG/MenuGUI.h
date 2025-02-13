#pragma once
#include "GUI.h"

class MenuGUI : public GUI
{
public:
	MenuGUI();
	~MenuGUI();

	std::shared_ptr<GUI> handleInput(Game& game, int input) override;
	void enter(Game& game) override;
};

