#include "BattleGUI.h"
#include "VictoryGUI.h"
#include "GameOverGUI.h"
#include "StoryGUI.h"
#include "BackpackGUI.h"
#include "SpellsGUI.h"

BattleGUI::BattleGUI(){
	usedPrev = false;
	chosenSpell = std::make_shared<Abilities>();
}

BattleGUI::~BattleGUI(){
}

//executeBattle powinno uruchamiaæ siê po wyœwietleniu grafiki

std::shared_ptr<GUI> BattleGUI::handleInput(World& world, int input){
	world.setGameState(GameState::STATE_BATTLE);

	//create enemy list
	std::vector<std::shared_ptr<Player> > enemiesList;
	for (auto& character : world.getCharacters()){
		if (character->getFriendly() == false && !character->isDead()){
			enemiesList.push_back(std::static_pointer_cast<Player>(character));
		}
	}

	//no enemies player won the battle
	if (enemiesList.size() == 0){
		//add loot
		std::unique_ptr<Loot> loot = std::make_unique<Loot>();
		for (auto& character : world.getCharacters()){
			if (character->isDead()){
				loot->expReward += std::static_pointer_cast<Player>(character)->getExperience();

				//append vector to vector
				for (auto& i : std::static_pointer_cast<Player>(character)->getBackpack()->getItems()) {
					loot->items.push_back(i);
				}
			}
		}
		world.setLoot(std::move(loot));

		//clear table
		loot.reset();
		enemiesList.clear();
		enemiesList.shrink_to_fit();

		return returnProperGUI<VictoryGUI>();
	}

	for (auto& character : world.getCharacters()){
		if (character->getFriendly() == false && usedPrev == true){
			continue;
		}
		//Actors turn
		if (character->getFriendly() == true){
			//spell chosen
			if (chosenSpell->getName() != "default"){
				//actions
				std::cout << std::endl << "Choose enemy to attack " << std::endl;
				for (unsigned i = 0; i < enemiesList.size(); i++){
					std::cout << i + 1 << ". " << enemiesList[i]->getName() << "\t" << enemiesList[i]->getHitPoints() << " hp" << std::endl;
				}
				std::cout << "> ";
				unsigned enemyNumber;

				//to prevent ArrayOutOfBandsException
				do{
					enemyNumber = world.getInput<int>();
				} while (enemyNumber > enemiesList.size());

				// make dmg to enemy
				bool success = chosenSpell->execute(world.getActor(), enemiesList[enemyNumber - 1]);
				if (success){
					usedPrev = false;
					continue;
				}
			}
			//normal turn
			std::cout << "Your turn. " << std::endl;
			std::cout << "> ";
			input = world.getInput<int>();
			switch (input){
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
					enemyNumber = world.getInput<int>();
				} while (enemyNumber > enemiesList.size());

				// make dmg to enemy
				world.getActor()->attack(enemiesList[enemyNumber - 1]);
				usedPrev = false;
				continue;
			}
			case 2: //special ability
				usedPrev = true;
				return returnProperGUI<BattleGUI>();
			case 3: //spell
				usedPrev = true;
				return returnProperGUI<SpellsGUI>();
			case 4: //backpack access
				usedPrev = true;
				return returnProperGUI<BackpackGUI>();
			case 5: //pass turn
				std::cout << "You passed this turn" << std::endl;
				continue;
			case 6: //retreat
			{
				std::random_device rd;
				std::mt19937 gen(rd());
				std::uniform_int_distribution<> randInit(1, 100);
				int ActorRandInit = randInit(gen);
				int ActorInit = world.getActor()->getInitiative() + ActorRandInit;
				for (auto& enemy : enemiesList){
					if (!enemy->isDead()){
						int rand_initiative = randInit(gen);
						if (ActorInit < enemy->getInitiative() + rand_initiative){
							return std::make_shared<GameOverGUI>();
						}
					}
				}
				return returnProperGUI<StoryGUI>();
			}
			default:
				break;
			}
			usedPrev = false;
		}
		else{
			//enemy turn
			if (!character->isDead()){
				character->attack(world.getActor());
			}
			
			//enemy gave the killing blow. Game over
			if (world.getActor()->getHitPoints() <= 0){
				return returnProperGUI<GameOverGUI>(); 
			}
		}
	}

	//remove enemiesList to free up the memory
	enemiesList.clear();
	enemiesList.shrink_to_fit();
	return returnProperGUI<BattleGUI>();
}

void BattleGUI::enter(World& world){
	Graphic graphic = Graphic::BATTLE_GUI;
	world.setGraphic(graphic);
}