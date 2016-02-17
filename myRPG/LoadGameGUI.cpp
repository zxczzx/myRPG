#include "LoadGameGUI.h"
#include "StoryGUI.h"
#include "ObjectSpawn.h"
#include "Paths.h"

LoadGameGUI::LoadGameGUI(){
}

LoadGameGUI::~LoadGameGUI(){
}

std::shared_ptr<GUI> LoadGameGUI::handleInput(Game& game, int input){
	switch (input)
	{
	case 1: //load file 1
	case 2: //load file 2
	case 3: //load file 3
	case 4: //load file 4
	case 5: //load file 5
		if (game.getSavedGames()[input - 1] != ""){
			loadGame(game, game.getSavedGames()[input - 1]);
			return returnProperGUI<StoryGUI>();
		}
		else{
			break;
		}
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
	//spawn player actor
	std::shared_ptr<ObjectSpawn> spawner = std::make_shared<ObjectSpawn>();
	game.setActor(spawner->spawnActor(Paths::saveGames + filename));
}
