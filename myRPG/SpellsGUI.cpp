#include "SpellsGUI.h"

SpellsGUI::SpellsGUI(){
}

SpellsGUI::~SpellsGUI(){
}

std::shared_ptr<GUI> SpellsGUI::handleInput(Game& game, int input){
	switch (input)
	{
	case 1:
		return prev;
	default:
		break;
	}
}

void SpellsGUI::enter(Game& game){
	Graphic graphic = Graphic::INVENTORY_SPELLS;
	game.setGraphic(graphic);
}