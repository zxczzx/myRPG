#pragma once
#include "GUI.h"
#include "StoryGUI.h"

class MenuGUI : public GUI
{
private:
	bool interaction(int action, std::shared_ptr<GUI>& nextGUI) override;
	void printScreen() override;

public:
	MenuGUI();
	~MenuGUI();
};

