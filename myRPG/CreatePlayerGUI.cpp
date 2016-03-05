#include "CreatePlayerGUI.h"
#include "StoryGUI.h"
#include "MenuGUI.h"
#include "ObjectSpawn.h"

CreatePlayerGUI::CreatePlayerGUI(){
}

CreatePlayerGUI::~CreatePlayerGUI(){
}

std::shared_ptr<GUI> CreatePlayerGUI::handleInput(World& world, int input){
	switch (input)
	{
	case 1:	//change name
		world.accum_mutex.lock();
		setName(world);
		world.accum_mutex.unlock();
		return returnProperGUI<CreatePlayerGUI>();
	case 2:	//change class
		chooseClass(world);
		return returnProperGUI<CreatePlayerGUI>();
	case 3:	//start world
		return returnProperGUI<StoryGUI>();
	case 4:	//back
		return prev;
	default:
		break;
	}
}

void CreatePlayerGUI::enter(World& world){
	Graphic graphic = Graphic::CREATE_Actor;
	world.setGraphic(graphic);
}

void CreatePlayerGUI::setName(World& world){
	//set new graphic
	Graphic graphic = Graphic::CREATE_WRITE_OPTION;
	world.setGraphic(graphic);

	//set new name	
	std::string name;
	std::cin >> name;

	world.getActor()->setName(name);
}

void CreatePlayerGUI::chooseClass(World& world){
	Graphic graphic = Graphic::CREATE_CLASS_OPTION;
	world.setGraphic(graphic);
	std::shared_ptr<ObjectSpawn> spawner = std::make_shared<ObjectSpawn>();
	//set new name
	int myClass = world.getInput<int>();

	auto name = world.getActor()->getName();
	if (myClass == 1){
		world.setActor(spawner->spawnActor("Warrior"));
	}
	else if (myClass == 2){
		world.setActor(spawner->spawnActor("Mage"));
	}
	if (name != "default") {
		world.getActor()->setName(name);
	}
}

template<class T>
void CreatePlayerGUI::changeActorClass(World& world){
	std::shared_ptr<Player> player = std::make_shared<T>();
	if (player->getName() == "default"){
		std::string name = world.getActor()->getName();
		player->setName(name);
	}
	world.setActor(player);
}