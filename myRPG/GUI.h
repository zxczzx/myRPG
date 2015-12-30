#pragma once
#include "libraries.h"
#include "Game.h"

class GUI
{
public:
	GUI();
	~GUI();

	virtual std::shared_ptr<GUI> handleInput(Game& game, int input) = 0;
	virtual void enter(Game& game) = 0;
};

