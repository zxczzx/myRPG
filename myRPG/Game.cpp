#include "Game.h"
#include "MenuState.h"

Game::Game() : window("myRPG", sf::Vector2u(800, 600)), state(std::make_shared<MenuState>(sf::Vector2u(800, 600))){
	state->setPrev(nullptr);
	state->setHead(state);

	clock.restart();
	elapsed = 0.0f;
}

Game::~Game(){
}

//SFML
void Game::handleInput()
{
	state->handleInput(world);
}

void Game::update()
{
	if (state->getNext() != nullptr) {
		state = state->getNext();
	}
	while (window.getRenderWindow()->pollEvent(window.event)) {
		window.update();
		state->handleInput(world, *window.getRenderWindow(), window.event);
	}
	state->update(world.getActor());
}

void Game::render()
{
	window.beginDraw();
	//what to draw
	state->render(*window.getRenderWindow(), world);
	window.endDraw();
}

sf::Time Game::getElapsed()
{
	return clock.getElapsedTime();
}

void Game::restartClock()
{
	elapsed += clock.restart().asSeconds();
}


Windows* Game::getWindow()
{
	return &window;
}
