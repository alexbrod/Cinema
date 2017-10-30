#include "Event.h"

Event::Event(const Date &date, int startHour, int endHour, char *name, Hall *hall, const Date &date1, int startHour1,
             int endHour1, char *name1, Hall *hall1) : Screening(date, startHour, endHour, name, hall),
                                                       Lecture(date1, startHour1, endHour1, name1, hall1) {}

ostream &operator<<(ostream &os, const Event &event) {
    os << " Event: " << static_cast<const Screening &>(event) << ' ' << static_cast<const Lecture &>(event);
    return os;
}
