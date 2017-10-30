#ifndef  VIPHALL_H
#define VIPHALL_H

#include <ostream>
#include "Hall.h"

class VipHall : public Hall
{
public:


	VipHall(int hallNumber, double pricePerSeat, int numOfRows, int numOfSeatsPerRow);

	~VipHall();

	bool isMassage() const;

	void setMassage(bool massage);

	bool isTray() const;

	void setTray(bool tray);

	bool isFootRest() const;

	void setFootRest(bool footRest);

	double getPrice() const;

	void setPrice(double price);

	friend std::ostream &operator<<(std::ostream &os, const VipHall &hall);


private:
	bool massage;
	bool tray;
	bool footRest;
	double extraPrice;
};

#endif VIPHALL_H