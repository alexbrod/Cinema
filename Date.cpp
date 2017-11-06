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

void Date::setYear(int year)
{
    if(year > 1970 && year < 2100 )
    {
        this->year = year;
    }
    else
    {
        throw "Invalid year";
    }
}

void Date::setMonth(int month)
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

void Date::setDay(int day)
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


std::ostream &operator<<(std::ostream &os, const Date &date)
{
    os << date.day << "/" << date.month << "/" << date.year;
    return os;
}

bool Date::operator==(const Date &date) const
{
    return this->year == date.year &&
            this->month == date.month &&
            this->day == date.day;
}

bool Date::operator!=(const Date &date) const
{
    return !(*this == date);
}
