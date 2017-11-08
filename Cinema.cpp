#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Movie.h"
#include "Lecture.h"
#include "Cinema.h"
#include "ThreeDHall.h"
#include "VipHall.h"

using namespace std;

Cinema::Cinema(int maxHalls): MAX_HALLS(maxHalls)
{
    std::srand(static_cast<unsigned int>(time(nullptr)));
    hallsList = MyLinkedList<Hall*>();
}

void Cinema::initHallsArray(int numOfHalls)
{
    if(numOfHalls <= MAX_HALLS)
    {
        int chooseType;
        for (int i = 0; i < numOfHalls; ++i)
        {
            chooseType = rand()%3;
            switch (chooseType)
            {
                case 0:
                    hallsList.pushBack(new Hall(i+1,rand()%100,rand()%30 + 3,rand()%30 + 3));
                    break;
                case 1:
                    hallsList.pushBack(new ThreeDHall(i+1,rand()%100,rand()%30 + 3,rand()%30 + 3));
                    break;
                case 2:
                    hallsList.pushBack(new VipHall(i+1,rand()%100,rand()%30 + 3,rand()%30 + 3));
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

void Cinema::initLectureList(const vector<string>& hostNames, const vector<string>& lectureNames)
{
    vector<string>::const_iterator namesItr = lectureNames.begin();
    vector<string>::const_iterator hostItr = hostNames.begin();
    for (; namesItr != lectureNames.end(), hostItr != hostNames.end(); ++namesItr, ++hostItr)
    {
        lectureList.push_back(new Lecture(*namesItr, *hostItr,
                                          Date(2017, rand()%12 + 1, rand()%31 + 1), 20, 21));
    }
}

void Cinema::initMovieList(const vector<string>& moviesNames, const vector<vector<string>>& actors)
{
    vector<string>::const_iterator namesItr = moviesNames.begin();
    vector<vector<string>>::const_iterator actorsItr = actors.begin();
    for (; namesItr != moviesNames.end(), actorsItr != actors.end(); ++namesItr, ++actorsItr)
    {
        movieList.push_back(new Movie(*namesItr, rand()% 100 + 60, *actorsItr,14,
                                        static_cast<Movie::eGenre>(rand() % 5)));
    }
}


void Cinema::addMovie(Movie* movie)
{
    movieList.push_back(movie);
}

void Cinema::deleteMovie(int index)
{
    int i = index - 1;
    if(i>=0 && i < movieList.size())
    {
        movieList.erase(std::remove(movieList.begin(), movieList.end(), getMovieByIndex(index)),
                        movieList.end());
    }
    else
    {
        throw "No such movie";
    }
}

void Cinema::addLecture(Lecture* lecture)
{
    lectureList.push_back(lecture);
}

void Cinema::deleteLecture(int index)
{
    int i = index - 1;
    if(i>=0 && i < lectureList.size())
    {
        lectureList.erase(lectureList.begin()+i);
    }
    else
    {
        throw "No such lecture";
    }
}

void Cinema::addOccasion(Occasion *occasion)
{
    occasionList.push_back(occasion);
}

void Cinema::deleteOccasion(const Occasion& occasion)
{
    occasionList.erase(std::remove(occasionList.begin(), occasionList.end(), &occasion),
                       occasionList.end());
}

const SeatTicket& Cinema::buyTicket(const Occasion& occasion)
{
    vector<Occasion*>::const_iterator itr = occasionList.begin();
    for (; itr != occasionList.end(); ++itr)
    {
        if(*itr == &occasion )
        {
            return (*itr)->orderTicket();
        }
    }
}

void Cinema::showLectures() const
{
    vector<Lecture*>::const_iterator itr = lectureList.begin();
    for (int i=0; itr != lectureList.end(); ++itr, ++i)
    {
        cout << i+1 << ". " << **itr << endl;
    }
}

void Cinema::showMovies() const
{
    vector<Movie*>::const_iterator itr = movieList.begin();
    for (int i=0; itr != movieList.end(); ++itr, ++i)
    {
        cout << i+1 << ". " << **itr << endl;
    }
}

bool Cinema::showOccasionsAssigendToHalls() const
{
    bool noOccasions = true;
    vector<Occasion*>::const_iterator itr = occasionList.begin();
    for (int i=0; itr != occasionList.end(); ++itr, ++i)
    {
        if((*itr)->getHall() != nullptr)
        {
            cout << i+1 << ". " << **itr << endl;
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
    vector<Occasion*>::const_iterator itr = occasionList.begin();
    for (int i=0; itr != occasionList.end(); ++itr, ++i)
    {
        if((*itr)->getHall() == nullptr)
        {
            cout << i+1 << ". " << **itr << endl;
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
    if(occasionList.empty())
    {
        cout << "No occasions" << endl;
    }
    else
    {
        vector<Occasion *>::const_iterator itr = occasionList.begin();
        for (int i = 0; itr != occasionList.end(); ++itr, ++i)
        {
            cout << i + 1 << ". " << **itr << endl;
        }
    }
}

bool Cinema::showEmptyHalls() const
{
    bool noEmptyHalls = true;
    for (int i = 0; i < hallsList.getSize(); ++i) {
        if(hallsList.getAt(i)->getOccation() == nullptr)
        {
            cout << i+1 << ". " << *hallsList.getAt(i) << endl;
            noEmptyHalls = false;
        }
    }
    if(noEmptyHalls)
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
    vector<Occasion *>::const_iterator itr = occasionList.begin();
    for (int i = 0; itr != occasionList.end(); ++itr, ++i)
    {
        screening = dynamic_cast<Screening *>(getOccasionByIndex(i+1));
        if(screening != nullptr)
        {
            cout << i+1 << ". " << **itr << endl;
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
    if(index-1 >= 0 && index-1 < occasionList.size())
    {
        return occasionList.at(index-1);
    }
    else
    {
        throw "No such occasion";
    }
}

Movie * Cinema::getMovieByIndex(int index)
{
    if(index-1 >= 0 && index-1 < movieList.size())
    {
        return movieList.at(index-1);
    }
    else
    {
        throw "No such movie";
    }
}

Lecture* Cinema::getLectureByIndex(int index)
{
    if(index-1 >= 0 && index-1 < lectureList.size())
    {
        return lectureList.at(index-1);
    }
    else
    {
        throw "No such lecture";
    }
}

Screening *Cinema::getScreeningByIndex(int index)
{
    Screening* screening;
    if(index-1 >= 0 && index-1 < occasionList.size())
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
    if(index-1 >= 0 && index-1 < hallsList.getSize())
    {
        return hallsList.getAt(index-1);
    }
    else
    {
        throw "No such hall";
    }
}






