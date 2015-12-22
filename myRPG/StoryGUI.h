#pragma once
#include "GUI.h"
class StoryGUI : public GUI
{
private:
	void interaction(int action) override;
	void printScreen() override;

public:
	StoryGUI();
	~StoryGUI();
};

