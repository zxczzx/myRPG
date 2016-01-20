#include "SpecialAbilitiesGUI.h"

SpecialAbilitiesGUI::SpecialAbilitiesGUI(){
}

SpecialAbilitiesGUI::~SpecialAbilitiesGUI(){
}

std::shared_ptr<GUI> SpecialAbilitiesGUI::handleInput(Game& game, int input){
	switch (input)
	{
	case 1:	
		return prev;
	default:
		break;
	}
}

void SpecialAbilitiesGUI::enter(Game& game){
	Graphic graphic = Graphic::INVENTORY_SPECIAL_ABILITIES;
	game.setGraphic(graphic);
}