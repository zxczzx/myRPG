#pragma once
#include "GUI.h"

class VictoryGUI : public GUI
{
public:
	VictoryGUI();
	~VictoryGUI();

	std::shared_ptr<GUI> handleInput(Game& game, int input) override;
	void enter(Game& game) override;
};

