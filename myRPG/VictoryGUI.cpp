#include "VictoryGUI.h"
#include "StoryGUI.h"

VictoryGUI::VictoryGUI(){
}

VictoryGUI::~VictoryGUI(){
}

std::shared_ptr<GUI> VictoryGUI::handleInput(World& world, int input){
	input = world.getInput<int>();
	switch (input)
	{
	default:	//press any key
		return returnProperGUI<StoryGUI>();
	}
}

void VictoryGUI::enter(World& world){
	Graphic graphic = Graphic::BATTLE_VICTORY_GUI;
	world.setGraphic(graphic);
}