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
		item->showDescription();
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