#include "Resistance.h"

Resistance::~Resistance(){
}

//GETTERS
int Resistance::getFireImmunity(){
	return fireImmunity;
}

int Resistance::getColdImmunity(){
	return coldImmunity;
}

int Resistance::getWaterImmunity(){
	return waterImmunity;
}

int Resistance::getElectricityImmunity(){
	return electricityImmunity;
}

//SETTERS
void Resistance::setFireImmunity(int fireImmun){
	fireImmunity = fireImmun;
}

void Resistance::setColdImmunity(int coldImmun){
	coldImmunity = coldImmun;
}

void Resistance::setWaterImmunity(int waterImmun){
	waterImmunity = waterImmun;
}

void Resistance::setElectricityImmunity(int windImmun){
	electricityImmunity = windImmun;
}

