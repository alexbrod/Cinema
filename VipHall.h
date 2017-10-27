#ifndef  VIPHALL_H
#define VIPHALL_H
#include "Hall.h"

class VipHall : public Hall
{
public:
	VipHall(int hallNumber, double pricePerSeat,bool massage,bool tray,bool footRest);
	~VipHall();
	void setMassage(bool massage);
	bool getMassage();
	void setTray(bool tray);
	bool getTray();
	void setFootRest(bool footRest);
	bool getFootRest();
	void setPriceAddition(double price);

private:
	bool massage;
	bool tray;
	bool footRest;
};

#endif VIPHALL_H