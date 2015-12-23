#include "StoryGUI.h"


StoryGUI::StoryGUI(){
}


StoryGUI::~StoryGUI(){
}

bool StoryGUI::interaction(int action, std::shared_ptr<GUI>& nextGUI){
	switch (action){
	case 1:
	{
		//TODO clear screen
		std::shared_ptr<GUI> storyGUIptr(new BattleGUI());
		nextGUI = storyGUIptr;
		nextGUI->printScreen();
		return true;
	}
	case 2:
		return true;
	case 3:
		return true;
	case 4:
		return false;
		break;
	default:
		return true;
	}
}

void StoryGUI::printScreen(){
	std::cout << "1. Go to Battle GUI";
}