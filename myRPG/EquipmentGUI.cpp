#include "EquipmentGUI.h"

EquipmentGUI::EquipmentGUI(){
}

EquipmentGUI::~EquipmentGUI(){
}

std::shared_ptr<GUI> EquipmentGUI::handleInput(Game& game, int input){
	auto player = game.getPlayer();
	switch (input)
	{
	case 1:	//back
		return prev;
	case 2:	//head
		takeOffItem(player, ItemSlot::HEAD);
		break;
	case 3:	//body
		takeOffItem(player, ItemSlot::BODY);
		break;
	case 4:	//legs
		takeOffItem(player, ItemSlot::LEGS);
		break;
	case 5:	//feet
		takeOffItem(player, ItemSlot::FEET);
		break;
	case 6:	//shoulders
		takeOffItem(player, ItemSlot::SHOULDERS);
		break;
	case 7:	//gloves
		takeOffItem(player, ItemSlot::GLOVES);
		break;
	case 8:	//main-hand
		takeOffItem(player, ItemSlot::MAIN_HAND);
		break;
	case 9:	//off-hand
		takeOffItem(player, ItemSlot::OFFHAND);
		break;
	default:
		break;
	}
}

void EquipmentGUI::enter(Game& game){
	Graphic graphic = Graphic::INVENTORY_EQUIPMENT;
	game.setGraphic(graphic);
}

void EquipmentGUI::takeOffItem(std::shared_ptr<Player> player, ItemSlot slot){
	if (player->BodySlots.find(slot)->second != nullptr){
		std::cout << "You have taken off " << player->BodySlots.find(slot)->second->getName() << std::endl;
		player->takeOffItem(player->BodySlots.find(slot)->second);
	}
	else{
		std::cout << "This slot is already empty" << std::endl;
	}
}