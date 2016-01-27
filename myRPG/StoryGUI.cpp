#include "StoryGUI.h"
#include "BattleGUI.h"
#include "MenuGUI.h"
#include "InventoryGUI.h"
#include "Enemy.h"
#include "Orc.h"

StoryGUI::StoryGUI(){
}


StoryGUI::~StoryGUI(){
}

std::shared_ptr<GUI> StoryGUI::handleInput(Game& game, int input){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> random_path(1, 10);
	std::uniform_int_distribution<> random_enemies(1, 3);
	std::uniform_int_distribution<> random_init(1, 100);

	game.setGameState(GameState::STATE_STORY);

	switch (input)
	{
	case 1:	//turn right
	case 2:	//turn left
	{
		int random = random_path(gen);
		if (random < 5){
			return returnProperGUI<StoryGUI>();
		}
		else{
			//create enemies
			int enemy_number = random_enemies(gen);
			std::vector<std::shared_ptr<Character> > characters;
			for (int i = 0; i < enemy_number; i++){
				std::shared_ptr<Enemy> enemy = std::make_shared<Orc>();
				characters.push_back(enemy);
			}
			//add characters
			characters.push_back(game.getPlayer());
			game.setCharacters(characters);
			characters.clear();
			characters.shrink_to_fit();

			//initiative rolls
			for (auto& character : game.getCharacters()){
				int rand_initiative = random_init(gen);
				character->setInitiative(character->getInitiative() + rand_initiative);
			}

			//sort vector
			game.initiaviveSort();

			return returnProperGUI<BattleGUI>();
		}
	}
	case 3:	//inventory
		return returnProperGUI<InventoryGUI>();
	case 4:	//menu
		return returnProperGUI<MenuGUI>();
	default:
		break;
	}
}

void StoryGUI::enter(Game& game){
	Graphic graphic = Graphic::MENU_STORY_GUI;
	game.setGraphic(graphic);
}