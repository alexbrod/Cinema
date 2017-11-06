
#include "Hall.h"

Hall::Hall(int hallNumber, double pricePerSeat, int numOfRows, int numOfSeatsPerRow):
        hallNumber(hallNumber), pricePerSeat(pricePerSeat), numOfRows(numOfRows),
        numOfSeatsPerRow(numOfSeatsPerRow)
{
    seatOccupationMatrix = new bool*[numOfRows];
    for (int i = 0; i < numOfRows; ++i) {
        seatOccupationMatrix[i] = new bool[numOfSeatsPerRow];
    }
    initHallSeats();
    occasion = nullptr;
}

Hall::~Hall()
{
    for (int i = 0; i < numOfRows; ++i) {
        delete seatOccupationMatrix[i];
    }
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

void Hall::setPricePerSeat(double price)
{
    if(price >= 0) {
        pricePerSeat = price;
    }
    else
    {
        throw "Invalid price";
    }
}

void Hall::setOccasion(Occasion *occasion)
{
    if(this->occasion != occasion)
    {
        this->occasion = occasion;
        if(this->occasion != nullptr)
        {
            this->occasion->setHall(this);
            initHallSeats();
        }
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


bool Hall::occupieSeat(int row, int seatNumber)
{
    if(row >= 1 && row <= numOfRows && seatNumber >= 1 && seatNumber <= numOfSeatsPerRow)
    {
        if(!seatOccupationMatrix[row-1][seatNumber-1])
        {
            seatOccupationMatrix[row-1][seatNumber-1] = true;
            return true;
        }
    }
    return false;
}

void Hall::clearSeat(int row, int seatNumber)
{
    if(row >= 1 && row <= numOfRows && seatNumber >= 1 && seatNumber <= numOfSeatsPerRow)
    {
        if(seatOccupationMatrix[row][seatNumber])
        {
            seatOccupationMatrix[row][seatNumber] = false;
        }
        else
        {
            throw ("Seat: %d Row: %d is already free\n", seatNumber, row);
        }
    }
    else
    {
        throw ("Seat: %d Row: %d is Invalid\n", seatNumber, row);
    }
}

void Hall::toOs(std::ostream& os) const {}

std::ostream &operator<<(std::ostream &os, const Hall &hall) {
    os << "Hall number: " << hall.hallNumber << " pricePerSeat: " << hall.pricePerSeat << " numOfSeatsPerRow: "
       << hall.numOfSeatsPerRow << " numOfRows: " << hall.numOfRows;
    hall.toOs(os);
    return os;
}
