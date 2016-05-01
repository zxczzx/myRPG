#include "StoryState.h"
#include "InventoryWindow.h"
#include "EquipmentWindow.h"
#include "SpellsWindow.h"
#include <string>

StoryState::StoryState(sf::Vector2u wind) : State(), window(wind)
{
	inventoryState = false;
}

StoryState::~StoryState()
{
}

void StoryState::handleInput(World& world)
{
	if (inventoryState == false) {
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
	else {
		//menu options
	}
}

void StoryState::handleInput(World& world, sf::RenderWindow & window, sf::Event event)
{
	if (event.type == sf::Event::KeyPressed) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
			inventoryWindow = new InventoryWindow(&world);
			std::cout << inventoryState << " pressed i" << std::endl;
			toggleInventory();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
			inventoryWindow = new EquipmentWindow(&world);
			std::cout << inventoryState << " pressed u" << std::endl;
			toggleInventory();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			inventoryWindow = new SpellsWindow(&world);
			std::cout << inventoryState << " pressed s" << std::endl;
			toggleInventory();
		}
	}
	if (inventoryState == true) {
		inventoryWindow->handleInput(event);
	}
}

void StoryState::update(std::shared_ptr<Player> player)
{
}

void StoryState::render(sf::RenderWindow & window, World& world)
{
	character = world.getActor()->getSprite();
	window.draw(character);
	if (inventoryState == true) {
		inventoryWindow->render(window);
	}
}

void StoryState::toggleInventory()
{
	inventoryState = !inventoryState;
}
