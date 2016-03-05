#pragma once
#include "State.h"

class MenuState : public State
{
public:
	MenuState(sf::Vector2u wind);
	~MenuState();

	void handleInput() override;
	void handleInput(sf::RenderWindow& window, sf::Event event) override;
	void render(sf::RenderWindow& window) override;
};

