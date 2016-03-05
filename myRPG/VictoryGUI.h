#pragma once
#include "GUI.h"

class VictoryGUI : public GUI
{
public:
	VictoryGUI();
	~VictoryGUI();

	std::shared_ptr<GUI> handleInput(World& world, int input) override;
	void enter(World& world) override;
};

