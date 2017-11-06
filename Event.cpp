#include <cstring>
#include "Event.h"
#include "Date.h"

class Lecture;

Event::Event(const Screening &screening, const Lecture &lecture) :
    Occasion("Screening and Lecture", screening.getDate(), screening.getStartHour(), screening.getEndHour()),
    Screening(screening.getName(),screening.getDate(),screening.getStartHour(),
              screening.getEndHour(), *screening.getMovie()),
    Lecture(lecture.getName(),lecture.getHostName(),lecture.getDate(),
            lecture.getStartHour(),lecture.getEndHour())
{
    if(lecture.getDate() != screening.getDate())
    {
        throw "Lecture and Screening are not in the same date\n";
    }
    if((lecture.getEndHour() > screening.getStartHour() &&
            lecture.getEndHour() <= screening.getEndHour()) ||
            (screening.getEndHour() > lecture.getStartHour() &&
            screening.getEndHour() <= lecture.getEndHour()))
    {
        throw "Lecture and Screenign has overriding in hours\n";
    }
}


Hall* Event::getHall() const
{
    Occasion::getHall();
}

void Event::setHall(Hall *hall)
{
    Occasion::setHall(hall);
}

void Event::toOs(std::ostream &os) const
{
    os << " Lecture: " << this->getLectureName() << " and Movie: " <<
       this->getMovie()->getName() << endl;
}

