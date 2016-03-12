#include "State.h"

State::State()
{
	head = nullptr;
	prev = nullptr;
	next = head;
	selectedItemIndex = 0;
}

State::~State()
{
}

void State::setHead(std::shared_ptr<State> myHead) {
	head = myHead;
}

void State::setPrev(std::shared_ptr<State> myPrev) {
	prev = myPrev;
}

void State::setNext(std::shared_ptr<State> myNext)
{
	next = myNext;
}

std::shared_ptr<State> State::getNext()
{
	if (next) {
		next->setNext(nullptr);
	}
	return next;
}

std::shared_ptr<Game> State::getGame()
{
	return game;
}

//Real-Time input
void State::handleInput(World& world)
{
}

//Events input
void State::handleInput(World& world, sf::RenderWindow& window, sf::Event event)
{
}

void State::update(std::shared_ptr<Player> player)
{
}

void State::render(sf::RenderWindow & window, World & world)
{
}

int State::getPressedItem()
{
	return selectedItemIndex;
}