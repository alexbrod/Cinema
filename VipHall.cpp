#include "VipHall.h"

VipHall::VipHall(int hallNumber, double pricePerSeat, int numOfRows, int numOfSeatsPerRow) :
        Hall(hallNumber, pricePerSeat, numOfRows, numOfSeatsPerRow)
{
    setFootRest(true);
    setMassage(true);
    setTray(false);
    setPrice(20);
}

bool VipHall::isMassage() const
{
    return massage;
}

void VipHall::setMassage(bool massage)
{
    VipHall::massage = massage;
}

bool VipHall::isTray() const {
    return tray;
}

void VipHall::setTray(bool tray)
{
    VipHall::tray = tray;
}

bool VipHall::isFootRest() const
{
    return footRest;
}

void VipHall::setFootRest(bool footRest)
{
    VipHall::footRest = footRest;
}

double VipHall::getPrice() const
{
    return extraPrice;
}

void VipHall::setPrice(double price)
{
    VipHall::extraPrice = price;
}

void VipHall::toOs(std::ostream& os) const
{
    os << (massage ? " with massage,":"no massage,") <<
            (tray ? " with tray,":"no tray,") <<
            (footRest ? " with footrest,":"no footrest,") <<
            " extra price:" << extraPrice;
}
