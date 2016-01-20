#pragma once
#include "GUI.h"

class EquipmentGUI : public GUI
{
public:
	EquipmentGUI();
	~EquipmentGUI();

	std::shared_ptr<GUI> handleInput(Game& game, int input) override;
	void enter(Game& game) override;
};

