#pragma once
#include "GUI.h"

class SpellsGUI : public GUI
{
public:
	SpellsGUI();
	~SpellsGUI();

	std::shared_ptr<GUI> handleInput(World& world, int input) override;
	void enter(World& world) override;
	void spellAction(World& world, std::shared_ptr<Abilities> item);
};

