#include "Resistance.h"

Resistance::~Resistance(){
}

//GETTERS
double Resistance::getFireImmunity(){
	return fireImmunity;
}

double Resistance::getColdImmunity(){
	return coldImmunity;
}

double Resistance::getWaterImmunity(){
	return waterImmunity;
}

double Resistance::getWindImmunity(){
	return windImmunity;
}

//SETTERS
void Resistance::setFireImmunity(double fireImmun){
	fireImmunity = fireImmun;
}

void Resistance::setColdImmunity(double coldImmun){
	coldImmunity = coldImmun;
}

void Resistance::setWaterImmunity(double waterImmun){
	waterImmunity = waterImmun;
}

void Resistance::setWindImmunity(double windImmun){
	windImmunity = windImmun;
}

