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
	else if (input < game.getPlayer()->getInventory().size()+2 && input > 1 ) {	//item id choice
		auto chosenItem = game.getPlayer()->getInventory()[input - 2];
		if (chosenItem->isUsable() == true){
			std::cout << "1. Description" << std::endl;
			std::cout << "2. Remove" << std::endl;
			std::cout << "3. Use" << std::endl;
			choice = game.getInput<int>();
			if (choice >= 1 && choice <= 3){
				itemAction(game, chosenItem, choice);
			}
		}
		else{
			std::cout << "1. Description" << std::endl;
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
		item->showDescription();
		break;
	case 2:
		std::cout << "Item " << item->getName() << " has been removed" << std::endl;
		game.getPlayer()->removeItem(item);
		break;
	case 3:
		std::cout << "You have used " << item->getName() << std::endl;
		game.getPlayer()->useItem(std::static_pointer_cast<UsableItem>(item));
		break;
	default:
		break;
	}
}