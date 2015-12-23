#include "MenuGUI.h"

MenuGUI::MenuGUI(){
}

MenuGUI::~MenuGUI(){
}

bool MenuGUI::interaction(int action, std::shared_ptr<GUI>& nextGUI){
	switch (action){
	case 1:
	{
		nextGUI = std::make_unique<StoryGUI>();
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

void MenuGUI::printScreen(){
	std::cout << "1. Start game" << std::endl;
	std::cout << "2. Load Game" << std::endl;
	std::cout << "3. Options" << std::endl;
	std::cout << "4. Exit" << std::endl;
}