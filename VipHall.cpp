#include "VipHall.h"

VipHall::VipHall(int hallNumber, double pricePerSeat, int numOfRows, int numOfSeatsPerRow) : Hall(hallNumber,
                                                                                                  pricePerSeat,
                                                                                                  numOfRows,
                                                                                                  numOfSeatsPerRow) {}

bool VipHall::isMassage() const {
    return massage;
}

void VipHall::setMassage(bool massage) {
    VipHall::massage = massage;
}

bool VipHall::isTray() const {
    return tray;
}

void VipHall::setTray(bool tray) {
    VipHall::tray = tray;
}

bool VipHall::isFootRest() const {
    return footRest;
}

void VipHall::setFootRest(bool footRest) {
    VipHall::footRest = footRest;
}

double VipHall::getPrice() const {
    return extraPrice;
}

void VipHall::setPrice(double price) {
    VipHall::extraPrice = price;
}

std::ostream &operator<<(std::ostream &os, const VipHall &hall) {
    os << " VipHall " << static_cast<const Hall &>(hall) << " VipHall massage: " << hall.massage << " VipHall tray: " << hall.tray << " VipHall footRest: "
       << hall.footRest << " VipHall extra price: " << hall.extraPrice;
    return os;
}
