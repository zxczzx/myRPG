#include "MenuGUI.h"
#include "StartGameGUI.h"
#include "QuitGUI.h"
#include "LoadGameGUI.h"
#include "SaveGameGUI.h"

MenuGUI::MenuGUI(){
}

MenuGUI::~MenuGUI(){
}

std::shared_ptr<GUI> MenuGUI::handleInput(World& world, int input){
	switch (input)
	{
	case 1:	//start world
		return returnProperGUI<StartGameGUI>();
	case 2:	//save world
		return returnProperGUI<SaveGameGUI>();
	case 3:	//load world
		return returnProperGUI<LoadGameGUI>();
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

void MenuGUI::enter(World& world){
	Graphic graphic;
	if (prev == nullptr){
		graphic = Graphic::MENU_GUI;
	}
	else{
		graphic = Graphic::MENU_GUI_BACK;
	}
	world.setGraphic(graphic);
	
}