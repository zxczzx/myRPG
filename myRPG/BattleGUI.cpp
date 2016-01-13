#include "BattleGUI.h"
#include "Enemy.h"
#include "VictoryGUI.h"
#include "GameOverGUI.h"
#include "StoryGUI.h"

BattleGUI::BattleGUI(){
}

BattleGUI::~BattleGUI(){
}

//executeBattle powinno uruchamiaæ siê w metodzie enter po wyœwietleniu grafiki

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

		return returnProperGUI<VictoryGUI>();
	}

	for (auto& character : game.getCharacters()){
		if (character->getFriendly() == true){
			//players turn
			std::cout << "Your turn. " << std::endl;
			std::cout << "> ";
			input = game.getInput<int>();
			switch (input)
			{
			case 1: //attack
			{
				//actions
				std::cout << std::endl << "Choose enemy to attack " << std::endl;
				for (unsigned i = 0; i < enemiesList.size(); i++){
					std::cout << i+1 << ". " << enemiesList[i]->getName() << "\t" << enemiesList[i]->getHitPoints() << " hp" << std::endl;
				}
				std::cout << "> ";
				unsigned enemyNumber;

				//to prevent ArrayOutOfBandsException
				do{
					enemyNumber = game.getInput<int>();
				} while (enemyNumber > enemiesList.size());

				// make dmg to enemy
				game.getPlayer()->attack(enemiesList[enemyNumber - 1]);
				continue;
			}
			case 2: //special ability
				return returnProperGUI<BattleGUI>();
			case 3: //spell
				return returnProperGUI<BattleGUI>();
			case 4: //inventory access
				return returnProperGUI<BattleGUI>();
			case 5: //pass turn
				std::cout << "You passed this turn" << std::endl;
				continue;
			case 6: //retreat
			{
				std::random_device rd;
				std::mt19937 gen(rd());
				std::uniform_int_distribution<> randInit(1, 100);
				int playerRandInit = randInit(gen);
				int playerInit = game.getPlayer()->getInitiative() + playerRandInit;
				for (auto& enemy : enemiesList){
					if (!enemy->isDead()){
						int rand_initiative = randInit(gen);
						if (playerInit < enemy->getInitiative() + rand_initiative){
							return std::make_shared<GameOverGUI>();
						}
					}
				}
				return returnProperGUI<StoryGUI>();
			}
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
				return returnProperGUI<GameOverGUI>(); 
			}
		}
	}

	//remove enemiesList to free up the memory
	enemiesList.clear();
	enemiesList.shrink_to_fit();
	return returnProperGUI<BattleGUI>();
}

void BattleGUI::enter(Game& game){
	Graphic graphic = Graphic::BATTLE_GUI;
	game.setGraphic(graphic);
}