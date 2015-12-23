#pragma once
#include "GUI.h"
class BattleGUI : public GUI
{
private:
	bool interaction(int action, std::shared_ptr<GUI>& nextGUI) override;
	void printScreen() override;

public:
	BattleGUI();
	~BattleGUI();
};

