#pragma once
#include "PlayerWindows.h"

class SpellsWindow : public PlayerWindows
{
public:
	SpellsWindow(World* world);
	~SpellsWindow();

	void handleInput(sf::Event event) override;
};

