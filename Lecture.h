#ifndef  LECTURE_H
#define LECTURE_H

#include <ostream>
#include "Occasion.h"

class Lecture : public Occasion
{
public:

	Lecture(const Date &date, int startHour, int endHour, char *name, Hall *hall);

	virtual ~Lecture ();
	const Lecture operator=(Lecture other);

	const char *getLectureName() const;

	void setLectureName(const char *lectureName);

	const char *getHostName() const;

	void setHostName(const char *hostName);

	double getLengthInMinutes() const;

	void setLengthInMinutes(double lengthInMinutes);

	friend std::ostream &operator<<(std::ostream &os, const Lecture &lecture);


private:
	const char* lectureName;
	const char* hostName;
	double lengthInMinutes;
};

#endif
