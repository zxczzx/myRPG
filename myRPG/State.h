#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Game.h"

class State
{
public:
	State();
	~State();

	void setHead(std::shared_ptr<State> myHead);
	void setPrev(std::shared_ptr<State> myPrev);
	void setNext(std::shared_ptr<State> myNext);
	std::shared_ptr<State> getNext();
	std::shared_ptr<Game> getGame();

	virtual void handleInput();
	virtual void handleInput(sf::RenderWindow& window, sf::Event event);
	virtual void render(sf::RenderWindow& window) = 0;

	int getPressedItem();

	template<class T>
	std::shared_ptr<State> newState();

protected:
	std::shared_ptr<State> head;
	std::shared_ptr<State> prev;
	std::shared_ptr<State> next;

	std::shared_ptr<Game> game;

	sf::Font font;
	std::vector<sf::Text> menuEntries;
	int selectedItemIndex;
};

template<class T>
std::shared_ptr<State> State::newState() {
	std::shared_ptr<State> nextState = std::make_shared<T>(sf::Vector2u(800, 600));
	nextState->setHead(nextState);
	nextState->setPrev(head);
	return nextState;
}