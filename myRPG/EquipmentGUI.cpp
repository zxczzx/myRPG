#include "EquipmentGUI.h"

EquipmentGUI::EquipmentGUI(){
}

EquipmentGUI::~EquipmentGUI(){
}

std::shared_ptr<GUI> EquipmentGUI::handleInput(World& world, int input){
	switch (input)
	{
	case 1:	//back
		return prev;
	case 2:	//head
		takeOffItem(world, ItemSlot::HEAD);
		break;
	case 3:	//body
		takeOffItem(world, ItemSlot::BODY);
		break;
	case 4:	//legs
		takeOffItem(world, ItemSlot::LEGS);
		break;
	case 5:	//feet
		takeOffItem(world, ItemSlot::FEET);
		break;
	case 6:	//shoulders
		takeOffItem(world, ItemSlot::SHOULDERS);
		break;
	case 7:	//gloves
		takeOffItem(world, ItemSlot::GLOVES);
		break;
	case 8:	//main-hand
		takeOffItem(world, ItemSlot::MAIN_HAND);
		break;
	case 9:	//off-hand
		takeOffItem(world, ItemSlot::OFFHAND);
		break;
	default:
		break;
	}
}

void EquipmentGUI::enter(World& world){
	Graphic graphic = Graphic::INVENTORY_EQUIPMENT;
	world.setGraphic(graphic);
}

void EquipmentGUI::takeOffItem(World& world, ItemSlot slot){
	auto player = world.getActor();
	if (player->BodySlots.find(slot)->second != nullptr){
		std::string itemName = player->BodySlots.find(slot)->second->getName();
		player->takeOffItem(player->BodySlots.find(slot)->second);
		enter(world);
		std::cout << "You have taken off " << itemName << std::endl;
	}
	else{
		std::cout << "This slot is already empty" << std::endl;
	}
}