#include "VictoryGUI.h"
#include "StoryGUI.h"

VictoryGUI::VictoryGUI(){
}

VictoryGUI::~VictoryGUI(){
}

std::shared_ptr<GUI> VictoryGUI::handleInput(Game& game, int input){
	switch (input)
	{
	default:
		return std::make_shared<StoryGUI>();
	}
}

void VictoryGUI::enter(Game& game){
	Graphic graphic = Graphic::BATTLE_VICTORY_GUI;
	game.setGraphic(graphic);
}