#pragma once
#include "GUI.h"
class StartGameGUI : public GUI
{
public:
	StartGameGUI();
	~StartGameGUI();

	std::shared_ptr<GUI> handleInput(World& world, int input) override;
	void enter(World& world) override;
};

