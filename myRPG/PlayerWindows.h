#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "World.h"

using MessageContainer = std::vector<sf::Text>;

class PlayerWindows
{
public:
	PlayerWindows();
	PlayerWindows(World* world);
	~PlayerWindows();

	void render(sf::RenderWindow& window);
	virtual void handleInput(sf::Event event);
	void setup(int visible, int charSize, int width, sf::Vector2f screenPos);
	void clear();
	void add(sf::Text message);

protected:
	int width;
	int charSize;
	sf::Vector2f screenPos;
	MessageContainer messages;
	int numVisible;
	sf::RectangleShape backdrop;
	sf::Font font;
	sf::Text content;
	World* world;
	int selectedItemIndex;
};

