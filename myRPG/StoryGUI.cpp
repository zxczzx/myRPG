#include "StoryGUI.h"


StoryGUI::StoryGUI(){
}


StoryGUI::~StoryGUI(){
}

bool StoryGUI::interaction(int action, std::shared_ptr<GUI>& nextGUI){
	switch (action){
	case 1:
	{
		nextGUI = std::make_unique<BattleGUI>();
		break;
	}
	case 2:
	case 3:
	{
		int random = rand() % 100 + 1;
		if (random < 50){
			nextGUI = std::make_unique<StoryGUI>();
		}
		else{
			nextGUI = std::make_unique<BattleGUI>();
		}
		break;
	}
	case 4:
		break;
	case 5:
		break;
	default:
		break;
	}
	return true;
}

void StoryGUI::printScreen(){
	std::cout << "1. Go to Battle GUI" << std::endl;
	std::cout << "2. Turn right" << std::endl;
	std::cout << "3. Turn left" << std::endl;
	std::cout << "4. Inventory" << std::endl;
	std::cout << "5. Menu" << std::endl;
}