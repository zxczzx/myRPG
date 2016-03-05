#pragma once
#include "State.h"

class LoadGameState : public State
{
public:
	LoadGameState(sf::Vector2u wind);
	~LoadGameState();

	void handleInput() override;
	void handleInput(sf::RenderWindow& window, sf::Event event) override;
	void render(sf::RenderWindow& window) override;
};

