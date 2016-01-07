#include "Game.h"
#include "MenuGUI.h"

Game::Game(){
	state_ = std::make_shared<MenuGUI>();
	running = true;
}

Game::~Game(){
}

//GETTERS
std::shared_ptr<Player> Game::getPlayer(){
	return player_;
}

std::vector<std::shared_ptr<Character> > Game::getCharacters(){
	return characters_;
}

//SETTERS
void Game::setPlayer(std::shared_ptr<Player> player){
	player_ = player;
}

void Game::setCharacters(std::vector<std::shared_ptr<Character> > enemiesList){
	characters_ = enemiesList;
}

//METHODS
void Game::handleInput(int input){
	std::shared_ptr<GUI> state = state_->handleInput(*this, input);
	if (state != NULL){
		state_.reset();
		state_ = state;

		state_->enter(*this);
	}
}

void Game::initiaviveSort(){
	std::sort(characters_.begin(), characters_.end(),
		[](std::shared_ptr<Character>& a, std::shared_ptr<Character>& b)-> bool {
		return a->getInitiative() > b->getInitiative();
	});
}

void Game::setGraphic(Graphic graphic){
	system("CLS");
	switch (graphic)
	{
	case Graphic::MENU_GUI:
		std::cout << "Main Menu" << std::endl << std::endl;
		std::cout << "1. Start game" << std::endl;
		std::cout << "2. Save game" << std::endl;
		std::cout << "3. Load game" << std::endl;
		std::cout << "4. Options" << std::endl;
		std::cout << "5. Exit" << std::endl;
		break;
	case Graphic::MENU_STORY_GUI:
		std::cout << "Where do you want to go?" << std::endl << std::endl;
		std::cout << "1. Go to Battle GUI" << std::endl;
		std::cout << "2. Turn right" << std::endl;
		std::cout << "3. Turn left" << std::endl;
		std::cout << "4. Inventory" << std::endl;
		std::cout << "5. Menu" << std::endl;
		break;
	case Graphic::MENU_START_GAME_GUI:
		std::cout << "Start game" << std::endl << std::endl;
		std::cout << "1. Create new player" << std::endl;
		std::cout << "2. Load game" << std::endl;
		std::cout << "3. Back" << std::endl;
		break;
	case Graphic::MENU_QUIT_GUI:
		std::cout << "Do you really want to quit?" << std::endl << std::endl;
		std::cout << "1. Yes" << std::endl;
		std::cout << "2. No" << std::endl;
		break;
	case Graphic::CREATE_PLAYER:
		std::cout << "Create your character" << std::endl << std::endl;
		std::cout << "1. Change name \t\t" << "Your name: " << player_->getName() << std::endl;
		std::cout << "2. Change class \t" << "Your class: " << player_->getClassType() << std::endl;
		std::cout << "3. Start game" << std::endl;
		std::cout << "4. Back" << std::endl;
		break;
	case Graphic::CREATE_CLASS_OPTION:
		std::cout << "What class do you choose?" << std::endl << std::endl;
		std::cout << "1. Warrior" << std::endl;
		std::cout << "2. Mage" << std::endl;
		break;
	case Graphic::CREATE_WRITE_OPTION:
		std::cout << "Your text" << std::endl;
		break;
	case Graphic::BATTLE_GUI:
		//GUI
		std::cout << "Battle!" << std::endl << std::endl;
		std::cout << "1. Attack" << std::endl;
		std::cout << "2. Special ability" << std::endl;
		std::cout << "3. Spell" << std::endl;
		std::cout << "4. Inventory" << std::endl;
		std::cout << "5. Pass turn" << std::endl;
		std::cout << "6. Retreat" << std::endl;
		//Graphic
		std::cout << std::endl;
		std::cout << "Status: " << player_->getName() << " " << player_->getHitPoints() << " hp" << std::endl;

		break;
	case Graphic::INENTORY_GUI:
		std::cout << "Inventory" << std::endl << std::endl;
		break;
	default:
		break;
	}
}