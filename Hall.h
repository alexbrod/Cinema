#ifndef  HALL_H
#define HALL_H
#include "SeatTicket.h"

class Hall 
{
private:
	int hallNumber;
	double pricePerSeat;
    int numOfSeatsPerRow;
    int numOfRows;
	bool** seatOccupationMatrix;
    Occasion* occasion;

    void initHallSeats();
public:
	Hall(int hallNumber , double pricePerSeat, int numOfRows, int numOfSeatsPerRow);
	Hall(const Hall& other) = delete;
	virtual ~Hall();

	int getHallNumber() const;
	int getNumOfRows() const;
	int getNumOfSeatsPerRow() const;
    Occasion* getOccation();
    void setOccasion(Occasion* occation);
	void setPricePerSeat(double price);
	virtual double getPricePerSeat() const;
    bool const ** const getSeatOccupationMatrix();
    void occupieSeat(int row, int seatNumber);
    void clearSeat(int row, int seatNumber);
};

#endif