#pragma once
#include "GUI.h"

class LoadGameGUI : public GUI
{
private:
	void loadGame(Game& game, std::string filename);

public:
	LoadGameGUI();
	~LoadGameGUI();

	std::shared_ptr<GUI> handleInput(Game& game, int input) override;
	void enter(Game& game) override;
};

