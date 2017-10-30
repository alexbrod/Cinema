#ifndef  OCCASION_H
#define OCCASION_H

#include <ostream>
#include "Date.h"

class SeatTicket;
class Hall;

class Occasion 
{
private:
	Date date;
	int startHour;
	int endHour;
	Hall* hall;
    SeatTicket*** tickets;
    char* name;

public:
	Occasion(const Date& date, int startHour, int endHour, const char* name);
    Occasion(Occasion& other) = delete;
	virtual ~Occasion();
	void setDate(Date date);
	const Date& getDate() const;
	void setStartHour(int hour) throw(const char*);
	int getStartHour() const;
	void setEndHour(int hour) throw(const char*);
    void setName(const char* name);
    char* getName() const;
	int getEndHour() const;
	void setHall(Hall* hall);
	Hall* getHall() const;
    const SeatTicket& orderTicket();
    void cancelTicket(const SeatTicket& ticket);

	friend std::ostream &operator<<(std::ostream &os, const Occasion &occasion);

};

#endif

