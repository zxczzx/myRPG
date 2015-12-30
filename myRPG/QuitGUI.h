#pragma once
#include "GUI.h"

class QuitGUI : public GUI
{
public:
	QuitGUI();
	~QuitGUI();

	std::shared_ptr<GUI> handleInput(Game& game, int input) override;
	void enter(Game& game) override;
};

