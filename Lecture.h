#ifndef  LECTURE_H
#define LECTURE_H

#include <ostream>
#include "Occasion.h"

class Lecture : virtual public Occasion
{
private:
	std::string hostName;
	double lengthInMinutes;
public:

	Lecture(const std::string& name, const std::string& hostName, const Date &date, int startHour, int endHour);
	Lecture(const Lecture& lecture);

	virtual ~Lecture() = default;

    virtual const std::string& getLectureName() const;

    virtual void setLectureName(const std::string& lectureName);

    virtual const std::string& getHostName() const;

    virtual void setHostName(const std::string& hostName);

    virtual double getLengthInMinutes() const;

    virtual void setLengthInMinutes(double lengthInMinutes);

    virtual void setHall(Hall* hall);

    virtual Hall* getHall() const;

    virtual void toOs(std::ostream& os) const;

};

#endif
