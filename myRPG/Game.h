#pragma once
#include "Player.h"
#include "Graphic.h"
#include "Loot.h"

class GUI;

class Game
{
private:
	std::shared_ptr<GUI> state_;
	std::shared_ptr<Player> player_;
	std::shared_ptr<Loot> loot_;
	std::vector<std::shared_ptr<Character> > characters_;
	
public:
	Game();
	~Game();

	//getter
	std::shared_ptr<Player> getPlayer();
	std::shared_ptr<Loot> getLoot();
	std::vector<std::shared_ptr<Character> > getCharacters();

	//setter
	void setPlayer(std::shared_ptr<Player> player);
	void setLoot(std::shared_ptr<Loot> myLoot);
	void setCharacters(std::vector<std::shared_ptr<Character> > enemiesList);
	void setGraphicUpdate(std::string inputGraphic);

	//method
	virtual void handleInput(int input);
	void setGraphic(Graphic graphic);
	void initiaviveSort();
};

