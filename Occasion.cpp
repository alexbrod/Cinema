#include <string.h>
#include "Occasion.h"
#include "Hall.h"

Occasion::Occasion(Date date, int startHour, int endHour, char* name, Hall* hall):
    date(date)
{
    //TODO: check why should initiate date in the init line
    //TODO: check if there is exception when invalid value inserted
    setName(name);
    setEndHour(endHour);
    setHall(hall);
    setStartHour(startHour);
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
}

void Occasion::setStartHour(int hour) throw(const char*)
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

void Occasion::setEndHour(int hour) throw(const char*)
{
    if(hour >= 0 && hour <= 23)
    {
        this->endHour = hour;
    }
    else
    {
        throw "Invalid end hour";
    }
}

void Occasion::setDate(Date date)
{
    //TODO: check if passes through copy constructor
    this->date = date;
}

const Date& Occasion::getDate() const {return date;}

int Occasion::getStartHour() const {return startHour;}

int Occasion::getEndHour() const {return endHour;}

void Occasion::setName(const char *name)
{
    if(this->name != nullptr)
    {
        delete []this->name;
    }
    char* newName = new char[strlen(name) + 1];
    strcpy(this->name,newName);
}

char* Occasion::getName() const { return name;}

void Occasion::setHall(Hall* hall)
{
    if(this->hall != hall)
    {
        if(this->hall != nullptr)
        {
            this->hall->setOccasion(nullptr);
        }
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
                if(!hall->getSeatOccupationMatrix()[i][j])
                {
                    hall->occupieSeat(i,j);
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

void Occasion::cancelTicket(const SeatTicket &ticket)
{
    if(hall != nullptr)
    {
        for (int i = 0; i < hall->getNumOfRows(); ++i)
        {
            for (int j = 0; j < hall->getNumOfSeatsPerRow(); ++j)
            {
                if(tickets[i][j] == &ticket)
                {
                    hall->clearSeat(i,j);
                    delete tickets[i][j];
                    return;
                }
            }
        }
    }
    else
    {
        throw "Cannot cancel the ticket, a Hall is not assigned to this occasion";
    }
}

std::ostream &operator<<(std::ostream &os, const Occasion &occasion) {
    os << "date: " << occasion.date << " startHour: " << occasion.startHour << " endHour: " << occasion.endHour
       << " hall: " << occasion.hall << " tickets: " << occasion.tickets << " name: " << occasion.name;
    return os;
}
