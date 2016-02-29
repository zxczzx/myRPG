#include "Windows.h"

Windows::Windows()
{
	setup("Window", sf::Vector2u(640, 480));
}

Windows::Windows(const std::string & title, const sf::Vector2u & size)
{
	setup(title, size);
}

Windows::~Windows()
{
	destroy();
}

void Windows::beginDraw()
{
	window.clear(sf::Color::Black);
}

void Windows::endDraw()
{
	window.display();
}

void Windows::update()
{
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			isdone = true;
		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
			isdone = true;
		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5) {
			toggleFullscreen();
		}
	}
}

bool Windows::isDone()
{
	return isdone;
}

bool Windows::isFullscreen()
{
	return isfullscreen;
}

sf::Vector2u Windows::getWindowSize()
{
	return windowSize;
}

sf::RenderWindow* Windows::getRenderWindow()
{
	return &window;
}

void Windows::toggleFullscreen()
{
	isfullscreen = !isfullscreen;
	destroy();
	create();
}

void Windows::draw(sf::Drawable & drawable)
{
	window.draw(drawable);
}

void Windows::setup(const std::string & title, const sf::Vector2u & size)
{
	windowTitle = title;
	windowSize = size;
	isfullscreen = false;
	isdone = false;
	create();
}

void Windows::destroy()
{
	window.close();
}

void Windows::create()
{
	auto style = (isfullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	window.create({ windowSize.x, windowSize.y, 32 }, windowTitle, style);
}
