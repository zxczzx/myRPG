#include "StoryGUI.h"
#include "BattleGUI.h"
#include "MenuGUI.h"
#include "Enemy.h"

StoryGUI::StoryGUI(){
}


StoryGUI::~StoryGUI(){
}

std::shared_ptr<GUI> StoryGUI::handleInput(Game& game, int input){
	switch (input)
	{
	case 1:
		return std::make_shared<BattleGUI>();
	case 2:
	case 3:
	{
		srand(time(NULL));
		int random = rand() % 10 + 1;
		if (random < 5){
			return std::make_unique<StoryGUI>();
		}
		else{
			//create enemies
			srand(time(NULL));
			int enemy_number = rand() % 3 + 1;
			std::vector<std::shared_ptr<Character> > characters;
			for (int i = 0; i < enemy_number; i++){
				std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>();
				enemy->setName("Orc");
				characters.push_back(enemy);
			}
			//add characters
			characters.push_back(game.getPlayer());
			game.setEnemies(characters);
			characters.clear();

			//initiative rolls
			srand(time(NULL));
			int random = rand() % 10 + 1;

			//sort vector

			return std::make_unique<BattleGUI>();
		}
	}
	case 4:
	case 5:
		return std::make_shared<MenuGUI>();
	default:
		return std::make_unique<StoryGUI>();
	}
}

void StoryGUI::enter(Game& game){
	Graphic graphic = Graphic::MENU_STORY_GUI;
	game.setGraphic(graphic);
}