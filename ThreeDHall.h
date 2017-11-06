#ifndef  THREEDHALL_H
#define THREEDHALL_H

#include <ostream>
#include "Hall.h"

//test commit clion

class ThreeDHall : public Hall
{
protected:
	bool movingChairs;
	bool windSensor;
	bool waterSensor;
	double extraPrice;
public:


	ThreeDHall(int hallNumber, double pricePerSeat, int numOfRows, int numOfSeatsPerRow);

	~ThreeDHall() override = default;
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

	void toOs(std::ostream& os) const;
};

#endif