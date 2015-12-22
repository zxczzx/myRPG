#include "GUI.h"


GUI::GUI(){
}


GUI::~GUI(){
}

//GETTERS
std::shared_ptr<GUI> GUI::getNextGUI(){
	return nextGUI;
}

//SETTERS
void GUI::setNextGUI(std::shared_ptr<GUI> next){
	nextGUI = next;
}