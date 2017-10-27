#ifndef DATE_H
#define DATE_H

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

};

#endif