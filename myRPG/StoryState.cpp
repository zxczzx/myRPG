#include "StoryState.h"

StoryState::StoryState(sf::Vector2u wind) : window(wind)
{
}

StoryState::~StoryState()
{
}

void StoryState::handleInput(World& world)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (character.getPosition().y > 0) {
			character.setPosition(character.getPosition().x, character.getPosition().y - 1);
		}
		std::cout << "pressed up x: " << character.getPosition().x << " y: " << character.getPosition().y << std::endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (character.getPosition().y < this->window.y - character.getGlobalBounds().height) {
			character.setPosition(character.getPosition().x, character.getPosition().y + 1);
		}
		std::cout << "pressed down x: " << character.getPosition().x << " y: " << character.getPosition().y << std::endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (character.getPosition().x < this->window.x - character.getGlobalBounds().width) {
			character.setPosition(character.getPosition().x + 1, character.getPosition().y);
		}
		std::cout << "pressed right x: " << character.getPosition().x << " y: " << character.getPosition().y << std::endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (character.getPosition().x > 0) {
			character.setPosition(character.getPosition().x - 1, character.getPosition().y);
		}
		std::cout << "pressed left x: " << character.getPosition().x << " y: " << character.getPosition().y << std::endl;
	}
	world.getActor()->setSprite(character);
}

void StoryState::handleInput(World& world, sf::RenderWindow & window, sf::Event event)
{
}

void StoryState::update(std::shared_ptr<Player> player)
{
}

void StoryState::render(sf::RenderWindow & window, World& world)
{
	character = world.getActor()->getSprite();
	window.draw(character);
}
