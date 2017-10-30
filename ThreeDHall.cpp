#include "ThreeDHall.h"

ThreeDHall::ThreeDHall(int hallNumber, double pricePerSeat, int numOfRows, int numOfSeatsPerRow) : Hall(hallNumber,
                                                                                                        pricePerSeat,
                                                                                                        numOfRows,
                                                                                                        numOfSeatsPerRow) {}

bool ThreeDHall::isMovingChairs() const {
    return movingChairs;
}

bool ThreeDHall::isWindSensor() const {
    return windSensor;
}

bool ThreeDHall::isWaterSensor() const {
    return waterSensor;
}

double ThreeDHall::getPrice() const {
    return extraPrice;
}

void ThreeDHall::setPrice(double price) {
    ThreeDHall::extraPrice = price;
}

std::ostream &operator<<(std::ostream &os, const ThreeDHall &hall) {
    os <<  " 3Dhall: " << static_cast<const Hall &>(hall) << " movingChairs: " << hall.movingChairs << " windSensor: "
       << hall.windSensor << " waterSensor: " << hall.waterSensor << " price: " << hall.extraPrice;
    return os;
}

