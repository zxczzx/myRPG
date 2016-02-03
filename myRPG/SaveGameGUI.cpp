#include "SaveGameGUI.h"

SaveGameGUI::SaveGameGUI(){
}

SaveGameGUI::~SaveGameGUI(){
}

std::shared_ptr<GUI> SaveGameGUI::handleInput(Game& game, int input){
	std::string name;
	std::string choice;
	std::shared_ptr<Filesystem> filesystem = std::make_shared<Filesystem>();
	switch (input)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		if (game.getSavedGames()[input - 1] != ""){
			std::cout << "Do you wish to override this file? (yes/no)" << std::endl;
			std::cin >> choice;
			if (choice == "yes"){
				saveGame(game, filesystem, game.getSavedGames()[input - 1]);
				std::cout << "Game saved" << std::endl;
			}
			else{
				return prev;
			}
		}
		else{
			std::cout << "Your save name: " << std::endl;
			std::cin >> name;
			saveGame(game, filesystem, name);
			std::cout << "Game saved" << std::endl;
		}
	case 6:
		return prev;
	default:
		break;
	}
}

void SaveGameGUI::enter(Game& game){
	Graphic graphic = Graphic::MENU_LOAD_GAME_GUI;
	game.setGraphic(graphic);
}

void SaveGameGUI::saveGame(Game& game, std::shared_ptr<Filesystem> filesystem, std::string filename){
	//helper lambdas
	auto getSlot = [&](ItemSlot slot) {
		return game.getPlayer()->BodySlots[slot] == nullptr ? "0" : "\"" + game.getPlayer()->BodySlots[slot]->getName() + "\"";
	};

	auto makeVector = [](std::string str){
		return std::vector<std::string>(1, str);
	};
	//maps
	std::map<std::string, std::vector<std::string> > stats{
		{ "name", makeVector(game.getPlayer()->getName()) },
		{ "class", makeVector(game.getPlayer()->getClassType()) },
		{ "level", makeVector(std::to_string(game.getPlayer()->getLevel())) },
		{ "exp", makeVector(std::to_string(game.getPlayer()->getExperience())) },
		{ "hp", makeVector(std::to_string(game.getPlayer()->getHitPoints())) },
		{ "mp", makeVector(std::to_string(game.getPlayer()->getMana())) },
	};

	std::map<std::string, std::vector<std::string> > equipment{
		{ "Head", makeVector(getSlot(ItemSlot::HEAD)) },
		{ "Body", makeVector(getSlot(ItemSlot::BODY)) },
		{ "Legs", makeVector(getSlot(ItemSlot::LEGS)) },
		{ "Feet", makeVector(getSlot(ItemSlot::FEET)) },
		{ "Shoulders", makeVector(getSlot(ItemSlot::SHOULDERS)) },
		{ "Gloves", makeVector(getSlot(ItemSlot::GLOVES)) },
		{ "Mainhand", makeVector(getSlot(ItemSlot::MAIN_HAND)) },
		{ "Offhand", makeVector(getSlot(ItemSlot::OFFHAND)) },
	};
	//change name
	if (filename.find(".save") == std::string::npos){
		filename = filename + ".save";
	}
	//execute
	filesystem->writeToFile(stats, equipment, game.getPlayer()->getBackpack()->getItems(), filename);
}