#pragma once
#include "GUI.h"

class SpellsGUI : public GUI
{
public:
	SpellsGUI();
	~SpellsGUI();

	std::shared_ptr<GUI> handleInput(Game& game, int input) override;
	void enter(Game& game) override;
};

