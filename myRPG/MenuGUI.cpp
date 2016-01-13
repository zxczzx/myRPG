#include "MenuGUI.h"
#include "StartGameGUI.h"
#include "QuitGUI.h"

MenuGUI::MenuGUI(){
}

MenuGUI::~MenuGUI(){
}

std::shared_ptr<GUI> MenuGUI::handleInput(Game& game, int input){
	switch (input)
	{
	case 1:	//start game
		return std::make_shared<StartGameGUI>();
	case 2:	//save game
	case 3:	//load game
	case 4:	//options
	case 5:	//exit
		return std::make_shared<QuitGUI>();
	default:
		break;
	}
}

void MenuGUI::enter(Game& game){
	Graphic graphic = Graphic::MENU_GUI;
	game.setGraphic(graphic);
}