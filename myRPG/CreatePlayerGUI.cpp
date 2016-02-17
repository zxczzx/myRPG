#include "CreatePlayerGUI.h"
#include "StoryGUI.h"
#include "MenuGUI.h"
#include "ObjectSpawn.h"

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
		return returnProperGUI<CreatePlayerGUI>();
	case 2:	//change class
		chooseClass(game);
		return returnProperGUI<CreatePlayerGUI>();
	case 3:	//start game
		return returnProperGUI<StoryGUI>();
	case 4:	//back
		return prev;
	default:
		break;
	}
}

void CreatePlayerGUI::enter(Game& game){
	Graphic graphic = Graphic::CREATE_Actor;
	game.setGraphic(graphic);
}

void CreatePlayerGUI::setName(Game& game){
	//set new graphic
	Graphic graphic = Graphic::CREATE_WRITE_OPTION;
	game.setGraphic(graphic);

	//set new name	
	std::string name;
	std::cin >> name;

	game.getActor()->setName(name);
}

void CreatePlayerGUI::chooseClass(Game& game){
	Graphic graphic = Graphic::CREATE_CLASS_OPTION;
	game.setGraphic(graphic);
	std::shared_ptr<ObjectSpawn> spawner = std::make_shared<ObjectSpawn>();
	//set new name
	int myClass = game.getInput<int>();

	auto name = game.getActor()->getName();
	if (myClass == 1){
		game.setActor(spawner->spawnActor("Warrior"));
	}
	else if (myClass == 2){
		game.setActor(spawner->spawnActor("Mage"));
	}
	if (name != "default") {
		game.getActor()->setName(name);
	}
}

template<class T>
void CreatePlayerGUI::changeActorClass(Game& game){
	std::shared_ptr<Actor> actor = std::make_shared<T>();
	if (actor->getName() == "default"){
		std::string name = game.getActor()->getName();
		actor->setName(name);
	}
	game.setActor(actor);
}