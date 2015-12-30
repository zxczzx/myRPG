#pragma once
#include "GUI.h"

class StoryGUI : public GUI
{
public:
	StoryGUI();
	~StoryGUI();

	std::shared_ptr<GUI> handleInput(Game& game, int input) override;
	void enter(Game& game) override;
};

