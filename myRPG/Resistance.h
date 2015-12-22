#pragma once
class Resistance
{
	double fireImmunity;
	double coldImmunity;
	double waterImmunity;
	double windImmunity;

public:
	Resistance() : fireImmunity(0), coldImmunity(0), waterImmunity(0), windImmunity(0) {}
	~Resistance();

	//getter
	double getFireImmunity();
	double getColdImmunity();
	double getWaterImmunity();
	double getWindImmunity();

	//setter
	void setFireImmunity(double fireImmun);
	void setColdImmunity(double coldImmun);
	void setWaterImmunity(double waterImmun);
	void setWindImmunity(double windImmun);
};

