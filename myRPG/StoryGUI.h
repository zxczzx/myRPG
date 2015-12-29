#pragma once
#include "GUI.h"
#include "BattleGUI.h"
#include "MenuGUI.h"

class StoryGUI : public GUI
{
private:
	bool interaction(int action, std::shared_ptr<GUI>& nextGUI) override;
	void printScreen() override;

public:
	StoryGUI();
	~StoryGUI();
};

