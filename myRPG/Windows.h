#pragma once
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Windows
{
public:
	Windows();
	Windows(const std::string& title, const sf::Vector2u& size);
	~Windows();

	void beginDraw();
	void endDraw();
	void update();
	bool isDone();
	bool isFullscreen();
	sf::Vector2u getWindowSize();
	sf::RenderWindow* getRenderWindow();
	void toggleFullscreen();
	void draw(sf::Drawable& drawable);

private:
	void setup(const std::string& title, const sf::Vector2u& size);
	void destroy();
	void create();

	sf::RenderWindow window;
	sf::Vector2u windowSize;
	std::string windowTitle;
	bool isdone;
	bool isfullscreen;
};

