#pragma once
class Resistance
{
	int fireImmunity;
	int coldImmunity;
	int waterImmunity;
	int electricityImmunity;

public:
	Resistance() : fireImmunity(0), coldImmunity(0), waterImmunity(0), electricityImmunity(0) {}
	~Resistance();

	//getter
	int getFireImmunity();
	int getColdImmunity();
	int getWaterImmunity();
	int getElectricityImmunity();

	//setter
	void setFireImmunity(int fireImmun);
	void setColdImmunity(int coldImmun);
	void setWaterImmunity(int waterImmun);
	void setElectricityImmunity(int elecImmun);
};

