#include "SpecialAbilitiesGUI.h"

SpecialAbilitiesGUI::SpecialAbilitiesGUI(){
}

SpecialAbilitiesGUI::~SpecialAbilitiesGUI(){
}

std::shared_ptr<GUI> SpecialAbilitiesGUI::handleInput(World& world, int input){
	switch (input)
	{
	case 1:	
		return prev;
	default:
		break;
	}
}

void SpecialAbilitiesGUI::enter(World& world){
	Graphic graphic = Graphic::INVENTORY_SPECIAL_ABILITIES;
	world.setGraphic(graphic);
}