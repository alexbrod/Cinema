#ifndef DATE_H
#define DATE_H

class Date
{
public:
	Date(int year, int month, int day);
	Date(const Date & other);
	virtual ~Date();
	void setYear(int year);
	int getYear();
	void setMonth(int month);
	int getMonth();
	void setDay(int day);
	int getDay();

private:
	int year;
	int month;
	int day;
};

#endif