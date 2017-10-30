#include "Movie.h"
#include "typeinfo.h"


Movie::Movie(const char * name, double lengthInMinuttes,const char ** actorsList,int numberOfActors, int ageLimit, eGenre genre)
        : name(name), lengthInMinuttes(lengthInMinuttes), actorsList(actorsList),numberOfActors(numberOfActors), ageLimit(ageLimit), genre(genre)
{
}

Movie::~Movie()
{
    //TODO: implement destructor
}


inline const char* ToStringGenre(Movie::eGenre genre)
{
    switch (genre)
    {
        case Movie::ACTION:
            return "Action";
            break;
        case Movie::COMEDY:
            return "Comedy";
            break;
        case Movie::DRAMA:
            return "Drama";
            break;
        case Movie::HORROR:
            return "Horror";
            break;
        case Movie::THRILLER:
            return "Thriller";
            break;
    }
}

void Movie::toSrting(std::ostream &os) const
{
}

ostream & operator<<(ostream & os,const Movie& movie)
{
    os << "Movie Type:" << typeid(movie).name() << ", Movie name:\"" <<
       movie.getName() << "\", Movie Genere:" << ToStringGenre(movie.getGenre()) <<
       ",Movie Length: " << movie.getLengthInMinuttes() << "Movie Age Limit: " <<
       movie.getAgeLimit() << ",Movie Actors: " ;
    movie.toSrting(os);

    for (int i = 0; i < movie.getNumberOfActors(); i++)
    {
        os << movie.getActorsList()[i] << endl;
    }

    return os;
}

const char *Movie::getName() const {
    return name;
}

void Movie::setName(const char *name) {
    Movie::name = name;
}

double Movie::getLengthInMinuttes() const {
    return lengthInMinuttes;
}

void Movie::setLengthInMinuttes(double lengthInMinuttes) {
    Movie::lengthInMinuttes = lengthInMinuttes;
}

const char **Movie::getActorsList() const {
    return actorsList;
}

void Movie::setActorsList(const char **actorsList) {
    Movie::actorsList = actorsList;
}

int Movie::getAgeLimit() const {
    return ageLimit;
}

void Movie::setAgeLimit(int ageLimit) {
    Movie::ageLimit = ageLimit;
}

Movie::eGenre Movie::getGenre() const {
    return genre;
}

void Movie::setGenre(Movie::eGenre genre) {
    Movie::genre = genre;
}

int Movie::getNumberOfActors() const {
    return numberOfActors;
}

void Movie::setNumberOfActors(int numberOfActors) {
    Movie::numberOfActors = numberOfActors;
}






