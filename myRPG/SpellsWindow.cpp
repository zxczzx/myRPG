#include "SpellsWindow.h"

SpellsWindow::SpellsWindow(World* world)
{
	int charSize = 16;
	int width = 160;
	sf::Vector2f screenPos = sf::Vector2f(475, 267);
	setup(8, charSize, width, screenPos);
	this->world = world;

	content.setString("\tSpells:");
	add(content);

	for (unsigned i = 0; i < world->getActor()->getAbilitiesBackpack()->getItems().size(); i++) {
		content.setString(world->getActor()->getAbilitiesBackpack()->getItems()[i]->getName());
		content.setPosition(content.getPosition().x, content.getPosition().y + charSize*1.2f);
		add(content);
	}

	selectedItemIndex = 0;
}

SpellsWindow::~SpellsWindow()
{
}

void SpellsWindow::handleInput(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (selectedItemIndex - 1 > 0)
			{
				messages[selectedItemIndex].setFillColor(sf::Color::White);
				selectedItemIndex--;
				messages[selectedItemIndex].setFillColor(sf::Color::Red);
				std::cout << "up" << std::endl;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (selectedItemIndex + 1 < messages.size())
			{
				messages[selectedItemIndex].setFillColor(sf::Color::White);
				selectedItemIndex++;
				messages[selectedItemIndex].setFillColor(sf::Color::Red);
				std::cout << "down" << std::endl;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			std::cout << messages[selectedItemIndex].getString().toAnsiString() << std::endl;
		}
	}
}
