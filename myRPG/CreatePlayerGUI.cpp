#include "CreatePlayerGUI.h"
#include "StoryGUI.h"
#include "MenuGUI.h"
#include "Warrior.h"
#include "Mage.h"

CreatePlayerGUI::CreatePlayerGUI(){
}

CreatePlayerGUI::~CreatePlayerGUI(){
}

std::shared_ptr<GUI> CreatePlayerGUI::handleInput(Game& game, int input){
	switch (input)
	{
	case 1:	//change name
		game.accum_mutex.lock();
		setName(game);
		game.accum_mutex.unlock();
		return std::make_shared<CreatePlayerGUI>();
	case 2:	//change class
		chooseClass(game);
		return std::make_shared<CreatePlayerGUI>();
	case 3:	//start game
		return std::make_shared<StoryGUI>();
	case 4:	//back
		return std::make_shared<MenuGUI>();
	default:
		break;
	}
}

void CreatePlayerGUI::enter(Game& game){
	Graphic graphic = Graphic::CREATE_PLAYER;
	game.setGraphic(graphic);
}

void CreatePlayerGUI::setName(Game& game){
	//set new graphic
	Graphic graphic = Graphic::CREATE_WRITE_OPTION;
	game.setGraphic(graphic);

	//set new name	
	std::string name;
	std::cin >> name;

	game.getPlayer()->setName(name);
}

void CreatePlayerGUI::chooseClass(Game& game){
	Graphic graphic = Graphic::CREATE_CLASS_OPTION;
	game.setGraphic(graphic);

	//set new name
	int myClass = game.getInput<int>();

	if (myClass == 1){
		changePlayerClass<Warrior>(game);
	}
	else if (myClass == 2){
		changePlayerClass<Mage>(game);
	}
}

template<class T>
void CreatePlayerGUI::changePlayerClass(Game& game){
	std::shared_ptr<Player> player = std::make_shared<T>();
	if (player->getName() == "default"){
		std::string name = game.getPlayer()->getName();
		player->setName(name);
	}
	game.setPlayer(player);
}