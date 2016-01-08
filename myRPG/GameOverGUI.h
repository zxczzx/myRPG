#pragma once
#include "GUI.h"

class GameOverGUI : public GUI
{
public:
	GameOverGUI();
	~GameOverGUI();

	std::shared_ptr<GUI> handleInput(Game& game, int input) override;
	void enter(Game& game) override;
};

