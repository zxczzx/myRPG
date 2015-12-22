#include "MainMenu.h"

MainMenu::~MainMenu(){
}

//GETTERS
std::shared_ptr<GUI> MainMenu::getInterface(){
	return gui;
}

//SETTERS
void MainMenu::setInterface(std::shared_ptr<GUI> interf){
	gui = interf;
}