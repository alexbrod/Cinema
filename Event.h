#ifndef  EVENT_H
#define EVENT_H
#include "Screening.h"
#include "Lecture.h"

class Event : public Screening, public Lecture
{
public:
	Event(Date date, int startHour, int endHour, Hall* hall, Movie* movie, char* lectureName, char* hostName, double lengthInMinutes);
	

private:
	
};

#endif