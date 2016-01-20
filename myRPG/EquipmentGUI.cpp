#include "EquipmentGUI.h"

EquipmentGUI::EquipmentGUI(){
}

EquipmentGUI::~EquipmentGUI(){
}

std::shared_ptr<GUI> EquipmentGUI::handleInput(Game& game, int input){
	switch (input)
	{
	case 1:
		return prev;
		//auto prevGUI = returnProperGUI<EquipmentGUI>();
		//prevGUI->setPrev(prev->prev);
		//return prevGUI;
	default:
		break;
	}
}

void EquipmentGUI::enter(Game& game){
	Graphic graphic = Graphic::INVENTORY_EQUIPMENT;
	game.setGraphic(graphic);
}