#include "Menu.h"
#include <iostream>

Menu::Menu(sf::Vector2u wind)
{
	font.loadFromFile("arial.ttf");

	sf::Text text;
	text.setFont(font);
	text.setColor(sf::Color::Red);

	text.setString("Start game");
	text.setPosition(sf::Vector2f(wind.y / 2, wind.x / 6 * 1));
	menuEntries.push_back(text);

	text.setColor(sf::Color::White);
	text.setString("Load game");
	text.setPosition(sf::Vector2f(wind.y / 2, wind.x / 6 * 2));
	menuEntries.push_back(text);

	text.setString("Exit");
	text.setPosition(sf::Vector2f(wind.y / 2, wind.x / 6 * 3));
	menuEntries.push_back(text);

	selectedItemIndex = 0;
}

Menu::~Menu()
{
}

int Menu::getPressedItem()
{
	return selectedItemIndex;
}

void Menu::update()
{
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
		if (selectedItemIndex + 1 < 3)
		{
			menuEntries[selectedItemIndex].setColor(sf::Color::White);
			selectedItemIndex++;
			menuEntries[selectedItemIndex].setColor(sf::Color::Red);
			std::cout << "down" << std::endl;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
		std::cout << menuEntries[selectedItemIndex].getString().toAnsiString() << std::endl;
	}
}

void Menu::render(sf::RenderWindow & window)
{
	for (auto& i : menuEntries) {
		window.draw(i);
	}
}

