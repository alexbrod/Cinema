
#include "Hall.h"

Hall::Hall(int hallNumber, double pricePerSeat, int numOfRows, int numOfSeatsPerRow):
        hallNumber(hallNumber), pricePerSeat(pricePerSeat), numOfRows(numOfRows),
        numOfSeatsPerRow(numOfSeatsPerRow)
{
    seatTicketMatrix = new SeatTicket*[numOfRows][numOfSeatsPerRow];
}

Hall::Hall(const Hall &other): hallNumber(other.hallNumber), pricePerSeat(other.pricePerSeat),
                               numOfRows(other.numOfRows),numOfSeatsPerRow(other.numOfSeatsPerRow)
{
    seatTicketMatrix = new SeatTicket*[numOfRows][numOfSeatsPerRow];
    for (int i = 0; i < numOfRows; ++i) {
        for (int j = 0; j < numOfSeatsPerRow; ++j) {
            seatTicketMatrix[i][j] = other.seatTicketMatrix[i][j];
        }
    }
}

Hall::~Hall()
{
    delete []seatTicketMatrix;
}

int Hall::getHallNumber() const { return hallNumber;}

int Hall::getNumOfRows() const { return  numOfRows;}

int Hall::getNumOfSeatsPerRow() const {return numOfSeatsPerRow;}

double Hall::getPricePerSeat() const {return pricePerSeat;}

void Hall::setPricePerSeat(double price) throw (const char*)
{
    if(price >= 0) {
        pricePerSeat = price;
    }
    else
    {
        throw 'Invalid price';
    }
}


