#pragma once
#include "GUI.h"

class LoadGameGUI : public GUI
{
private:
	void loadGame(World& world, std::string filename);

public:
	LoadGameGUI();
	~LoadGameGUI();

	std::shared_ptr<GUI> handleInput(World& world, int input) override;
	void enter(World& world) override;
};

