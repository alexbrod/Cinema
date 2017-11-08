#ifndef  OCCASION_H
#define OCCASION_H

#include <ostream>
#include "Date.h"

class SeatTicket;
class Hall;

class Occasion 
{
private:
	Date* date;
	int startHour;
	int endHour;
	Hall* hall;
    SeatTicket*** tickets;
    std::string name;

public:
	Occasion(const std::string& name , const Date& date, int startHour, int endHour);
    Occasion(Occasion& other) = delete;
	virtual ~Occasion();
    virtual void setDate(const Date& date);
    virtual const Date& getDate() const;
    virtual void setStartHour(int hour);
    virtual int getStartHour() const;
    virtual void setEndHour(int hour);
    virtual void setName(const std::string& name);
    virtual const std::string& getName() const;
    virtual int getEndHour() const;

    virtual void setHall(Hall* hall);
    virtual Hall* getHall() const;

    virtual const SeatTicket& orderTicket();

    virtual void toOs(std::ostream& os) const =0;
    friend std::ostream& operator<<(std::ostream& os, const Occasion& occasion);

};

#endif

