#include "LoadGameState.h"
#include "World.h"
#include "Filesystem.h"
#include <iostream>

LoadGameState::LoadGameState(sf::Vector2u wind) : State()
{
	font.loadFromFile("arial.ttf");

	sf::Text text;
	text.setFont(font);

	text.setColor(sf::Color::Red);
	text.setString("Back");
	menuEntries.push_back(text);

	text.setColor(sf::Color::White);

	std::unique_ptr<Filesystem> file = std::make_unique<Filesystem>();
	auto savedGames = file->listDirectory();

	for (unsigned i = 1; i <= savedGames.size(); i++) {
		std::cout << i << ". " << savedGames[i - 1] << std::endl;
	}

	float height = wind.y / 3;
	for (unsigned i = 0; i < menuEntries.size(); i++) {
		height += menuEntries[i].getLocalBounds().height + 20;
		menuEntries[i].setPosition(
			sf::Vector2f(wind.x / 2 - menuEntries[i].getLocalBounds().width / 2,
				height)
			);
	}

	selectedItemIndex = 0;
}

LoadGameState::~LoadGameState()
{
}

void LoadGameState::handleInput()
{
}

void LoadGameState::handleInput(sf::RenderWindow& window, sf::Event event)
{

	if (event.type == sf::Event::KeyPressed) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (selectedItemIndex - 1 >= 0)
			{
				menuEntries[selectedItemIndex].setColor(sf::Color::White);
				selectedItemIndex--;
				menuEntries[selectedItemIndex].setColor(sf::Color::Red);
				std::cout << "up" << std::endl;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (selectedItemIndex + 1 < menuEntries.size())
			{
				menuEntries[selectedItemIndex].setColor(sf::Color::White);
				selectedItemIndex++;
				menuEntries[selectedItemIndex].setColor(sf::Color::Red);
				std::cout << "down" << std::endl;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			std::cout << menuEntries[selectedItemIndex].getString().toAnsiString() << std::endl;
			if (menuEntries[selectedItemIndex].getString().toAnsiString() == "Back") {
				next = prev;
			}
		}

	}
}

void LoadGameState::render(sf::RenderWindow & window)
{
	for (auto& i : menuEntries) {
		window.draw(i);
	}
}