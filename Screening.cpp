#include "Screening.h"

Screening::Screening(const string& name, const Date &date, int startHour, int endHour,const Movie& movie) :
        Occasion(name, date, startHour, endHour), movie(nullptr)
{
    setMovie(movie);
}

Screening::~Screening()
{
    delete movie;
}

const Movie* Screening::getMovie() const
{
    return movie;
}

void Screening::setMovie(const Movie& movie)
{
    delete this->movie;
    Screening::movie = new Movie(movie);
}

Hall* Screening::getHall() const
{
    return Occasion::getHall();
}

void Screening::setHall(Hall *hall)
{
    Occasion::setHall(hall);
}

void Screening::toOs(std::ostream &os) const
{
    os << "Movie: " << *movie;
}

