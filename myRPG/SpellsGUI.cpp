#include "SpellsGUI.h"
#include "BattleGUI.h"

SpellsGUI::SpellsGUI(){
}

SpellsGUI::~SpellsGUI(){
}

std::shared_ptr<GUI> SpellsGUI::handleInput(Game& game, int input){
	if (input == 1){	//back
		return prev;
	}
	else if (input < game.getActor()->getAbilitiesBackpack()->getItems().size() + 2 && input > 1) {	//item id choice
		auto chosenSpell = game.getActor()->getAbilitiesBackpack()->getItems()[input - 2];
		if (game.getGameState() == GameState::STATE_BATTLE){
			std::static_pointer_cast<BattleGUI>(prev)->chosenSpell = chosenSpell;
			return prev;
		}
		else{
			spellAction(game, chosenSpell);
		}
	}
}

void SpellsGUI::enter(Game& game){
	Graphic graphic = Graphic::INVENTORY_SPELLS;
	game.setGraphic(graphic);
}

void SpellsGUI::spellAction(Game& game, std::shared_ptr<Abilities> item){
	enter(game);
	std::cout << std::endl;
	std::cout << "\t" << item->getName() << std::endl
		<< item->getDescription() << std::endl
		<< "Dmg: \t" << item->getDamage() << std::endl
		<< "MP: \t" << item->getManaConsumption() << std::endl;
}
