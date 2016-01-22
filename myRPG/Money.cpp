#include "Money.h"

Money::Money(int count){
	name = "Coin";
	description = count + "x golden coins shining in the sun";
	quantity = count;
	usable = false;
}

Money::~Money(){
}
