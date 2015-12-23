#include "BattleGUI.h"


BattleGUI::BattleGUI(){
}


BattleGUI::~BattleGUI(){
}

bool BattleGUI::interaction(int action, std::shared_ptr<GUI>& nextGUI){
	switch (action){
	case 1:
	{
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
	default:
		return true;
	}
}

void BattleGUI::printScreen(){
	std::cout << "1. BattleGUI" << std::endl;
}