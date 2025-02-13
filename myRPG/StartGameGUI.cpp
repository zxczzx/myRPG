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
	case 1:	//create new player
	{
		std::shared_ptr<Player> player = Player::createActor<Player>();
		game.setActor(player);
		return returnProperGUI<CreatePlayerGUI>();
	}
	case 2:	//load game
		break;
	case 3:	//back
		return prev;
	default:
		break;
	}
}

void StartGameGUI::enter(Game& game){
	Graphic graphic = Graphic::MENU_START_GAME_GUI;
	game.setGraphic(graphic);
}