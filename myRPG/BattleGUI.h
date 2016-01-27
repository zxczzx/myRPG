#pragma once
#include "GUI.h"
class BattleGUI : public GUI
{
private:
	bool usedPrev;

public:
	BattleGUI();
	~BattleGUI();
	std::shared_ptr<Abilities> chosenSpell;

	std::shared_ptr<GUI> handleInput(Game& game, int input) override;
	void enter(Game& game) override;
};

