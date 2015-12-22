#pragma once
#include "GUI.h"
class BattleGUI : public GUI
{
private:
	void interaction(int action) override;
	void printScreen() override;

public:
	BattleGUI();
	~BattleGUI();
};

