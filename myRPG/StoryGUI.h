#pragma once
#include "GUI.h"

class StoryGUI : public GUI
{
public:
	StoryGUI();
	~StoryGUI();

	std::shared_ptr<GUI> handleInput(World& world, int input) override;
	void enter(World& world) override;
};

