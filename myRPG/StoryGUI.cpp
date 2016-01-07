#include "StoryGUI.h"
#include "BattleGUI.h"
#include "MenuGUI.h"
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

	switch (input)
	{
	case 1:
		return std::make_shared<BattleGUI>();
	case 2:
	case 3:
	{
		int random = random_path(gen);
		if (random < 5){
			return std::make_unique<StoryGUI>();
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

			//initiative rolls
			for (auto& character : game.getCharacters()){
				int rand_initiative = random_init(gen);
				character->setInitiative(character->getInitiative() + rand_initiative);
			}

			//sort vector
			game.initiaviveSort();

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