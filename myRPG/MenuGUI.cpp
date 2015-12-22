#include "MenuGUI.h"


MenuGUI::MenuGUI(){
}


MenuGUI::~MenuGUI(){
}

void MenuGUI::interaction(int action){
	switch (action){
	case 1:
		//clear screen
		//std::shared_ptr<GUI> a(new std::shared_ptr<StoryGUI>());
		//nextGUI = new std::shared_ptr<GUI>();
		//std::cout << "whatever";
		//nextGUI->printScreen();
		//GUI* a = new StoryGUI();
		//a->printScreen();
		//std::shared_ptr<GUI> a = new std::shared_ptr<StoryGUI>();
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	default:
		break;
	}
}

void MenuGUI::printScreen(){
	std::cout << "1. Start game" << std::endl;
	std::cout << "2. Load Game" << std::endl;
	std::cout << "3. Options" << std::endl;
	std::cout << "4. Exit" << std::endl;
}