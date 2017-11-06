#ifndef DATE_H
#define DATE_H

#include <ostream>

class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date(int year, int month, int day);
	Date(const Date & other);
	virtual ~Date() = default;
    void setYear(int year);
	int getYear();
	void setMonth(int month);
	int getMonth();
	void setDay(int day);
	int getDay();

	bool operator==(const Date& date) const;
    bool operator!=(const Date& date) const;

    friend std::ostream &operator<<(std::ostream &os, const Date &date);

};

#endif