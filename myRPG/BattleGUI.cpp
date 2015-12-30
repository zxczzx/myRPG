#include "BattleGUI.h"


BattleGUI::BattleGUI(){
}

BattleGUI::~BattleGUI(){
}

std::shared_ptr<GUI> BattleGUI::handleInput(Game& game, int input){
	switch (input)
	{
	case 1:
		return std::make_shared<BattleGUI>();
	default:
		return std::make_shared<BattleGUI>();
	}
}

void BattleGUI::enter(Game& game){
	Graphic graphic = Graphic::BATTLE_GUI;
	game.setGraphic(graphic);
}