#pragma once
#include "libraries.h"
#include "GUI.h"

class MainMenu
{
private:
	std::shared_ptr<GUI> gui;

	void startGame();
	void loadGame();
	void exitGame();
	void options();

public:
	MainMenu() : gui(nullptr) {}
	~MainMenu();
	
	//getter
	std::shared_ptr<GUI> getInterface();

	//setter
	void setInterface(std::shared_ptr<GUI> interf);
};

