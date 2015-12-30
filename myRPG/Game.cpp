#include "Game.h"
#include "MenuGUI.h"

Game::Game(){
	state_ = std::make_shared<MenuGUI>();
	running = true;
}

Game::~Game(){
}

void Game::handleInput(int input){
	std::shared_ptr<GUI> state = state_->handleInput(*this, input);
	if (state != NULL){
		state_.reset();
		state_ = state;

		state_->enter(*this);
	}
}

void Game::setGraphic(Graphic graphic){
	system("CLS");
	switch (graphic)
	{
	case Graphic::STORY_GUI:
		std::cout << "1. Go to Battle GUI" << std::endl;
		std::cout << "2. Turn right" << std::endl;
		std::cout << "3. Turn left" << std::endl;
		std::cout << "4. Inventory" << std::endl;
		std::cout << "5. Menu" << std::endl;
		break;
	case Graphic::MENU_GUI:
		std::cout << "1. Start game" << std::endl;
		std::cout << "2. Save game" << std::endl;
		std::cout << "3. Load game" << std::endl;
		std::cout << "4. Options" << std::endl;
		std::cout << "5. Exit" << std::endl;
		break;
	case Graphic::BATTLE_GUI:
		std::cout << "1. BattleGUI" << std::endl;
		break;
	case Graphic::QUIT_GUI:
		std::cout << "Do you really want to quit?" << std::endl;
		std::cout << "1. Yes" << std::endl;
		std::cout << "2. No" << std::endl;
		break;
	case Graphic::INENTORY_GUI:
		break;
	default:
		break;
	}
}