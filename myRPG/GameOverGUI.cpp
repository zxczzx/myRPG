#include "GameOverGUI.h"
#include "MenuGUI.h"
#include "QuitGUI.h"

GameOverGUI::GameOverGUI()
{
}

GameOverGUI::~GameOverGUI()
{
}

std::shared_ptr<GUI> GameOverGUI::handleInput(Game& game, int input){
	switch (input)
	{
	case 1:
		return std::make_shared<MenuGUI>();
	case 2:
		return returnProperGUI<QuitGUI>();
	default:
		break;
	}
}

void GameOverGUI::enter(Game& game){
	Graphic graphic = Graphic::BATTLE_GAME_OVER_GUI;
	game.setGraphic(graphic);
}