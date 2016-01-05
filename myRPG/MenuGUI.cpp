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
	case 1:
		return std::make_shared<StartGameGUI>();
	case 2:
	case 3:
	case 4:
	case 5:
		//return std::make_shared<ExitGUI>();
	default:
		return std::make_shared<QuitGUI>();
	}
}

void MenuGUI::enter(Game& game){
	Graphic graphic = Graphic::MENU_GUI;
	game.setGraphic(graphic);
}