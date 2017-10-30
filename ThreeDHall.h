#ifndef  THREEDHALL_H
#define THREEDHALL_H

#include <ostream>
#include "Hall.h"

//test commit clion

class ThreeDHall : public Hall
{
public:


	ThreeDHall(int hallNumber, double pricePerSeat, int numOfRows, int numOfSeatsPerRow);

	virtual ~ThreeDHall();
	void setMovingChairs(bool chairs);
	bool getMovingChairs() const;
	void setWindSensor(bool windSensor);
	bool getWindSensor() const;
	void setWaterSensor(bool waterSensor);
	bool getWaterSensor() const;
	void setPriceAddition(double price);

	bool isMovingChairs() const;

	bool isWindSensor() const;

	bool isWaterSensor() const;

	double getPrice() const;

	void setPrice(double price);

	friend std::ostream &operator<<(std::ostream &os, const ThreeDHall &hall);

protected:
	bool movingChairs;
	bool windSensor;
	bool waterSensor;
	double extraPrice;
};

#endif THREEDHALL_H