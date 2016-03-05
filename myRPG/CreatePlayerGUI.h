#pragma once
#include "GUI.h"
class CreatePlayerGUI : public GUI
{
public:
	CreatePlayerGUI();
	~CreatePlayerGUI();

	std::shared_ptr<GUI> handleInput(World& world, int input) override;
	void enter(World& world) override;
	void setName(World& world);
	void chooseClass(World& world);
	template<class T>
	void changeActorClass(World& world);
};

