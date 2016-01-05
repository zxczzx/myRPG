#include "StartGameGUI.h"
#include "MenuGUI.h"
#include "CreatePlayerGUI.h"
#include "Player.h"


StartGameGUI::StartGameGUI(){
}

StartGameGUI::~StartGameGUI(){
}


std::shared_ptr<GUI> StartGameGUI::handleInput(Game& game, int input){
	switch (input)
	{
	case 1:
	{
		std::shared_ptr<Player> player = std::make_shared<Player>();
		game.setPlayer(player);
		return std::make_shared<CreatePlayerGUI>();
	}
	case 2:
		return std::make_shared<MenuGUI>();
	case 3:
		return std::make_shared<MenuGUI>();
	default:
		break;
	}
}

void StartGameGUI::enter(Game& game){
	Graphic graphic = Graphic::MENU_START_GAME_GUI;
	game.setGraphic(graphic);
}