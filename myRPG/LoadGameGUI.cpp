#include "LoadGameGUI.h"
#include "Filesystem.h"
#include "StoryGUI.h"
#include "Warrior.h"
#include "Mage.h"
#include "dirent.h"

LoadGameGUI::LoadGameGUI(){
}

LoadGameGUI::~LoadGameGUI(){
}

std::shared_ptr<GUI> LoadGameGUI::handleInput(Game& game, int input){
	input = game.getInput<int>();
	switch (input)
	{
	case 1: //load file 1
	case 2: //load file 2
	case 3: //load file 3
	case 4: //load file 4
	case 5: //load file 5
		loadGame(game, game.getSavedGames()[input - 1]);
		return returnProperGUI<StoryGUI>();
	case 6: //back
		return prev;
	default:
		break;
	}
}

void LoadGameGUI::enter(Game& game){
	Graphic graphic = Graphic::MENU_LOAD_GAME_GUI;
	game.setGraphic(graphic);
}

void LoadGameGUI::loadGame(Game& game, std::string filename){
	//load info from file
	std::map<std::string, std::string> fileMap;
	std::shared_ptr<Filesystem> filesystem = std::make_shared<Filesystem>();
	fileMap = filesystem->ReadFromFile(filename);
	//set proper class
	std::string classType = fileMap.find("class")->second;
	if (classType == "Warrior"){
		std::shared_ptr<Player> player = std::make_shared<Warrior>();
		game.setPlayer(player);
	}
	else if (classType == "Mage"){
		std::shared_ptr<Player> player = std::make_shared<Mage>();
		game.setPlayer(player);
	}
	//set loaded values to a player
	game.getPlayer()->setName(fileMap.find("name")->second);
	game.getPlayer()->setLevel(std::stoi(fileMap.find("level")->second));
	game.getPlayer()->setHitPoints(std::stoi(fileMap.find("hp")->second));
	game.getPlayer()->setMana(std::stoi(fileMap.find("mp")->second));
	game.getPlayer()->setExperience(std::stoi(fileMap.find("exp")->second));

	for (unsigned i = 1; i < game.getPlayer()->getLevel(); i++){
		game.getPlayer()->statsGrowth();
	}
}
