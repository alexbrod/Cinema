
#include "Occasion.h"
#include "Hall.h"

Occasion::Occasion(Date date, int startHour, int endHour, Hall* hall):
    date(date)
{
    setEndHour(endHour);
    setHall(hall);
    setStartHour(startHour);
}

Occasion::~Occasion()
{
    if(this->hall != nullptr)
    {
        this->hall->setOccasion(nullptr);
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
        throw 'Invalid start hour';
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
        throw 'Invalid end hour';
    }
}

void Occasion::setDate(Date date)
{
    //TODO: check if passes through copy constructor
    this->date = date;
}

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
        }
    }
}

int Occasion::getStartHour() const {return startHour;}

int Occasion::getEndHour() const {return endHour;}

const Date& Occasion::getDate() const {return date;}

Hall* Occasion::getHall() const { return hall;}