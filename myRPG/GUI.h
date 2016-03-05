#pragma once
#include "libraries.h"
#include "World.h"

class GUI
{
protected:
	std::shared_ptr<GUI> head;
	std::shared_ptr<GUI> prev;

public:
	GUI();
	~GUI();

	//setters
	void setHead(std::shared_ptr<GUI> myHead);
	void setPrev(std::shared_ptr<GUI> myPrev);

	virtual std::shared_ptr<GUI> handleInput(World& world, int input) = 0;
	virtual void enter(World& world) = 0;

	template<class T>
	std::shared_ptr<GUI> returnProperGUI();
};

// doesn't work outside .h file
template<class T>
std::shared_ptr<GUI> GUI::returnProperGUI(){
	std::shared_ptr<T> nextGUI = std::make_shared<T>();
	nextGUI->setHead(nextGUI);
	nextGUI->setPrev(head);
	return nextGUI;
}
