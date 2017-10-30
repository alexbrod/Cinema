#include "Date.h"

Date::Date(int year, int month, int day)
{
    setDay(day);
    setMonth(month);
    setYear(year);
}

Date::Date(const Date &other) : day(other.day), month(other.month), year(other.year) {}

int Date::getDay() {return day;}

int Date::getMonth() {return month;}

int Date::getYear() { return year;}

void Date::setYear(int year) throw(const char*)
{
    if(year > 0)
    {
        this->year = year;
    }
    else
    {
        throw "Invalid year";
    }
}

void Date::setMonth(int month) throw(const char*)
{
    if(month >= 1 && month <= 12)
    {
        this->month = month;
    }
    else
    {
        throw "Invalid month";
    }
}

void Date::setDay(int day) throw(const char*)
{
    if(day >= 1 && day <= 31)
    {
        this->day = day;
    }
    else
    {
        throw "Invalid month";
    }
}


std::ostream &operator<<(std::ostream &os, const Date &date) {
    os << "year: " << date.year << " month: " << date.month << " day: " << date.day;
    return os;
}
