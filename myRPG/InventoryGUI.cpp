#include "InventoryGUI.h"
#include "MenuGUI.h"


InventoryGUI::InventoryGUI(){
}


InventoryGUI::~InventoryGUI(){
}

std::shared_ptr<GUI> InventoryGUI::handleInput(Game& game, int input){
	switch (input)
	{
	case 1:
		return std::make_shared<MenuGUI>();
	default:
		return std::make_shared<InventoryGUI>();
	}
}

void InventoryGUI::enter(Game& game){
	Graphic graphic = Graphic::INENTORY_GUI;
	game.setGraphic(graphic);
}