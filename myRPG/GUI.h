#pragma once
#include "libraries.h"


class GUI
{
protected:
	std::shared_ptr<GUI> nextGUI;

public:
	GUI();
	~GUI();

	//getter
	std::shared_ptr<GUI> getNextGUI();

	//setter
	void setNextGUI(std::shared_ptr<GUI> next);

	//method
	virtual void printScreen() = 0;
	virtual void interaction(int action) = 0;
};

