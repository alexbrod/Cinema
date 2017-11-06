#include <string.h>
#include "Lecture.h"

Lecture::Lecture(const char *name, const char* hostName, const Date &date, int startHour, int endHour):
        Occasion(name, date, startHour, endHour), hostName(nullptr)
{
    setHostName(hostName);
}

Lecture::Lecture(const Lecture& other):
        Lecture(other.getLectureName(),other.getHostName(),other.getDate(),
                other.getStartHour(),other.getEndHour()) {}

Lecture::~Lecture()
{
    delete hostName;
}

const char* Lecture::getLectureName() const
{
    return Occasion::getName();
}

void Lecture::setLectureName(const char* lectureName)
{
    Occasion::setName(lectureName);
}

const char* Lecture::getHostName() const
{
    return hostName;
}

void Lecture::setHostName(const char* hostName)
{
    delete []this->hostName;
    this->hostName = new char[strlen(hostName) + 1];
    strcpy(this->hostName,hostName);
}

double Lecture::getLengthInMinutes() const
{
    return lengthInMinutes;
}

void Lecture::setLengthInMinutes(double lengthInMinutes)
{
    Lecture::lengthInMinutes = lengthInMinutes;
}

void Lecture::setHall(Hall* hall)
{
    Occasion::setHall(hall);
}

Hall* Lecture::getHall() const
{
    return Occasion::getHall();
}

void Lecture::toOs(std::ostream &os) const
{
    os << " Host name: " << hostName;
}

