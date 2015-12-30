#include "StoryGUI.h"
#include "BattleGUI.h"
#include "MenuGUI.h"

StoryGUI::StoryGUI(){
}


StoryGUI::~StoryGUI(){
}

std::shared_ptr<GUI> StoryGUI::handleInput(Game& game, int input){
	switch (input)
	{
	case 1:
		return std::make_shared<BattleGUI>();
	case 2:
	case 3:
	{
		srand(time(NULL));
		int random = rand() % 10 + 1;
		if (random < 5){
			return std::make_unique<StoryGUI>();
		}
		else{
			return std::make_unique<BattleGUI>();
		}
	}
	case 4:
	case 5:
		return std::make_shared<MenuGUI>();
	default:
		return std::make_unique<StoryGUI>();
	}
}

void StoryGUI::enter(Game& game){
	Graphic graphic = Graphic::STORY_GUI;
	game.setGraphic(graphic);
}