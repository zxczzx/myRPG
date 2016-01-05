#include "Game.h"

int main(){
	std::unique_ptr<Game> game = std::make_unique<Game>();
	int action;
	game->setGraphic(Graphic::MENU_GUI);

	while (true){
		_CrtDumpMemoryLeaks();
		std::cin >> action;
		game->handleInput(action);
	}

	return 0;
}