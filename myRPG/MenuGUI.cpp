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
		return returnProperGUI<StartGameGUI>();
	case 2:	//save game
	case 3:	//load game
	case 4:	//options
	case 5:	//exit
		return returnProperGUI<QuitGUI>();
	case 6:	//back
		if (prev != nullptr){
			return prev;
		}
	default:
		break;
	}
}

void MenuGUI::enter(Game& game){
	Graphic graphic;
	if (prev == nullptr){
		graphic = Graphic::MENU_GUI;
	}
	else{
		graphic = Graphic::MENU_GUI_BACK;
	}
	game.setGraphic(graphic);
	
}