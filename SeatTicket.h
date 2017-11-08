#ifndef  SEATTICKET_H
#define SEATTICKET_H
#include "Occasion.h"

class SeatTicket 
{
private:

    std::string occasionName;
	int rowNumber;
	int seatNumber;
    int hallNumber;
	double price;
public:
    SeatTicket(SeatTicket& other) = delete;
	SeatTicket(int hallNumber, int rowNumber, int seatNumber, double price, const std::string& occasionName);
    ~SeatTicket() = default;
	void setRowNumber(int row);
	int getRowNumber() const;
	void setSeatNumber(int seat);
	int getSeatNumber() const;
	void setPrice(double price);
	double getPrice() const;
    void setHallNumber(int hallNumber);
    int getHallNumber() const;
    void setOccasionName(const std::string& name);
    const std::string& getOccasionName() const;

	friend std::ostream &operator<<(std::ostream &os, const SeatTicket &seatTicket);
};

#endif