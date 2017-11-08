#include <cstring>
#include <vector>
#include "Movie.h"
using namespace std;

Movie::Movie(const string& name, int lengthInMinuttes, const vector<string>& actorsList,
             int ageLimit, eGenre genre)
        : name(name),lengthInMinutes(lengthInMinuttes), ageLimit(ageLimit), genre(genre)
{
    setActorsList(actorsList);
}

ostream & operator<<(ostream & os,const Movie& movie)
{
    os << " Name:\"" << movie.getName() << "\", Movie Genere:"
       << Movie::toStringGenre(movie.getGenre()) << ",Movie Length: "
       << movie.getLengthInMinutes() << " Movie Age Limit: " <<
       movie.getAgeLimit();
    if(!movie.actorsList.empty())
    {
        os  << ", Movie Actors: ";
        vector<string>::const_iterator itr;
        for (itr = movie.actorsList.begin(); itr != movie.actorsList.end(); ++itr)
        {
            os << *itr << ", ";
        }
        os << "\b\b ";
    }
    movie.toOs(os);
    return os;
}

const string& Movie::getName() const
{
    return name;
}

void Movie::setName(const string& name)
{
    this->name = name;
}

int Movie::getLengthInMinutes() const
{
    return lengthInMinutes;
}

void Movie::setLengthInMinuttes(int lengthInMinutes)
{
    Movie::lengthInMinutes = lengthInMinutes;
}

const vector<string>& Movie::getActorsList() const
{
    return this->actorsList;
}

void Movie::setActorsList(const vector<string>& actors)
{
    actorsList.clear();
    this->actorsList = actors;
}

int Movie::getAgeLimit() const
{
    return ageLimit;
}

void Movie::setAgeLimit(int ageLimit)
{
    Movie::ageLimit = ageLimit;
}

Movie::eGenre Movie::getGenre() const
{
    return genre;
}

void Movie::setGenre(Movie::eGenre genre)
{
    Movie::genre = genre;
}

const string Movie::toStringGenre(Movie::eGenre genre)
{
    const char* genreStr;
    switch (genre)
    {
        case Movie::ACTION:
            genreStr = "Action";
            break;
        case Movie::COMEDY:
            genreStr = "Comedy";
            break;
        case Movie::DRAMA:
            genreStr = "Drama";
            break;
        case Movie::HORROR:
            genreStr = "Horror";
            break;
        case Movie::THRILLER:
            genreStr = "Thriller";
            break;
        default:
            genreStr = "Action";
            break;
    }
    return std::string(genreStr);
}


const bool Movie::operator<(const Movie &other)
{
    return this->lengthInMinutes < other.lengthInMinutes;
}

const bool Movie::operator>(const Movie &other)
{
    return this->lengthInMinutes > other.lengthInMinutes;
}













