#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Cinema.h"
using namespace std;

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

Cinema::~Cinema()
{
    delete []movieList;
    delete []lectureList;
    delete []occasionList;
    delete []hallsArray;
}

void Cinema::initHallsArray(int numOfHalls) throw(const char*)
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
        throw ("Can not add %d max number of halls is: %d\n", numOfHalls, MAX_HALLS);
    }
}

void Cinema::initLectureList(int numOfLectures, const char** hostNames, const char** lectureNames) throw(const char*)
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
        throw ("Can not add %d , max number of lectures is: %d\n", numOfLectures, MAX_LECTURES);
    }
}

void Cinema::initMovieList(int numOfMovies, const char** moviesNames, const char* actors[][Movie::MAX_ACTORS_IN_MOVIE]) throw(const char*)
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
        throw ("Can not add %d , max number of lectures is: %d\n", numOfMovies, MAX_MOVIES);
    }
}

void Cinema::initOccasionList(Occasion** occasionList)
{
    this->occasionList = occasionList;
}



void Cinema::addHall(Hall *hall) throw(const char*)
{
    if(hall != nullptr)
    {
        if(numOfActiveHalls < MAX_HALLS)
        {
            hallsArray[numOfActiveHalls++] = hall;
        }
        else
        {
            throw "Reached maximum halls can not add another one!\n";
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
        --numOfActiveHalls;
        return true;
    }
    return false;
}

void Cinema::addMovie(Movie* movie) throw(const char*)
{
    if(movie != nullptr)
    {
        if(currentMovies < MAX_MOVIES)
        {
            movieList[currentMovies++] = movie;
        }
        else
        {
            throw "Reached maximum movies can not add another one!\n";
        }
    }
}

bool Cinema::deleteMovie(const Movie& movie)
{
    int deletedIndex = currentMovies;
    for (int i = 0; i < currentMovies; ++i)
    {
        if(movieList[i] == &movie)
        {
            delete movieList[i];
            deletedIndex = i;
            break;
        }
    }
    if(deletedIndex < currentMovies)
    {
        for (int j = deletedIndex; j < currentMovies - 1; ++j)
        {
            movieList[j] = movieList[j+1];
        }
        --currentMovies;
        return true;
    }
    return false;
}

bool Cinema::addLecture(Lecture *lecture) throw(const char*)
{
    if(lecture != nullptr)
    {
        if(currentLectures < MAX_LECTURES)
        {
            lectureList[currentLectures++] = lecture;
        }
        else
        {
            throw "Reached maximum lectures can not add another one!\n";
        }
    }
}

bool Cinema::deleteLecture(const Lecture& lecture)
{
    int deletedIndex = currentLectures;
    for (int i = 0; i < currentLectures; ++i)
    {
        if(lectureList[i] == &lecture)
        {
            delete lectureList[i];
            deletedIndex = i;
            break;
        }
    }
    if(deletedIndex < currentLectures)
    {
        for (int j = deletedIndex; j < currentLectures - 1; ++j)
        {
            lectureList[j] = lectureList[j+1];
        }
        --currentLectures;
        return true;
    }
    return false;
}

void Cinema::addOccasion(Occasion *occasion) throw(const char*)
{
    if(occasion != nullptr)
    {
        if(currentOccasions < MAX_OCCASIONS)
        {
            occasionList[currentOccasions++] = occasion;
        }
        else
        {
            throw "Reached maximum occasions can not add another one!\n";
        }
    }
}

bool Cinema::deleteOccasion(Occasion &occasion)
{
    int deletedIndex = currentOccasions;
    for (int i = 0; i < currentOccasions; ++i)
    {
        if(occasionList[i] == &occasion)
        {
            delete occasionList[i];
            deletedIndex = i;
            break;
        }
    }
    if(deletedIndex < currentOccasions)
    {
        for (int j = deletedIndex; j < currentOccasions - 1; ++j)
        {
            occasionList[j] = occasionList[j+1];
        }
        --currentOccasions;
        return true;
    }
    return false;
}

const SeatTicket& Cinema::buyTicket(const Occasion& occasion)
{
    if(&occasion != nullptr)
    {
        for (int i = 0; i < currentOccasions; ++i)
        {
            if(occasionList[i] == &occasion )
            {
                return occasionList[i]->orderTicket();
            }
        }
    }
    //TODO: check what happens if there is no occasion or no seats
}

bool Cinema::cancelTicket(Occasion& occasion, SeatTicket &seatTicket) throw(const char*)
{
    if(&occasion != nullptr)
    {
        for (int i = 0; i < currentOccasions; ++i)
        {
            if(occasionList[i] == &occasion)
            {
                occasion.cancelTicket(seatTicket);
                return true;
            }
        }
        return false;
    }
    else
    {
        throw "Didn\'t provide an occasion to cancel from\n";
    }
}

void Cinema::showLectures() const
{
    for (int i = 0; i < currentLectures; ++i)
    {
        cout << lectureList[i] << endl;
    }
}

void Cinema::showMovies() const
{
    for (int i = 0; i < currentMovies; ++i)
    {
        cout << movieList[i] << endl;
    }
}

void Cinema::showOccasions() const
{
    for (int i = 0; i < currentOccasions; ++i)
    {
        cout << occasionList[i] << endl;
    }
}

const Occasion& Cinema::getOccasionByIndex(int index)
{

    if(index-1 >= 0 && index-1 < currentOccasions)
    {
        return *occasionList[index-1];
    }
    //TODO: what happens if no occasion
}

const Movie& Cinema::getMovieByIndex(int index)
{
    if(index-1 >= 0 && index-1 < currentMovies)
    {
        return *movieList[index-1];
    }
    //TODO: what happens if no movie
}

const Lecture& Cinema::getLectureByIndex(int index)
{
    if(index-1 >= 0 && index-1 < currentLectures)
    {
        return *lectureList[index-1];
    }
    //TODO: what happens if no lecture
}