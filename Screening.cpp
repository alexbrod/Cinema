#include "Screening.h"

Screening::Screening(const Date &date, int startHour, int endHour, char *name, Hall *hall) : Occasion(date, startHour,
                                                                                                      endHour, name,
                                                                                                      hall) {}

Movie *Screening::getMovie() const {
    return movie;
}

void Screening::setMovie(Movie *movie) {
    Screening::movie = movie;
}

ostream &operator<<(ostream &os, const Screening &screening) {
    os << " Screening: " << static_cast<const Occasion &>(screening) << " movie: " << screening.movie;
    return os;
}

