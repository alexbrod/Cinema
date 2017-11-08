#include <string.h>
#include "Lecture.h"

Lecture::Lecture(const std::string& name, const std::string& hostName, const Date &date, int startHour, int endHour):
        Occasion(name, date, startHour, endHour), hostName(hostName)
{}

Lecture::Lecture(const Lecture& other):
        Lecture(other.getLectureName(),other.getHostName(),other.getDate(),
                other.getStartHour(),other.getEndHour()) {}

Lecture::~Lecture() {}

const std::string& Lecture::getLectureName() const
{
    return Occasion::getName();
}

void Lecture::setLectureName(const std::string& lectureName)
{
    Occasion::setName(lectureName);
}

const std::string& Lecture::getHostName() const
{
    return hostName;
}

void Lecture::setHostName(const std::string& hostName)
{
    this->hostName = hostName;
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

