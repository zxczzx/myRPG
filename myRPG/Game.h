#pragma once
#include "Player.h"
#include "Graphic.h"

class GUI;

class Game
{
private:
	std::shared_ptr<GUI> state_;
	std::shared_ptr<Player> player_;
	std::vector<std::shared_ptr<Character> > characters_;

public:
	Game();
	~Game();
	bool running;

	//getter
	std::shared_ptr<Player> getPlayer();
	std::vector<std::shared_ptr<Character> > getEnemies();

	//setter
	void setPlayer(std::shared_ptr<Player> player);
	void setEnemies(std::vector<std::shared_ptr<Character> > enemiesList);

	//method
	virtual void handleInput(int input);
	void setGraphic(Graphic graphic);
};

