#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Movie.h"
#include "Lecture.h"
#include "Cinema.h"
#include "ThreeDHall.h"
#include "VipHall.h"

using namespace std;

Cinema::Cinema(int maxHalls, int maxLectures, int maxMovies, int maxOccasions):
        MAX_HALLS(maxHalls), MAX_LECTURES(maxLectures), MAX_MOVIES(maxMovies), MAX_OCCASIONS(maxOccasions)
{
    std::srand(static_cast<unsigned int>(time(nullptr)));
    hallsArray = new Hall*[MAX_HALLS];
    lectureList = new Lecture*[MAX_LECTURES];
    movieList = new Movie*[MAX_MOVIES];
    occasionList = new Occasion*[MAX_OCCASIONS];
    currentHalls = 0;
    currentLectures = 0;
    currentMovies = 0;
    currentOccasions = 0;
}

Cinema::~Cinema()
{
    for (int i = 0; i < currentLectures; ++i)
    {
        delete lectureList[i];
    }
    for (int i = 0; i < currentMovies; ++i)
    {
        delete movieList[i];
    }
    for (int i = 0; i < currentHalls; ++i)
    {
        delete hallsArray[i];
    }
    for (int i = 0; i < currentOccasions; ++i)
    {
        delete occasionList[i];
    }
    delete []movieList;
    delete []lectureList;
    delete []occasionList;
    delete []hallsArray;
}

void Cinema::initHallsArray(int numOfHalls)
{
    if(numOfHalls <= MAX_HALLS)
    {
        int chooseType;
        for (int i = 0; i < numOfHalls; ++i)
        {
            ++currentHalls;
            chooseType = rand()%3;
            switch (chooseType)
            {
                case 0:
                    hallsArray[i] = new Hall(i+1,rand()%100,rand()%30 + 3,rand()%30 + 3);
                    break;
                case 1:
                    hallsArray[i] = new ThreeDHall(i+1,rand()%100,rand()%30 + 3,rand()%30 + 3);
                    break;
                case 2:
                    hallsArray[i] = new VipHall(i+1,rand()%100,rand()%30 + 3,rand()%30 + 3);
                    break;
                default:break;
            }
        }
    }
    else
    {
        throw ("Can not add %d max number of halls is: %d\n", numOfHalls, MAX_HALLS);
    }
}

void Cinema::initLectureList(int numOfLectures, const char** hostNames, const char** lectureNames)
{
    if(numOfLectures <= MAX_LECTURES)
    {
        for (int i = 0; i < numOfLectures; ++i)
        {
            ++currentLectures;
            lectureList[i] = new Lecture(lectureNames[i], hostNames[i],
                                         Date(2017, rand()%12 + 1, rand()%31 + 1), 20, 21);
        }
    }
    else
    {
        throw ("Can not add %d , max number of lectures is: %d\n", numOfLectures, MAX_LECTURES);
    }
}

void Cinema::initMovieList(int numOfMovies, const char** moviesNames,
                           const char* actors[][Movie::MAX_ACTORS_IN_MOVIE],
                           const int NUM_OF_ACTORS[])
{
    if(numOfMovies <= MAX_MOVIES)
    {
        for (int i = 0; i < numOfMovies; ++i)
        {
            ++currentMovies;
            movieList[i] = new Movie(
                    moviesNames[i],
                    rand()% 100 + 60,
                    actors[i],
                    NUM_OF_ACTORS[i],
                    14,
                    static_cast<Movie::eGenre>(rand() % 5));
        }
    }
    else
    {
        throw ("Can not add %d , max number of lectures is: %d\n", numOfMovies, MAX_MOVIES);
    }
}


void Cinema::addMovie(Movie* movie)
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

void Cinema::deleteMovie(int index)
{
    int i = index - 1;
    if(i>=0 && i < currentMovies)
    {
        delete movieList[i];
        for (int j = i; j < currentMovies; ++j)
        {
            movieList[j] = movieList[j+1];
        }
    }
    else
    {
        throw "No such movie";
    }
    --currentMovies;
}

void Cinema::addLecture(Lecture* lecture)
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

void Cinema::deleteLecture(int index)
{
    int i = index - 1;
    if(i>=0 && i < currentLectures)
    {
        delete lectureList[i];
        for (int j = i; j < currentLectures; ++j)
        {
            lectureList[j] = lectureList[j+1];
        }
    }
    else
    {
        throw "No such lecture";
    }
    --currentLectures;
}

void Cinema::addOccasion(Occasion *occasion)
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
    else
    {
        throw "Trying to add occasion without specifying one";
    }
}

bool Cinema::deleteOccasion(const Occasion& occasion)
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
    else
    {
        throw "Trying to buy ticket without specifying an occasion";
    }
}

void Cinema::showLectures() const
{
    for (int i = 0; i < currentLectures; ++i)
    {
        cout << i+1 << ". " << *lectureList[i] << endl;
    }
}

void Cinema::showMovies() const
{
    for (int i = 0; i < currentMovies; ++i)
    {
        cout << i+1 << ". " << *movieList[i] << endl;
    }
}

bool Cinema::showOccasionsAssigendToHalls() const
{
    bool noOccasions = true;
    for (int i = 0; i < currentOccasions; ++i)
    {
        if(occasionList[i]->getHall() != nullptr)
        {
            cout << i+1 << ". " << *occasionList[i] << endl;
            noOccasions = false;
        }
    }
    if(noOccasions)
    {
        cout << "No occasions - maybe you forgot to assign occasion to a hall?" << endl;
        return false;
    }
    return true;
}

bool Cinema::showOccasionsWithoutHalls() const
{
    bool noOccasions = true;
    for (int i = 0; i < currentOccasions; ++i)
    {
        if(occasionList[i]->getHall() == nullptr)
        {
            cout << i+1 << ". " << *occasionList[i] << endl;
            noOccasions = false;
        }
    }
    if(noOccasions)
    {
        cout << "No occasions" << endl;
        return false;
    }
    return true;
}

void Cinema::showAllOccasions() const
{
    for (int i = 0; i < currentOccasions; ++i)
    {
        cout << i+1 << ". " << *occasionList[i] << endl;
    }
    if(currentOccasions == 0)
    {
        throw "No occasion";
    }
}

bool Cinema::showEmptyHalls() const
{
    bool noEmtyHalls = true;
    for (int i = 0; i < currentHalls; ++i) {
        if(hallsArray[i]->getOccation() == nullptr)
        {
            cout << i+1 << ". " << *hallsArray[i] << endl;
            noEmtyHalls = false;
        }
    }
    if(noEmtyHalls)
    {
        cout << "No empty halls\n";
        return false;
    }
    return true;
}

bool Cinema::showScreenings()
{
    Screening* screening;
    bool noScreenings = true;
    for (int i = 0; i < currentOccasions; ++i)
    {
        screening = dynamic_cast<Screening *>(getOccasionByIndex(i+1));
        if(screening != nullptr)
        {
            cout << i+1 << ". " << *occasionList[i] << endl;
            noScreenings = false;
        }

    }
    if(noScreenings)
    {
        cout << "No screenings\n";
        return false;
    }
    return true;
}

Occasion* Cinema::getOccasionByIndex(int index)
{

    if(index-1 >= 0 && index-1 < currentOccasions)
    {
        return occasionList[index-1];
    }
    else
    {
        throw "No such occasion";
    }
}

Movie * Cinema::getMovieByIndex(int index)
{
    if(index-1 >= 0 && index-1 < currentMovies)
    {
        return movieList[index-1];
    }
    else
    {
        throw "No such movie";
    }
}

Lecture* Cinema::getLectureByIndex(int index)
{
    if(index-1 >= 0 && index-1 < currentLectures)
    {
        return lectureList[index-1];
    }
    else
    {
        throw "No such lecture";
    }
}

Screening *Cinema::getScreeningByIndex(int index)
{
    Screening* screening;
    if(index-1 >= 0 && index-1 < currentOccasions)
    {
        try
        {
            screening = dynamic_cast<Screening *>(getOccasionByIndex(index));
            if(screening == nullptr)
                throw "Probably didn't choose screening occasion";
            else
                return screening;
        }
        catch (const char* e)
        {
            throw "Not a Screening occasion was chosen";
        }
    }
    else
    {
        throw "No such screening";
    }
}

Hall* Cinema::getHallByIndex(int index)
{
    if(index-1 >= 0 && index-1 < currentHalls)
    {
        return hallsArray[index-1];
    }
    else
    {
        throw "No such hall";
    }
}

const bool Cinema::operator+=(Movie* other)
{
    addMovie(other);
}

const bool Cinema::operator-=(Movie *other)
{
    for (int i = 0; i < currentMovies; ++i)
    {
        if(movieList[i] == other)
        {
            deleteMovie(i+1);
        }
    }
}

const Movie* Cinema::operator[](int index)
{
    return getMovieByIndex(index);
}






