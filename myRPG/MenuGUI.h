#pragma once
#include "GUI.h"

class MenuGUI : public GUI
{
public:
	MenuGUI();
	~MenuGUI();

	std::shared_ptr<GUI> handleInput(World& world, int input) override;
	void enter(World& world) override;
};

