#pragma once
#include "GUI.h"
#include "StoryGUI.h"

class MenuGUI : public GUI
{
private:
	//interation returns object->action
	void interaction(int action) override;
	void printScreen() override;

public:
	MenuGUI();
	~MenuGUI();
};

