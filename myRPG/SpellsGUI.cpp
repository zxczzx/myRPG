#include "SpellsGUI.h"
#include "BattleGUI.h"

SpellsGUI::SpellsGUI(){
}

SpellsGUI::~SpellsGUI(){
}

std::shared_ptr<GUI> SpellsGUI::handleInput(World& world, int input){
	if (input == 1){	//back
		return prev;
	}
	else if (input < world.getActor()->getAbilitiesBackpack()->getItems().size() + 2 && input > 1) {	//item id choice
		auto chosenSpell = world.getActor()->getAbilitiesBackpack()->getItems()[input - 2];
		if (world.getGameState() == GameState::STATE_BATTLE){
			std::static_pointer_cast<BattleGUI>(prev)->chosenSpell = chosenSpell;
			return prev;
		}
		else{
			spellAction(world, chosenSpell);
		}
	}
}

void SpellsGUI::enter(World& world){
	Graphic graphic = Graphic::INVENTORY_SPELLS;
	world.setGraphic(graphic);
}

void SpellsGUI::spellAction(World& world, std::shared_ptr<Abilities> item){
	enter(world);
	std::cout << std::endl;
	std::cout << "\t" << item->getName() << std::endl
		<< item->getDescription() << std::endl
		<< "Dmg: \t" << item->getDamage() << std::endl
		<< "MP: \t" << item->getManaConsumption() << std::endl;
}
