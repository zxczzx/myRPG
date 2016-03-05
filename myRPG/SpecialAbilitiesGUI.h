#pragma once
#include "GUI.h"

class SpecialAbilitiesGUI : public GUI
{
public:
	SpecialAbilitiesGUI();
	~SpecialAbilitiesGUI();

	std::shared_ptr<GUI> handleInput(World& world, int input) override;
	void enter(World& world) override;
};

