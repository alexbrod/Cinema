#include <string.h>
#include "SeatTicket.h"

SeatTicket::SeatTicket(int hallNumber, int rowNumber, int seatNumber, double price,
                       const std::string &occasionName)
{
    setPrice(price);
    setSeatNumber(seatNumber);
    setRowNumber(rowNumber);
    setHallNumber(hallNumber);
    setOccasionName(occasionName);
}

double SeatTicket::getPrice() const{ return price;}

void SeatTicket::setPrice(double price) {this->price = price;}

int SeatTicket::getRowNumber() const {return rowNumber+1;}

void SeatTicket::setRowNumber(int row) {this->rowNumber = row-1;}

int SeatTicket::getSeatNumber() const{ return seatNumber+1;}

void SeatTicket::setSeatNumber(int seat) {this->seatNumber = seat-1;}

void SeatTicket::setHallNumber(int hallNumber) {this->hallNumber = hallNumber-1;}

int SeatTicket::getHallNumber() const { return hallNumber+1;}

const std::string& SeatTicket::getOccasionName() const { return this->occasionName;}

void SeatTicket::setOccasionName(const std::string& name)
{
    this->occasionName = name;
}

std::ostream& operator<<(std::ostream &os, const SeatTicket &seatTicket)
{
    os << "Hall: " << seatTicket.getHallNumber() << " row: " << seatTicket.getRowNumber()
       << " seat: " << seatTicket.getSeatNumber() << " price: " << seatTicket.price;
    return os;
}