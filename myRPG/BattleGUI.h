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

	std::shared_ptr<GUI> handleInput(World& world, int input) override;
	void enter(World& world) override;
};

