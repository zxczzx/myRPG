#pragma once
#include "MenuGUI.h"
#include "Character.h"

class MainMenu
{
private:
	std::shared_ptr<GUI> gui;
	std::unique_ptr<Character> player;
	std::vector<std::shared_ptr<Character> > enemies;

public:
	MainMenu() : gui(nullptr) {}
	~MainMenu();
	
	//getter
	std::shared_ptr<GUI> getInterface();

	//setter
	void setInterface(std::shared_ptr<GUI> interf);

	//method
	void start();
	static void cls();
};

