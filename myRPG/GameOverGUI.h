#pragma once
#include "GUI.h"

class GameOverGUI : public GUI
{
public:
	GameOverGUI();
	~GameOverGUI();

	std::shared_ptr<GUI> handleInput(World& world, int input) override;
	void enter(World& world) override;
};

