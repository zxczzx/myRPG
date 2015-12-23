#include "MainMenu.h"


int main(){
	std::cout << "started" << std::endl;

	std::unique_ptr<MainMenu> menu(new MainMenu());
	menu->start();

	return 0;
}