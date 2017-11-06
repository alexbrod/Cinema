#include <cstring>
#include "Movie.h"
#include "typeinfo.h"


Movie::Movie(const char * name, int lengthInMinuttes, const char ** actorsList,
             int numberOfActors, int ageLimit, eGenre genre)
        : name(nullptr),lengthInMinuttes(lengthInMinuttes), actorsList(nullptr),
          numberOfActors(numberOfActors), ageLimit(ageLimit), genre(genre)
{
    setName(name);
    setActorsList(actorsList);
}

Movie::Movie(const Movie &other):
    Movie(other.getName(), other.getLengthInMinuttes(),
          other.getActorsList(),
    other.getNumberOfActors(), other.getAgeLimit(), other.getGenre())
{}

Movie::~Movie()
{
    delete []this->name;
    for (int i = 0; i < getNumberOfActors(); ++i)
    {
        delete []actorsList[i];
    }
    delete []actorsList;
}

ostream & operator<<(ostream & os,const Movie& movie)
{
    os << " Name:\"" << movie.getName() << "\", Movie Genere:"
       << Movie::toStringGenre(movie.getGenre()) << ",Movie Length: "
       << movie.getLengthInMinuttes() << " Movie Age Limit: " <<
       movie.getAgeLimit();
    if(movie.getNumberOfActors() > 0)
    {
        os  << ", Movie Actors: ";
        for (int i = 0; i < movie.getNumberOfActors(); i++)
        {
            os << movie.getActorsList()[i] << ", ";
        }
        os << "\b\b ";
    }
    movie.toOs(os);
    return os;
}

const char *Movie::getName() const
{
    return name;
}

void Movie::setName(const char *name)
{
    delete []this->name;
    this->name = new char[std::strlen(name)+1];
    strcpy(this->name, name);
}

int Movie::getLengthInMinuttes() const
{
    return lengthInMinuttes;
}

void Movie::setLengthInMinuttes(int lengthInMinuttes)
{
    Movie::lengthInMinuttes = lengthInMinuttes;
}

const char **Movie::getActorsList() const
{
    return const_cast<const char **>(this->actorsList);
}

void Movie::setActorsList(const char **actorsList)
{
    if(actorsList != nullptr)
    {
        if(this->actorsList != nullptr)
        {
            for (int i = 0; i < numberOfActors; ++i)
            {
                delete this->actorsList[i];
            }
            delete []this->actorsList;
        }
        this->actorsList = new char*[numberOfActors];
        for (int j = 0; j < numberOfActors; ++j)
        {
            if(actorsList[j] != nullptr)
            {
                this->actorsList[j] = new char[strlen(actorsList[j])+1];
                strcpy(this->actorsList[j],actorsList[j]);
            }
            else
            {
                throw "Actors list is not properly initialized";
            }

        }
    }
    else
    {
        throw "Actors list is not properly initialized";
    }

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

int Movie::getNumberOfActors() const
{
    return numberOfActors;
}

void Movie::setNumberOfActors(int numberOfActors)
{
    Movie::numberOfActors = numberOfActors;
}

const char *Movie::toStringGenre(Movie::eGenre genre)
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
    }
    return genreStr;
}













