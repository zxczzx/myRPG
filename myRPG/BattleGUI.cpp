#include "BattleGUI.h"
#include "Enemy.h"
#include "VictoryGUI.h"
#include "GameOverGUI.h"

BattleGUI::BattleGUI(){
}

BattleGUI::~BattleGUI(){
}

std::shared_ptr<GUI> BattleGUI::handleInput(Game& game, int input){
	//create enemy list
	std::vector<std::shared_ptr<Enemy> > enemiesList;
	for (auto& character : game.getCharacters()){
		if (character->getFriendly() == false && !character->isDead()){
			enemiesList.push_back(std::static_pointer_cast<Enemy>(character));
		}
	}
	
	//no enemies player won the battle
	if (enemiesList.size() == 0){
		//add loot
		std::unique_ptr<Loot> loot = std::make_unique<Loot>();
		for (auto& character : game.getCharacters()){
			if (character->isDead()){
				loot->expReward += std::static_pointer_cast<Enemy>(character)->getLoot()->expReward;
				loot->goldReward += std::static_pointer_cast<Enemy>(character)->getLoot()->goldReward;

				//append vector to vector
				loot->items.insert(std::end(loot->items), 
					std::begin(std::static_pointer_cast<Enemy>(character)->getLoot()->items), 
					std::end(std::static_pointer_cast<Enemy>(character)->getLoot()->items)
				);
			}
		}
		game.setLoot(std::move(loot));

		//clear table
		loot.reset();
		enemiesList.clear();
		enemiesList.shrink_to_fit();

		return std::make_shared<VictoryGUI>();
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
				int enemyNumber;
				std::cout << "> ";
				std::cin >> enemyNumber;
				// make dmg to enemy
				game.getPlayer()->attack(enemiesList[enemyNumber - 1]);
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
			if (!character->isDead()){
				character->attack(game.getPlayer());
			}
			
			//enemy gave the killing blow. Game over
			if (game.getPlayer()->getHitPoints() <= 0){
				return std::make_shared<GameOverGUI>();
			}
		}
	}

	//remove enemiesList to free up the memory
	enemiesList.clear();
	enemiesList.shrink_to_fit();
	return std::make_shared<BattleGUI>();
}

void BattleGUI::enter(Game& game){
	Graphic graphic = Graphic::BATTLE_GUI;
	game.setGraphic(graphic);
}