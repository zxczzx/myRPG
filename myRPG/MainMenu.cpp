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
	std::shared_ptr<GUI> menu(new MenuGUI());
	gui = menu;
	int action;
	bool running = true;

	while (running){
		gui->printScreen();
		std::cin >> action;
		running = gui->interaction(action, gui);
		MainMenu::cls();
	}
}

void MainMenu::cls(){
	system("CLS");
	//std::cout << std::string(31, '\n');
}