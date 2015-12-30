#pragma once
#include "Character.h"
#include "Graphic.h"

class GUI;

class Game
{
private:
	std::shared_ptr<GUI> state_;
	std::unique_ptr<Character> player_;
	std::vector<std::shared_ptr<Character> > enemies_;

public:
	Game();
	~Game();
	bool running;

	virtual void handleInput(int input);
	void setGraphic(Graphic graphic);
};

