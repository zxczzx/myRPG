#include "PlayerWindows.h"

PlayerWindows::PlayerWindows()
{
}

PlayerWindows::PlayerWindows(World* world)
{
	int width = 200;
	int charsize = 9;
	setup(5, charsize, width, sf::Vector2f(0, 0));
	this->world = world;
}

PlayerWindows::~PlayerWindows()
{
	clear();
}

void PlayerWindows::render(sf::RenderWindow& window)
{
	window.draw(backdrop);
	for (auto& i : messages) {
		window.draw(i);
	}
}

void PlayerWindows::handleInput(sf::Event event)
{
}

void PlayerWindows::setup(int visible, int charSize, int width, sf::Vector2f screenPos)
{
	numVisible = visible;
	sf::Vector2f offset(2.0f, 8.0f);

	font.loadFromFile("arial.ttf");
	content.setFont(font);
	content.setString("");
	content.setCharacterSize(charSize);
	content.setFillColor(sf::Color::White);
	content.setPosition(screenPos + offset + sf::Vector2f(width / 2 - 60, offset.y));

	backdrop.setSize(sf::Vector2f(width, (visible * (charSize * 1.2f))));
	backdrop.setFillColor(sf::Color(90, 90, 90, 90));
	backdrop.setPosition(screenPos);
}

void PlayerWindows::clear()
{
	messages.clear();
}

void PlayerWindows::add(sf::Text message)
{
	messages.push_back(message);
}
