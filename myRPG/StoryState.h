#pragma once
#include "State.h"

class StoryState : public State
{
public:
	StoryState(sf::Vector2u wind);
	~StoryState();

	void handleInput(World& world) override;
	void handleInput(World& world, sf::RenderWindow& window, sf::Event event) override;
	void update(std::shared_ptr<Player> player) override;
	void render(sf::RenderWindow& window, World& world) override;

private:
	sf::Vector2f window;
	sf::Sprite character;
};

