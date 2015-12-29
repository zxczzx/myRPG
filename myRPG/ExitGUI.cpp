#include "ExitGUI.h"

ExitGUI::~ExitGUI(){
}

bool ExitGUI::interaction(int action, std::shared_ptr<GUI>& nextGUI){
	switch (action){
	case 1:
		return false;
	case 2:
		return true;
	default:
		return true;
	}
}

void ExitGUI::printScreen(){
	std::cout << "Do you really want to quit?" << std::endl;
	std::cout << "1. Yes" << std::endl;
	std::cout << "2. No" << std::endl;
}