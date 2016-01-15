#include "Game.h"
#include "MenuGUI.h"
#include "Filesystem.h"

Game::Game(){
	state_ = std::make_shared<MenuGUI>();
	state_->setPrev(nullptr);
	state_->setHead(state_);
}

Game::~Game(){
}

//GETTERS
std::shared_ptr<Player> Game::getPlayer(){
	return player_;
}

std::shared_ptr<Loot> Game::getLoot(){
	return loot_;
}

std::vector<std::shared_ptr<Character> > Game::getCharacters(){
	return characters_;
}

std::vector<std::string> Game::getSavedGames(){
	return savedGames_;
}

//SETTERS
void Game::setPlayer(std::shared_ptr<Player> player){
	player_ = player;
}

void Game::setLoot(std::shared_ptr<Loot> myLoot){
	loot_ = myLoot;
}

void Game::setCharacters(std::vector<std::shared_ptr<Character> > enemiesList){
	characters_ = enemiesList;
}

void Game::setSavedGames(std::vector<std::string> games){
	savedGames_ = games;
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
	if (graphic == Graphic::BATTLE_GUI || graphic == Graphic::MENU_STORY_GUI)
	std::cout << player_->getName() << ", " << player_->getLevel()
		<< " lvl, " << player_->getExperience() << "/" << player_->getLvLMap().find(player_->getLevel())->second  << " exp, "
		<< player_->getHitPoints() << "/" << player_->getMaxHitPoints() << " hp, " 
		<< player_->getMana() << "/" << player_->getMaxMana() << " mp" << std::endl << std::endl;


	std::unique_ptr<Filesystem> file = std::make_unique<Filesystem>();
	savedGames_ = file->listDirectory();
	while (savedGames_.size() < 5){
		savedGames_.push_back("");
	}

	
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
	case Graphic::MENU_GUI_BACK:
		std::cout << "Main Menu" << std::endl << std::endl;
		std::cout << "1. Start game" << std::endl;
		std::cout << "2. Save game" << std::endl;
		std::cout << "3. Load game" << std::endl;
		std::cout << "4. Options" << std::endl;
		std::cout << "5. Exit" << std::endl;
		std::cout << "6. Back" << std::endl;
		break;
	case Graphic::MENU_STORY_GUI:
		std::cout << "You are in a dark room. Torches are burning in a distant corridors." << std::endl;
		std::cout << "The feeling that someone is looking at you makes you tremble, but still... \nYou came here to find the ancient tresure there is no way you turn and go back to your boring life. \nProve yourself in battle and live glorious life as a hero or die." << std::endl << std::endl;
		std::cout << "Where do you want to go?" << std::endl << std::endl;
		std::cout << "1. Turn right" << std::endl;
		std::cout << "2. Turn left" << std::endl;
		std::cout << "3. Inventory" << std::endl;
		std::cout << "4. Menu" << std::endl;
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
	case Graphic::MENU_LOAD_GAME_GUI:
	{
		std::cout << "Save/load game:" << std::endl << std::endl;
		for (unsigned i = 1; i <= savedGames_.size(); i++){
			std::cout << i << ". " << savedGames_[i-1] << std::endl;
		}
		std::cout << "6. Back" << std::endl;
		break;
	}
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
		std::cout << "Encountered enemies: ";
		for (auto character : characters_){
			if (!character->getFriendly()){
				std::cout << character->getName() << ", ";
			}
		}
		std::cout << std::endl;
		break;
	case Graphic::BATTLE_GAME_OVER_GUI:
		std::cout << "...you died" << std::endl << std::endl;
		std::cout << "\t\tGAME OVER" << std::endl << std::endl << std::endl;
		std::cout << "1. Main Menu" << std::endl << std::endl;
		std::cout << "2. Exit game" << std::endl << std::endl;
		break;
	case Graphic::BATTLE_VICTORY_GUI:
		std::cout << "YOU ARE VICTORIOUS!" << std::endl << std::endl;
		std::cout << "Your reward is:" << std::endl;
		std::cout << "\t\t" << loot_->expReward << " experience" << std::endl;
		std::cout << "\t\t" << loot_->goldReward << " gold" << std::endl;
		for (auto& item : loot_->items){
			std::cout << "\t\t" << item << std::endl;
		}
		player_->setExperience(player_->getExperience() + loot_->expReward);

		std::cout << std::endl << "Press any key to continue..." << std::endl;
		break;
	case Graphic::INENTORY_GUI:
		std::cout << "Inventory" << std::endl << std::endl;
		break;
	default:
		break;
	}
}