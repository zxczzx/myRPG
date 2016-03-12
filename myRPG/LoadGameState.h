#pragma once
#include "State.h"

class LoadGameState : public State
{
public:
	LoadGameState(sf::Vector2u wind);
	~LoadGameState();

	void handleInput(World& world) override;
	void handleInput(World& world, sf::RenderWindow& window, sf::Event event) override;
	void update(std::shared_ptr<Player> player) override;
	void render(sf::RenderWindow& window, World& world) override;
};

