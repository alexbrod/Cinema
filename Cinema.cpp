#include <ctime>
#include <cstdlib>
#include "Cinema.h"

Cinema::Cinema(int maxHalls, int maxLectures, int maxMovies, int maxOccasions):
        MAX_HALLS(maxHalls), MAX_LECTURES(maxLectures), MAX_MOVIES(maxMovies), MAX_OCCASIONS(maxOccasions)
{
    std::srand(static_cast<unsigned int>(time(nullptr)));
    hallsArray = new Hall*[MAX_HALLS];
    lectureList = new Lecture*[MAX_LECTURES];
    movieList = new Movie*[MAX_MOVIES];
    occasionList = new Occasion*[MAX_OCCASIONS];
    numOfActiveHalls = 0;
}


void Cinema::initHallsArray(int numOfHalls)
{
    if(numOfHalls <= MAX_HALLS)
    {
        for (int i = 0; i < numOfHalls; ++i)
        {
            ++numOfActiveHalls;
            hallsArray[i] = new Hall(i,rand()%100,rand()%30 + 3,rand()%30 + 3);
        }
    }
    else
    {
        throw 'Can not add ' << numOfHalls << ', max number of halls is: ' << MAX_HALLS << '\n';
    }
}

void Cinema::initLectureList(int numOfLectures, const char** hostNames, const char** lectureNames)
{
    if(numOfLectures <= MAX_LECTURES)
    {
        for (int i = 0; i < numOfLectures; ++i)
        {
            ++currentLectures;
            lectureList[i] = new Lecture(
                    Date(2018,rand()%12 + 1, rand()%31 + 1),
                    20, 21, nullptr, lectureNames[i],
                    hostNames[i], 60);
        }
    }
    else
    {
        throw 'Can not add ' << numOfLectures << ', max number of lectures is: ' << MAX_LECTURES << '\n';
    }
}

void Cinema::initMovieList(int numOfMovies, const char** moviesNames, const char*** actors)
{
    if(numOfMovies <= MAX_LECTURES)
    {
        for (int i = 0; i < numOfMovies; ++i)
        {
            ++currentMovies;
            movieList[i] = new Movie(
                    moviesNames[i],
                    rand()% 100 + 60,
                    actors[i],
                    14,
                    static_cast<Movie::eGenre>(rand() % 5));
        }
    }
    else
    {
        throw 'Can not add ' << numOfMovies << ', max number of movies is: ' << MAX_MOVIES << '\n';
    }
}

void Cinema::initOccasionList(Occasion** occasionList)
{
    this->occasionList = occasionList;
}



bool Cinema::addHall(Hall *hall) throw(const char*)
{
    if(hall != nullptr)
    {
        if(numOfActiveHalls < MAX_HALLS)
        {
            hallsArray[numOfActiveHalls++] = hall;
        }
        else
        {
            throw 'Reached maximum halls can not add another one!\n';
        }
    }
}

bool Cinema::deleteHall(const Hall& hall)
{
    int deletedIndex = numOfActiveHalls;
    for (int i = 0; i < numOfActiveHalls; ++i)
    {
        if(hallsArray[i] == &hall)
        {
            delete hallsArray[i];
            deletedIndex = i;
            break;
        }
    }
    if(deletedIndex < numOfActiveHalls)
    {
        for (int j = deletedIndex; j < numOfActiveHalls - 1; ++j)
        {
            hallsArray[j] = hallsArray[j+1];
        }
        return true;
    }
    return false;
}

