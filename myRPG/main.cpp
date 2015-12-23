#include "MainMenu.h"


int main(){
	std::unique_ptr<MainMenu> menu(new MainMenu());
	menu->start();

	return 0;
}