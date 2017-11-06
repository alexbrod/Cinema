#ifndef  LECTURE_H
#define LECTURE_H

#include <ostream>
#include "Occasion.h"

class Lecture : virtual public Occasion
{
private:
	char* hostName;
	double lengthInMinutes;
public:

	Lecture(const char* name, const char* hostName, const Date &date, int startHour, int endHour);
	Lecture(const Lecture& lecture);

	~Lecture() override;

    virtual const char* getLectureName() const;

    virtual void setLectureName(const char* lectureName);

    virtual const char* getHostName() const;

    virtual void setHostName(const char* hostName);

    virtual double getLengthInMinutes() const;

    virtual void setLengthInMinutes(double lengthInMinutes);

    virtual void setHall(Hall* hall);

    virtual Hall* getHall() const;

    virtual void toOs(std::ostream& os) const;

};

#endif
