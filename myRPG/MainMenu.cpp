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

//METHODS
void MainMenu::start(){
	gui = std::make_unique<MenuGUI>();
	int action;

	while (true){
		gui->printScreen();
		std::cin >> action;
		if (!gui->interaction(action, gui))
			break;
		MainMenu::cls();
	}
}

void MainMenu::cls(){
	system("CLS");
}