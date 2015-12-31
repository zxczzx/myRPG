#include "QuitGUI.h"
#include "MenuGUI.h"

QuitGUI::QuitGUI(){
}

QuitGUI::~QuitGUI(){
}

std::shared_ptr<GUI> QuitGUI::handleInput(Game& game, int input){
	switch (input)
	{
	case 1:
		exit(0);
	case 2:
		return std::make_shared<MenuGUI>();
	default:
		return std::make_shared<QuitGUI>();
	}
}

void QuitGUI::enter(Game& game){
	Graphic graphic = Graphic::QUIT_GUI;
	game.setGraphic(graphic);
}