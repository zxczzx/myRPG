#pragma once
#include "GUI.h"
class BattleGUI : public GUI
{
public:
	BattleGUI();
	~BattleGUI();

	std::shared_ptr<GUI> handleInput(Game& game, int input) override;
	void enter(Game& game) override;
};

