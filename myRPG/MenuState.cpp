#include "MenuState.h"
#include "LoadGameState.h"
#include <iostream>

MenuState::MenuState(sf::Vector2u wind) : State() {
	font.loadFromFile("arial.ttf");

	sf::Text text;
	text.setFont(font);

	text.setColor(sf::Color::Red);
	text.setString("Start game");
	menuEntries.push_back(text);

	text.setColor(sf::Color::White);
	if (prev != nullptr) { // != StoryMode
		text.setString("Save game");
		menuEntries.push_back(text);
	}

	text.setString("Load game");
	menuEntries.push_back(text);

	text.setString("Exit");
	menuEntries.push_back(text);

	if (prev != nullptr) {
		text.setString("Back");
		menuEntries.push_back(text);
	}
	
	float height = wind.y / 3 ;
	for (unsigned i = 0; i < menuEntries.size(); i++) {
		height += menuEntries[i].getLocalBounds().height + 20;
		menuEntries[i].setPosition(
			sf::Vector2f(wind.x / 2 - menuEntries[i].getLocalBounds().width / 2,
			height)
			);
	}

	selectedItemIndex = 0;
}

MenuState::~MenuState()
{
}

void MenuState::handleInput()
{
}

void MenuState::handleInput(sf::RenderWindow& window, sf::Event event)
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
			if (menuEntries[selectedItemIndex].getString().toAnsiString() == "Load game") {
				next = newState<LoadGameState>();
			}
		}

	}
}

void MenuState::render(sf::RenderWindow & window)
{
	for (auto& i : menuEntries) {
		window.draw(i);
	}
}