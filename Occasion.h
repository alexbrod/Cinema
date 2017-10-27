#ifndef  OCCASION_H
#define OCCASION_H
#include "Date.h"

class Hall;

class Occasion 
{
private:
	Date date;
	int startHour;
	int endHour;
	Hall* hall;

	bool buyTicket();
public:
	Occasion(Date date, int startHour, int endHour, Hall* hall);
    Occasion(Occasion& other) = delete;
	~Occasion();
	void setDate(Date date);
	const Date& getDate() const;
	void setStartHour(int hour);
	int getStartHour() const;
	void setEndHour(int hour);
	int getEndHour() const;
	void setHall(Hall* hall);
	Hall* getHall() const;

};

#endif

