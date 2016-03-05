#include "SaveGameGUI.h"

SaveGameGUI::SaveGameGUI(){
}

SaveGameGUI::~SaveGameGUI(){
}

std::shared_ptr<GUI> SaveGameGUI::handleInput(World& world, int input){
	std::string name;
	std::string choice;
	std::shared_ptr<Filesystem> filesystem = std::make_shared<Filesystem>();
	switch (input)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		if (world.getSavedGames()[input - 1] != ""){
			std::cout << "Do you wish to override this file? (yes/no)" << std::endl;
			std::cin >> choice;
			if (choice == "yes"){
				saveGame(world, filesystem, world.getSavedGames()[input - 1]);
				std::cout << "Game saved" << std::endl;
			}
			else{
				return prev;
			}
		}
		else{
			std::cout << "Your save name: " << std::endl;
			std::cin >> name;
			saveGame(world, filesystem, name);
			std::cout << "Game saved" << std::endl;
		}
	case 6:
		return prev;
	default:
		break;
	}
}

void SaveGameGUI::enter(World& world){
	Graphic graphic = Graphic::MENU_LOAD_GAME_GUI;
	world.setGraphic(graphic);
}

void SaveGameGUI::saveGame(World& world, std::shared_ptr<Filesystem> filesystem, std::string filename){
	//helper lambdas
	auto getSlot = [&](ItemSlot slot) {
		return world.getActor()->BodySlots[slot] == nullptr ? "0" : "\"" + world.getActor()->BodySlots[slot]->getName() + "\"";
	};

	auto makeVector = [](std::string str){
		return std::vector<std::string>(1, str);
	};
	//maps
	std::map<std::string, std::vector<std::string> > stats{
		{ "name", makeVector(world.getActor()->getName()) },
		{ "class", makeVector(world.getActor()->getClassType()) },
		{ "level", makeVector(std::to_string(world.getActor()->getLevel())) },
		{ "exp", makeVector(std::to_string(world.getActor()->getExperience())) },
		{ "init", makeVector(std::to_string(world.getActor()->getRealInitiative())) },
		{ "hp", makeVector(std::to_string(world.getActor()->getHitPoints())) },
		{ "maxHP", makeVector(std::to_string(world.getActor()->getRealHitPoints())) },
		{ "mp", makeVector(std::to_string(world.getActor()->getMana())) },
		{ "maxMP", makeVector(std::to_string(world.getActor()->getRealMana())) },
		{ "damage", makeVector(std::to_string(world.getActor()->getRealDamage())) },
		{ "armor", makeVector(std::to_string(world.getActor()->getRealArmor())) },
		{ "friendly", makeVector(std::to_string(world.getActor()->getFriendly())) },
		{ "hpGrowth", makeVector(std::to_string(world.getActor()->getHpGrowth())) },
		{ "mpGrowth", makeVector(std::to_string(world.getActor()->getMpGrowth())) },
		{ "dmgGrowth", makeVector(std::to_string(world.getActor()->getDmgGrowth())) },

	};

	std::map<std::string, std::vector<std::string> > equipment{
		{ "head", makeVector(getSlot(ItemSlot::HEAD)) },
		{ "body", makeVector(getSlot(ItemSlot::BODY)) },
		{ "legs", makeVector(getSlot(ItemSlot::LEGS)) },
		{ "feet", makeVector(getSlot(ItemSlot::FEET)) },
		{ "shoulders", makeVector(getSlot(ItemSlot::SHOULDERS)) },
		{ "gloves", makeVector(getSlot(ItemSlot::GLOVES)) },
		{ "mainhand", makeVector(getSlot(ItemSlot::MAIN_HAND)) },
		{ "offhand", makeVector(getSlot(ItemSlot::OFFHAND)) },
	};
	//change name
	if (filename.find(".save") == std::string::npos){
		filename = filename + ".save";
	}
	//execute
	filesystem->writeToFile(stats, equipment, world.getActor()->getBackpack()->getItems(), 
		world.getActor()->getAbilitiesBackpack()->getItems(), world.getActor()->getResistance(), filename);
}