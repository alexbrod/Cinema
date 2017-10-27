#ifndef  OCCASION_H
#define OCCASION_H
#include "Date.h"

class Hall;

class Occasion 
{
public:
	Occasion(Date date, int startHour, int endHour, Hall* hall);
	~Occasion();
	void setDate(Date date);
	Date getDate();
	void setStartHour(int hour);
	int getStartHour();
	void setEndHour(int hour);
	int getEndHour();
	void setHall(const Hall* hall);
	Hall* getHall();

private:
	Date date;
	int startHour;
	int endHour;
	Hall* hall;

	bool buyTicket();
};

#endif

