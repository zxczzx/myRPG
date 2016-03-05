#pragma once
#include <SFML/Graphics.hpp>
#include "Windows.h"
#include "World.h"

class State;

class Game
{
private:
	Windows window;
	std::shared_ptr<State> state;

	sf::Clock clock;
	float elapsed;
	
public:
	Game();
	~Game();

	//SFML
	void handleInput();
	void update();
	void render();

	sf::Time getElapsed();
	void restartClock();

	std::shared_ptr<World> world;;
	Windows* getWindow();	
};

