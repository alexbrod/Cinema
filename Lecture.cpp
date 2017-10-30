#include "Lecture.h"

Lecture::Lecture(const Date &date, int startHour, int endHour, char *name, Hall *hall) : Occasion(date, startHour,
                                                                                                  endHour, name,
                                                                                                  hall) {}

const char *Lecture::getLectureName() const {
    return lectureName;
}

void Lecture::setLectureName(const char *lectureName) {
    Lecture::lectureName = lectureName;
}

const char *Lecture::getHostName() const {
    return hostName;
}

void Lecture::setHostName(const char *hostName) {
    Lecture::hostName = hostName;
}

double Lecture::getLengthInMinutes() const {
    return lengthInMinutes;
}

void Lecture::setLengthInMinutes(double lengthInMinutes) {
    Lecture::lengthInMinutes = lengthInMinutes;
}

std::ostream &operator<<(std::ostream &os, const Lecture &lecture) {
    os << " Lecture: " << static_cast<const Occasion &>(lecture) << " lectureName: " << lecture.lectureName << " hostName: "
       << lecture.hostName << " lengthInMinutes: " << lecture.lengthInMinutes;
    return os;
}
