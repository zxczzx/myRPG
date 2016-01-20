#pragma once
#include "GUI.h"

class SpecialAbilitiesGUI : public GUI
{
public:
	SpecialAbilitiesGUI();
	~SpecialAbilitiesGUI();

	std::shared_ptr<GUI> handleInput(Game& game, int input) override;
	void enter(Game& game) override;
};

