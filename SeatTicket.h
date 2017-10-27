#ifndef  SEATTICKET_H
#define SEATTICKET_H
#include "Occasion.h"

class SeatTicket 
{
private:
	Occasion* occasion;
	int rowNumber;
	int seatNumber;
	int barcode;
	double price;
public:
	SeatTicket(Occasion* occasion, int rowNumber, int seatNumber, int barcode, double price);
	~SeatTicket();
	void setOccasion(const Occasion* occasion);
	Occasion getOccasion();
	void setRowNumber(int row);
	int getRowNumber();
	void setSeatNumber(int seat);
	int getSeatNumber();
	void setBarcode(int barcode);
	int getBarcode();
	void setPrice(int price);
	double getPrice();
	SeatTicket& operator=(SeatTicket& seatTicket);

};

#endif