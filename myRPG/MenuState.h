#pragma once
#include "State.h"

class MenuState : public State
{
public:
	MenuState(sf::Vector2u wind);
	~MenuState();

	void handleInput(World& world) override;
	void handleInput(World& world, sf::RenderWindow& window, sf::Event event) override;
	void update(std::shared_ptr<Player> player) override;
	void render(sf::RenderWindow& window, World& world) override;
};

