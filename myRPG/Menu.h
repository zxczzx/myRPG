#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Menu
{
public:
	Menu(sf::Vector2u wind);
	~Menu();

	void update();
	void render(sf::RenderWindow& window);

	int getPressedItem();

private:
	sf::Font font;
	std::vector<sf::Text> menuEntries;
	int selectedItemIndex;
};

