#pragma once
#include "GUI.h"

class SaveGameGUI : public GUI
{
private:
	void saveGame(Game& game, std::string name);

public:
	SaveGameGUI();
	~SaveGameGUI();

	std::shared_ptr<GUI> handleInput(Game& game, int input) override;
	void enter(Game& game) override;
};

