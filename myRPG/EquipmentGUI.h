#pragma once
#include "GUI.h"

class EquipmentGUI : public GUI
{
public:
	EquipmentGUI();
	~EquipmentGUI();

	std::shared_ptr<GUI> handleInput(World& world, int input) override;
	void enter(World& world) override;

	void takeOffItem(World& world, ItemSlot slot);
};

