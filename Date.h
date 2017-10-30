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
    void setYear(int year) throw(const char*);
	int getYear();
	void setMonth(int month) throw(const char*);
	int getMonth();
	void setDay(int day) throw(const char*);
	int getDay();

	friend std::ostream &operator<<(std::ostream &os, const Date &date);

};

#endif