#include "Money.h"

Money::Money(int count){
	name = "Coin";
	description = "Golden coins shining in the sun";
	quantity = count;
	usable = false;
}

Money::~Money(){
}
