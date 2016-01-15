#pragma once
#include "Player.h"
#include "Graphic.h"
#include "Loot.h"
#include <mutex>
#include <atomic>

class GUI;

class Game
{
private:
	std::shared_ptr<GUI> state_;
	std::shared_ptr<Player> player_;
	std::shared_ptr<Loot> loot_;
	std::vector<std::shared_ptr<Character> > characters_;
	std::vector<std::string> savedGames_;
	
public:
	Game();
	~Game();

	//thread variables
	bool gotInput;
	std::mutex accum_mutex;
	std::atomic_int atomicAction;

	//getter
	std::shared_ptr<Player> getPlayer();
	std::shared_ptr<Loot> getLoot();
	std::vector<std::shared_ptr<Character> > getCharacters();
	std::vector<std::string> getSavedGames();

	//setter
	void setPlayer(std::shared_ptr<Player> player);
	void setLoot(std::shared_ptr<Loot> myLoot);
	void setCharacters(std::vector<std::shared_ptr<Character> > enemiesList);
	void setGraphicUpdate(std::string inputGraphic);
	void setSavedGames(std::vector<std::string> games);

	//method
	virtual void handleInput(int input);
	void setGraphic(Graphic graphic);
	void initiaviveSort();
	template<typename T>
	int getInput();
};

//Doesn't work if placed in .cpp file...
template<class T>
int Game::getInput(){
	gotInput = false;
	int value;
	while (!gotInput){
		value = atomicAction.load();
	}
	return value;
}

