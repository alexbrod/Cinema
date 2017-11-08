#include <string.h>
#include "Occasion.h"
#include "Hall.h"

Occasion::Occasion(const char* name, const Date& date, int startHour, int endHour):
    name(nullptr), date(nullptr), hall(nullptr)
{
    setName(name);
    setStartHour(startHour);
    setEndHour(endHour);
    setHall(hall);
    setDate(date);
}

Occasion::~Occasion()
{
    if(this->hall != nullptr)
    {
        this->hall->setOccasion(nullptr);
        for (int i = 0; i < hall->getNumOfRows(); ++i)
        {
            delete tickets[i];
        }
        delete []tickets;
    }
    delete name;
}

void Occasion::setStartHour(int hour)
{
    if(hour >= 0 && hour <= 23)
    {
        this->startHour = hour;
    }
    else
    {
        throw "Invalid start hour";
    }
}

void Occasion::setEndHour(int hour)
{
    if(hour >= 0 && hour <= 23 && hour > startHour)
    {
        this->endHour = hour;
    }
    else
    {
        throw "Invalid end hour";
    }
}

void Occasion::setDate(const Date& date)
{
    delete this->date;
    this->date = new Date(date);
}

const Date& Occasion::getDate() const {return *date;}

int Occasion::getStartHour() const {return startHour;}

int Occasion::getEndHour() const {return endHour;}

void Occasion::setName(const char *name)
{
    delete []this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name,name);
}

const char* Occasion::getName() const { return name;}

void Occasion::setHall(Hall* hall)
{
    if(this->hall != hall)
    {
        this->hall = hall;
        if(this->hall != nullptr)
        {
            this->hall->setOccasion(this);
            tickets = new SeatTicket**[hall->getNumOfRows()];
            for (int i = 0; i < hall->getNumOfRows(); ++i) {
                tickets[i] = new SeatTicket*[hall->getNumOfSeatsPerRow()];
            }
        }
    }
}

Hall* Occasion::getHall() const { return hall;}

const SeatTicket& Occasion::orderTicket()
{
    if(hall != nullptr)
    {
        for (int i = 0; i < hall->getNumOfRows(); ++i)
        {
            for (int j = 0; j < hall->getNumOfSeatsPerRow(); ++j)
            {
                if(hall->occupieSeat(i+1,j+1))
                {
                    tickets[i][j] = new SeatTicket(hall->getHallNumber(),
                                                   i, j, hall->getPricePerSeat(),*name);
                    return *tickets[i][j];
                }
            }
        }
        throw "Cannot order the ticket, the Hall is full";
    }
    else
    {
        throw "Cannot order the ticket, a Hall is not assigned to this occasion";
    }
}

std::ostream &operator<<(std::ostream& os, const Occasion& occasion)
{
    os <<"Name: " << occasion.name << " Date: " << *occasion.date << " Hours: " <<
    occasion.startHour << " - " << occasion.endHour << " ";
    occasion.toOs(os);
    return os;
}
