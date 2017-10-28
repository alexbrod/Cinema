
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

bool const ** const Hall::getSeatOccupationMatrix()
{
    return reinterpret_cast<const bool **const>(seatOccupationMatrix);
}

void Hall::occupieSeat(int row, int seatNumber) throw(const char*)
{
    if(row >= 1 && row <= numOfRows && seatNumber >= 1 && seatNumber <= numOfSeatsPerRow)
    {
        if(!seatOccupationMatrix[row][seatNumber])
        {
            seatOccupationMatrix[row][seatNumber] = true;
        }
        else
        {
            throw 'Seat: ' << seatNumber << ' Row: ' << row << ' is already occupied';
        }
    }
    else
    {
        throw 'Seat: ' << seatNumber << ' Row: ' << row << ' is Invalid';
    }
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
            throw 'Seat: ' << seatNumber << ' Row: ' << row << ' is already free';
        }
    }
    else
    {
        throw 'Seat: ' << seatNumber << ' Row: ' << row << ' is Invalid';
    }
}
