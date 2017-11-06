#ifndef  VIPHALL_H
#define VIPHALL_H

#include <ostream>
#include "Hall.h"

class VipHall : public Hall
{
private:
	bool massage;
	bool tray;
	bool footRest;
	double extraPrice;
public:


	VipHall(int hallNumber, double pricePerSeat, int numOfRows, int numOfSeatsPerRow);

	~VipHall() override = default;

	bool isMassage() const;

	void setMassage(bool massage);

	bool isTray() const;

	void setTray(bool tray);

	bool isFootRest() const;

	void setFootRest(bool footRest);

	double getPrice() const;

	void setPrice(double price);

	void toOs(std::ostream& os) const;

};

#endif