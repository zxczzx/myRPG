#include "BackpackGUI.h"

BackpackGUI::BackpackGUI(){
}

BackpackGUI::~BackpackGUI(){
}

std::shared_ptr<GUI> BackpackGUI::handleInput(World& world, int input){
	int choice;
	if (input == 1){	//back
		return prev;
	}
	else if (input < world.getActor()->getBackpack()->getItems().size() + 2 && input > 1) {	//item id choice
		auto chosenItem = world.getActor()->getBackpack()->getItems()[input - 2];
		if (chosenItem->isUsable() == true){
			enter(world);
			std::cout << std::endl << "1. Description" << std::endl;
			std::cout << "2. Remove" << std::endl;
			std::cout << "3. Use" << std::endl;
			choice = world.getInput<int>();
			if (choice >= 1 && choice <= 3){
				itemAction(world, chosenItem, choice);
			}
		}
		else{
			enter(world);
			std::cout << std::endl << "1. Description" << std::endl;
			std::cout << "2. Remove" << std::endl;
			choice = world.getInput<int>();
			if (choice == 1 || choice == 2){
				itemAction(world, chosenItem, choice);
			}
		}
	}
}

void BackpackGUI::enter(World& world){
	Graphic graphic = Graphic::INVENTORY_BACKPACK;
	world.setGraphic(graphic);
}

void BackpackGUI::itemAction(World& world, std::shared_ptr<Inventory> item, int input){
	switch (input){
	case 1:
		enter(world);
		std::cout << std::endl;
		std::cout << "\t" << item->getName() << std::endl;
		item->showDescription();
		if (item->isUsable()){
			if (std::static_pointer_cast<Inventory>(item)->getArmorValue() != 0)
				std::cout << "Armor: \t" << std::static_pointer_cast<Inventory>(item)->getArmorValue() << std::endl;
			if (std::static_pointer_cast<Inventory>(item)->getAttackValue() != 0)
				std::cout << "Damage: \t" << std::static_pointer_cast<Inventory>(item)->getAttackValue() << std::endl;
			if (std::static_pointer_cast<Inventory>(item)->getMaxDurability() != 0)
				std::cout << "Durability: \t" << std::static_pointer_cast<Inventory>(item)->getDurability() << "/"
				<< std::static_pointer_cast<Inventory>(item)->getMaxDurability() << std::endl;
			if (std::static_pointer_cast<Inventory>(item)->getResistance()->getColdImmunity() != 0)
				std::cout << "Cold resistnce: " << std::static_pointer_cast<Inventory>(item)->getResistance()->getColdImmunity() << std::endl;
			if (std::static_pointer_cast<Inventory>(item)->getResistance()->getElectricityImmunity() != 0)
				std::cout << "Electricity resistnce: " 
				<< std::static_pointer_cast<Inventory>(item)->getResistance()->getElectricityImmunity() << std::endl;
			if (std::static_pointer_cast<Inventory>(item)->getResistance()->getFireImmunity() != 0)
				std::cout << "Fire resistnce: " << std::static_pointer_cast<Inventory>(item)->getResistance()->getFireImmunity() << std::endl;
			if (std::static_pointer_cast<Inventory>(item)->getResistance()->getWaterImmunity() != 0)
				std::cout << "Water resistnce: " << std::static_pointer_cast<Inventory>(item)->getResistance()->getWaterImmunity() << std::endl;
			std::cout << "Required level: " << std::static_pointer_cast<Inventory>(item)->getRequirements()->level << std::endl;
			if (std::static_pointer_cast<Inventory>(item)->getRequirements()->classType.size() != 2){
				std::cout << "(Only for ";
				for (auto& i : std::static_pointer_cast<Inventory>(item)->getRequirements()->classType){
					std::cout << i;
				}
				std::cout << ")" << std::endl;
			}
		}
		break;
	case 2:
		world.getActor()->getBackpack()->removeFromBackpack(item);
		enter(world);
		std::cout << std::endl << "Item " << item->getName() << " has been removed" << std::endl;
		break;
	case 3:
		world.getActor()->useItem(item);
		enter(world);
		std::cout << std::endl << "You have used " << item->getName() << std::endl;
		break;
	default:
		break;
	}
}