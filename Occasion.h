#ifndef  OCCASION_H
#define OCCASION_H
#include "Date.h"
#include "SeatTicket.h"

class Hall;

class Occasion 
{
private:
	Date date;
	int startHour;
	int endHour;
	Hall* hall;
    SeatTicket** tickets;
    char* name;

public:
	Occasion(Date date, int startHour, int endHour, char* name, Hall* hall);
    Occasion(Occasion& other) = delete;
	~Occasion();
	void setDate(Date date);
	const Date& getDate() const;
	void setStartHour(int hour);
	int getStartHour() const;
	void setEndHour(int hour);
    void setName(const char* name);
    char* getName() const;
	int getEndHour() const;
	void setHall(Hall* hall);
	Hall* getHall() const;
    const SeatTicket& orderTicket();
    void cancelTicket(const SeatTicket& ticket);

};

#endif

