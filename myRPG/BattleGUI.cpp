#include "BattleGUI.h"


BattleGUI::BattleGUI(){
}

BattleGUI::~BattleGUI(){
}

std::shared_ptr<GUI> BattleGUI::handleInput(Game& game, int input){
	for (auto character : game.getCharacters()){
		if (character->getFriendly() == true){
			//players turn
			switch (input)
			{
			case 1: //attack
				//actions
				continue;
				return std::make_shared<BattleGUI>();
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
			//enemies turn
		}
	}
	return std::make_shared<BattleGUI>();
}

void BattleGUI::enter(Game& game){
	Graphic graphic = Graphic::BATTLE_GUI;
	game.setGraphic(graphic);
}