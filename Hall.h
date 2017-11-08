#ifndef  HALL_H
#define HALL_H

#include <ostream>
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
	Hall(int hallNumber , double pricePerSeat, int numOfRows,  int numOfSeatsPerRow);
	Hall(const Hall& other) = delete;
	virtual ~Hall();

	int getHallNumber() const;
	int getNumOfRows() const;
	int getNumOfSeatsPerRow() const;
    Occasion* getOccation();
    void setOccasion(Occasion* occation);
	void setPricePerSeat(double price);
    double getPricePerSeat() const;
    bool occupieSeat(int row, int seatNumber);
    void clearSeat(int row, int seatNumber);

	friend std::ostream &operator<<(std::ostream &os, const Hall &hall);
	virtual void toOs(std::ostream& os) const;
};

#endif