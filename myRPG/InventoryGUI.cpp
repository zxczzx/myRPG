#include "InventoryGUI.h"
#include "MenuGUI.h"
#include "BackpackGUI.h"
#include "EquipmentGUI.h"
#include "SpecialAbilitiesGUI.h"
#include "SpellsGUI.h"

InventoryGUI::InventoryGUI(){
}

InventoryGUI::~InventoryGUI(){
}

std::shared_ptr<GUI> InventoryGUI::handleInput(Game& game, int input){
	switch (input)
	{
	case 1:	//equipment
		return returnProperGUI<EquipmentGUI>();
	case 2:	//backpack
		return returnProperGUI<BackpackGUI>();
	case 3:	//spells
		return returnProperGUI<SpellsGUI>();
	case 4:	//special abilities
		return returnProperGUI<SpecialAbilitiesGUI>();
	case 5:	//back
		return prev;
	default:
		break;
	}
}

void InventoryGUI::enter(Game& game){
	Graphic graphic = Graphic::INVENTORY_GUI;
	game.setGraphic(graphic);
}