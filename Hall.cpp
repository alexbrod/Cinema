
#include "Hall.h"

Hall::Hall(int hallNumber, double pricePerSeat, int numOfRows, int numOfSeatsPerRow):
        hallNumber(hallNumber), pricePerSeat(pricePerSeat), numOfRows(numOfRows),
        numOfSeatsPerRow(numOfSeatsPerRow)
{
    seatOccupationMatrix = new bool*[numOfRows][numOfSeatsPerRow];
    initHallSeats();
    occasion = nullptr;
}

Hall::~Hall()
{
    delete []seatOccupationMatrix;
    if(this->occasion != nullptr)
    {
        this->occasion->setHall(nullptr);
    }
}

Occasion* Hall::getOccation() { return occasion;}

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

void Hall::setOccasion(Occasion *occasion)
{
    if(this->occasion != occasion)
    {
        if(this->occasion != nullptr)
            this->occasion->setHall(nullptr);
        this->occasion = occasion;
        if(this->occasion != nullptr)
        {
            this->occasion->setHall(this);
        }
        initHallSeats();
    }
}

void Hall::initHallSeats()
{
    if(seatOccupationMatrix != nullptr)
    {
        for (int i = 0; i < numOfRows; ++i)
        {
            for (int j = 0; j < numOfSeatsPerRow; ++j)
            {
                seatOccupationMatrix[i][j] = false;
            }
        }
    }
}
