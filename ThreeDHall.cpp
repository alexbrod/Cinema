#include "ThreeDHall.h"

ThreeDHall::ThreeDHall(int hallNumber, double pricePerSeat, int numOfRows, int numOfSeatsPerRow) :
        Hall(hallNumber, pricePerSeat, numOfRows, numOfSeatsPerRow)
{
    setMovingChairs(true);
    setWaterSensor(false);
    setPriceAddition(20);
    setWindSensor(false);
}

bool ThreeDHall::isMovingChairs() const
{
    return movingChairs;
}

bool ThreeDHall::isWindSensor() const
{
    return windSensor;
}

bool ThreeDHall::isWaterSensor() const
{
    return waterSensor;
}

double ThreeDHall::getPrice() const
{
    return extraPrice;
}

void ThreeDHall::setPrice(double price)
{
    ThreeDHall::extraPrice = price;
}

void ThreeDHall::toOs(std::ostream& os) const
{
    os << " moving chairs:" << (movingChairs ? "yes":"no") << " wind sensor:"
       << (windSensor ? "yes":"no") << " water sensor:"
       << (waterSensor ? "yes":"no") << " price:" << extraPrice;
}

void ThreeDHall::setMovingChairs(bool chairs)
{
    this->movingChairs = chairs;
}

bool ThreeDHall::getMovingChairs() const
{
    return movingChairs;
}

void ThreeDHall::setWindSensor(bool windSensor)
{
    this->waterSensor = windSensor;
}

bool ThreeDHall::getWindSensor() const
{
    return this->waterSensor;
}

void ThreeDHall::setWaterSensor(bool waterSensor)
{
    this->waterSensor = waterSensor;
}

bool ThreeDHall::getWaterSensor() const
{
    return this->waterSensor;
}

void ThreeDHall::setPriceAddition(double price)
{
    this->extraPrice = price;
}

