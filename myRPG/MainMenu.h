#pragma once
#include "MenuGUI.h"

class MainMenu
{
private:
	std::shared_ptr<GUI> gui;

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

