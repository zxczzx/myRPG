#include <windows.h>
#include "BattleGUI.h"
#include "Enemy.h"

BattleGUI::BattleGUI(){
}

BattleGUI::~BattleGUI(){
}

std::shared_ptr<GUI> BattleGUI::handleInput(Game& game, int input){
	//create enemy list
	std::vector<std::shared_ptr<Enemy> > enemiesList;
	for (auto& character : game.getCharacters()){
		if (character->getFriendly() == false){
			enemiesList.push_back(std::static_pointer_cast<Enemy>(character));
		}
	}

	for (auto& character : game.getCharacters()){
		if (character->getFriendly() == true){
			//players turn
			switch (input)
			{
			case 1: //attack
			{
				//actions
				std::cout << std::endl;
				for (unsigned i = 0; i < enemiesList.size(); i++){
					std::cout << i+1 << ". " << enemiesList[i]->getName() << "\t" << enemiesList[i]->getHitPoints() << " hp" << std::endl;
				}
				int enemyNumber = 0;
				std::cout << "> ";
				std::cin >> enemyNumber;
				// make dmg to enemy
				enemiesList[enemyNumber - 1]->setHitPoints(enemiesList[enemyNumber - 1]->getHitPoints() - game.getPlayer()->getDamage());
				std::cout << "You attacked " << enemiesList[enemyNumber - 1]->getName() << " for " << character->getDamage() << " dmg" << std::endl;
				Sleep(2000);
				continue;
			}
			case 2: //special ability
				return std::make_shared<BattleGUI>();
			case 3: //spell
				return std::make_shared<BattleGUI>();
			case 4: //inventory access
				return std::make_shared<BattleGUI>();
			case 5: //pass turn
				return std::make_shared<BattleGUI>();
			case 6: //retreat
				return std::make_shared<BattleGUI>();
			default:
				break;
			}
		}
		else{
			//enemy turn
			game.getPlayer()->setHitPoints(game.getPlayer()->getHitPoints() - character->getDamage());
			//attack
			std::cout << character->getName() << " attacked you for " << character->getDamage() << " dmg" << std::endl;
			//wait 1,5 sec
			Sleep(2000);
		}
	}
	return std::make_shared<BattleGUI>();
}

void BattleGUI::enter(Game& game){
	Graphic graphic = Graphic::BATTLE_GUI;
	game.setGraphic(graphic);
}