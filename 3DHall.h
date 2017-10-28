#ifndef  THREEDHALL_H
#define THREEDHALL_H
#include "Hall.h"

//test commit clion

class ThreeDHall : public Hall
{
public:
	ThreeDHall(int hallNumber, double pricePerSeat,bool movingChairs, bool windSensor, bool waterSensor, double priceAddition);
	ThreeDHall(const ThreeDHall & other);
	virtual ~ThreeDHall();
	void setMovingChairs(bool chairs);
	bool getMovingChairs() const;
	void setWindSensor(bool windSensor);
	bool getWindSensor() const;
	void setWaterSensor(bool waterSensor);
	bool getWaterSensor() const;
	void setPriceAddition(double price);

private:
	bool movingChairs;
	bool windSensor;
	bool waterSensor;
};

#endif THREEDHALL_H