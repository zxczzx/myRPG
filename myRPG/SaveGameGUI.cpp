#include <fstream>
#include "SaveGameGUI.h"
#include "Filesystem.h"

SaveGameGUI::SaveGameGUI(){
}

SaveGameGUI::~SaveGameGUI(){
}

std::shared_ptr<GUI> SaveGameGUI::handleInput(Game& game, int input){
	std::string name;
	std::string choice;
	std::unique_ptr<Filesystem> filesystem = std::make_unique<Filesystem>();
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
				saveGame(game, game.getSavedGames()[input - 1]);
				std::cout << "Game saved" << std::endl;
			}
			else{
				return prev;
			}
		}
		else{
			std::cout << "Your save name: " << std::endl;
			std::cin >> name;
			saveGame(game, name);
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

void SaveGameGUI::saveGame(Game& game, std::string filename){
	std::ofstream fout("./SavedGames/" + filename);
	fout << "name " << game.getPlayer()->getName() << std::endl;
	fout << "class " << game.getPlayer()->getClassType() << std::endl;
	fout << "level " << game.getPlayer()->getLevel() << std::endl;
	fout << "exp " << game.getPlayer()->getExperience() << std::endl;
	fout << "hp " << game.getPlayer()->getHitPoints() << std::endl;
	fout << "mp " << game.getPlayer()->getMana() << std::endl;
}