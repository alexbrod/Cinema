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
	SeatTicket** seatTicketMatrix;

	//void initHallSeats(int rows,int seatsPerRow);

public:
	Hall(int hallNumber , double pricePerSeat, int numOfRows, int numOfSeatsPerRow);
	Hall(const Hall& other);
	virtual ~Hall();

	int getHallNumber() const;
	int getNumOfRows() const;
	int getNumOfSeatsPerRow() const;
	void setPricePerSeat(double price);
	virtual double getPricePerSeat() const;
	void printSeatMatrix() const;
	bool addTicket(SeatTicket* ticket);
	bool removeTicket(SeatTicket* ticket);
};

#endif