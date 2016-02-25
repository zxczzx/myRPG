#include "EquipmentGUI.h"

EquipmentGUI::EquipmentGUI(){
}

EquipmentGUI::~EquipmentGUI(){
}

std::shared_ptr<GUI> EquipmentGUI::handleInput(Game& game, int input){
	switch (input)
	{
	case 1:	//back
		return prev;
	case 2:	//head
		takeOffItem(game, ItemSlot::HEAD);
		break;
	case 3:	//body
		takeOffItem(game, ItemSlot::BODY);
		break;
	case 4:	//legs
		takeOffItem(game, ItemSlot::LEGS);
		break;
	case 5:	//feet
		takeOffItem(game, ItemSlot::FEET);
		break;
	case 6:	//shoulders
		takeOffItem(game, ItemSlot::SHOULDERS);
		break;
	case 7:	//gloves
		takeOffItem(game, ItemSlot::GLOVES);
		break;
	case 8:	//main-hand
		takeOffItem(game, ItemSlot::MAIN_HAND);
		break;
	case 9:	//off-hand
		takeOffItem(game, ItemSlot::OFFHAND);
		break;
	default:
		break;
	}
}

void EquipmentGUI::enter(Game& game){
	Graphic graphic = Graphic::INVENTORY_EQUIPMENT;
	game.setGraphic(graphic);
}

void EquipmentGUI::takeOffItem(Game& game, ItemSlot slot){
	auto player = game.getActor();
	if (player->BodySlots.find(slot)->second != nullptr){
		std::string itemName = player->BodySlots.find(slot)->second->getName();
		player->takeOffItem(player->BodySlots.find(slot)->second);
		enter(game);
		std::cout << "You have taken off " << itemName << std::endl;
	}
	else{
		std::cout << "This slot is already empty" << std::endl;
	}
}