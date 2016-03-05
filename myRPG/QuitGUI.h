#pragma once
#include "GUI.h"

class QuitGUI : public GUI
{
public:
	QuitGUI();
	~QuitGUI();

	std::shared_ptr<GUI> handleInput(World& world, int input) override;
	void enter(World& world) override;
};

