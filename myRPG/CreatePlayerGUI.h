#pragma once
#include "GUI.h"
class CreatePlayerGUI : public GUI
{
public:
	CreatePlayerGUI();
	~CreatePlayerGUI();

	std::shared_ptr<GUI> handleInput(Game& game, int input) override;
	void enter(Game& game) override;
	void setName(Game& game);
	void chooseClass(Game& game);
	template<class T>
	void changeActorClass(Game& game);
};

