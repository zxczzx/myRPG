#include "BackpackGUI.h"

BackpackGUI::BackpackGUI(){
}

BackpackGUI::~BackpackGUI(){
}

std::shared_ptr<GUI> BackpackGUI::handleInput(Game& game, int input){
	int choice;
	if (input == 1){	//back
		return prev;
	}
	else if (input < game.getPlayer()->getBackpack()->getItems().size() + 2 && input > 1) {	//item id choice
		auto chosenItem = game.getPlayer()->getBackpack()->getItems()[input - 2];
		if (chosenItem->isUsable() == true){
			enter(game);
			std::cout << std::endl << "1. Description" << std::endl;
			std::cout << "2. Remove" << std::endl;
			std::cout << "3. Use" << std::endl;
			choice = game.getInput<int>();
			if (choice >= 1 && choice <= 3){
				itemAction(game, chosenItem, choice);
			}
		}
		else{
			enter(game);
			std::cout << std::endl << "1. Description" << std::endl;
			std::cout << "2. Remove" << std::endl;
			choice = game.getInput<int>();
			if (choice == 1 || choice == 2){
				itemAction(game, chosenItem, choice);
			}
		}
	}
}

void BackpackGUI::enter(Game& game){
	Graphic graphic = Graphic::INVENTORY_BACKPACK;
	game.setGraphic(graphic);
}

void BackpackGUI::itemAction(Game& game, std::shared_ptr<Inventory> item, int input){
	switch (input){
	case 1:
		enter(game);
		std::cout << std::endl;
		std::cout << "\t" << item->getName() << std::endl;
		item->showDescription();
		if (item->isUsable()){
			if (std::static_pointer_cast<UsableItem>(item)->getArmorValue() != 0)
				std::cout << "Armor: \t" << std::static_pointer_cast<UsableItem>(item)->getArmorValue() << std::endl;
			if (std::static_pointer_cast<UsableItem>(item)->getAttackValue() != 0)
				std::cout << "Damage: \t" << std::static_pointer_cast<UsableItem>(item)->getAttackValue() << std::endl;
			if (std::static_pointer_cast<UsableItem>(item)->getResistance()->getColdImmunity() != 0)
				std::cout << "Cold resistnce: \t" << std::static_pointer_cast<UsableItem>(item)->getResistance()->getColdImmunity() << std::endl;
			if (std::static_pointer_cast<UsableItem>(item)->getResistance()->getElectricityImmunity() != 0)
				std::cout << "Electricity resistnce: \t" 
				<< std::static_pointer_cast<UsableItem>(item)->getResistance()->getElectricityImmunity() << std::endl;
			if (std::static_pointer_cast<UsableItem>(item)->getResistance()->getFireImmunity() != 0)
				std::cout << "Fire resistnce: \t" << std::static_pointer_cast<UsableItem>(item)->getResistance()->getFireImmunity() << std::endl;
			if (std::static_pointer_cast<UsableItem>(item)->getResistance()->getWaterImmunity() != 0)
				std::cout << "Water resistnce: \t" << std::static_pointer_cast<UsableItem>(item)->getResistance()->getWaterImmunity() << std::endl;
			std::cout << "Required level: " << std::static_pointer_cast<UsableItem>(item)->getRequirements()->level;
			if (std::static_pointer_cast<UsableItem>(item)->getRequirements()->classType.size() != 2){
				std::cout << "(Only for " << std::static_pointer_cast<UsableItem>(item)->getRequirements()->classType[0] << ")";
			}
		}
		break;
	case 2:
		game.getPlayer()->getBackpack()->removeFromBackpack(item);
		enter(game);
		std::cout << std::endl << "Item " << item->getName() << " has been removed" << std::endl;
		break;
	case 3:
		game.getPlayer()->useItem(std::static_pointer_cast<UsableItem>(item));
		enter(game);
		std::cout << std::endl << "You have used " << item->getName() << std::endl;
		break;
	default:
		break;
	}
}