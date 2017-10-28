#include <string.h>
#include "SeatTicket.h"

SeatTicket::SeatTicket(int hallNumber, int rowNumber, int seatNumber, double price,
                       const char& occasionName):
{
    //TODO: check if there is exception when invalid value inserted
    setPrice(price);
    setSeatNumber(seatNumber);
    setRowNumber(rowNumber);
    setHallNumber(hallNumber);
    setOccasionName(occasionName);
}

SeatTicket::~SeatTicket()
{
    delete []occasionName;
}

double SeatTicket::getPrice() const{ return price;}

void SeatTicket::setPrice(double price) {this->price = price;}

int SeatTicket::getRowNumber() const {return rowNumber;}

void SeatTicket::setRowNumber(int row) {this->rowNumber = row;}

int SeatTicket::getSeatNumber() const{ return seatNumber;}

void SeatTicket::setSeatNumber(int seat) {this->seatNumber = seat;}

void SeatTicket::setHallNumber(int hallNumber) {this->hallNumber = hallNumber;}

int SeatTicket::getHallNumber() const { return hallNumber;}

char const * const SeatTicket::getOccasionName() const { return this->occasionName;}

void SeatTicket::setOccasionName(const char& name)
{
    this->occasionName = &name;
}
