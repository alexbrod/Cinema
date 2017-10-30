#ifndef  EVENT_H
#define EVENT_H

#include <ostream>
#include "Screening.h"
#include "Lecture.h"

class Event : public Screening, public Lecture
{
public:
	Event(Date date, int startHour, int endHour, Hall* hall, Movie* movie, char* lectureName, char* hostName, double lengthInMinutes);

	Event(const Date &date, int startHour, int endHour, char *name, Hall *hall, const Date &date1, int startHour1,
		  int endHour1, char *name1, Hall *hall1);

	friend ostream &operator<<(ostream &os, const Event &event);


private:
	
};

#endif