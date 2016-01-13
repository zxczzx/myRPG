#include "GUI.h"


GUI::GUI(){
	head = nullptr;
	prev = nullptr;
}


GUI::~GUI(){
}

//SETTERS

void GUI::setHead(std::shared_ptr<GUI> myHead){
	head = myHead;
}

void GUI::setPrev(std::shared_ptr<GUI> myPrev){
	prev = myPrev;
}