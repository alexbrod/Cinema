#ifndef  LECTURE_H
#define LECTURE_H
#include "Occasion.h"

class Lecture : public Occasion
{
public:
	Lecture (Date date, int startHour, int endHour, Hall* hall, char* lectureName, char* hostName, double lengthInMinutes);
	virtual ~Lecture ();
	const Lecture operator=(Lecture other);
	char* getLectureName();
	void setLectureName(char* name);
	char* getHostName();
	void setHostName(char* name);
	double getLength();
	void setLength(double length);

private:
	char* lectureName;
	char* hostName;
	double lengthInMinutes;
};

#endif
