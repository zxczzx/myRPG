#include "QuitGUI.h"
#include "MenuGUI.h"

QuitGUI::QuitGUI(){
}

QuitGUI::~QuitGUI(){
}

std::shared_ptr<GUI> QuitGUI::handleInput(Game& game, int input){
	switch (input)
	{
	case 1:	//yes
		exit(0);
	case 2:	//no (back)
		return prev;
	default:
		break;
	}
}

void QuitGUI::enter(Game& game){
	Graphic graphic = Graphic::MENU_QUIT_GUI;
	game.setGraphic(graphic);
}