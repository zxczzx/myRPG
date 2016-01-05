#pragma once
#include "GUI.h"
class StartGameGUI : public GUI
{
public:
	StartGameGUI();
	~StartGameGUI();

	std::shared_ptr<GUI> handleInput(Game& game, int input) override;
	void enter(Game& game) override;
};

